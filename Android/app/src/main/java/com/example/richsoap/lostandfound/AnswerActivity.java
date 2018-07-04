package com.example.richsoap.lostandfound;

import android.content.Context;
import android.content.Intent;
import android.graphics.Bitmap;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.v7.app.ActionBar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.DefaultItemAnimator;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.support.v7.widget.Toolbar;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.ProgressBar;
import android.widget.Toast;

import com.example.richsoap.lostandfound.Adapters.BlanksAdapter;
import com.example.richsoap.lostandfound.NormalObject.Blanks;
import com.example.richsoap.lostandfound.Table.OtherUserStore;

import org.json.JSONObject;

import java.util.List;
import java.util.UUID;

/**
 * This Activity is designed for user to answer questions about the object
 * Step1, get resource id list for this uuid
 * Step2, get blank photo and set it to BlanksAdapter
 */

public class AnswerActivity extends AppCompatActivity {
    private String uuid;
    private List<Blanks> blanksList;
    private BlanksAdapter adapter;
    private RecyclerView recyclerView;
    private BlanksListTask blanksListTask;
    private boolean loadfinish;
    private ProgressBar progressBar;
    private String description;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_answer);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
        ActionBar actionBar = getSupportActionBar();
        if(actionBar != null) {
            actionBar.setDisplayHomeAsUpEnabled(true);
            actionBar.setDisplayShowTitleEnabled(true);
        }

        Intent intent = getIntent();
        uuid = intent.getStringExtra("UUID");
        description = intent.getStringExtra("Description");
        adapter = new BlanksAdapter(this);
        recyclerView = (RecyclerView) findViewById(R.id.answer_recyclerview);
        recyclerView.setAdapter(adapter);
        LinearLayoutManager layoutManager = new LinearLayoutManager(this);
        recyclerView.setLayoutManager(layoutManager);
        recyclerView.setItemAnimator(new DefaultItemAnimator());
        progressBar = (ProgressBar) findViewById(R.id.answer_progress);
        progressBar.setVisibility(View.GONE);
        loadfinish = false;
        getBlanksList();
    }
    @Override
    protected void onStop() {
        super.onStop();
        blanksListTask.cancel(true);
    }

    private void getBlanksList() {
        blanksListTask = new BlanksListTask(this);
        blanksListTask.execute(uuid);
    }

    private void addBlankToList(Blanks blanks) {
        adapter.addData(blanks);
    }

    private void startCommunicate() {
        Intent intent = new Intent(this, ChatActivity.class);
        intent.putExtra("uuid", uuid);
        intent.putExtra("kind", 0);
        intent.putExtra("description", description);
        startActivity(intent);
        finish();
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.toolbar_answer, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()) {
            case android.R.id.home:
                finish();
                break;
            case R.id.toolbar_ok:
                if(loadfinish) {
                    JSONObject jsonObject = adapter.getStrings();
                    startValid(uuid, jsonObject);
                    progressBar.setVisibility(View.VISIBLE);
                }
                break;
            case R.id.toolbar_communicate:
                startCommunicate();
                finish();
                break;
        }
        return true;
    }

    private class BlanksListTask extends AsyncTask<String, Blanks, Void> {
        private Context context;

        public BlanksListTask(Context context) {
            this.context = context;
        }

        @Override
        protected Void doInBackground(String... keys) {
            blanksList = NetworkManager.getBlanksList(keys[0], context);
            if(blanksList == null) {
                cancel(true);
                return null;
            }
            for(int i = 0;i < blanksList.size();i ++) {
                Bitmap result = NetworkManager.getImage(uuid, "mask", i, context); // get image for each mask
                if(result != null) {
                    blanksList.get(i).setImage(result);
                    publishProgress(blanksList.get(i));
                }
                if(isCancelled()) {
                    return null;
                }
            }
            return null;
        }

        @Override
        protected void onProgressUpdate(Blanks... details) {
            if(details[0].getImage() == null) {
                Toast.makeText(context,"Network error, please try again later", Toast.LENGTH_SHORT).show();
                cancel(false);
                addBlankToList(details[0]);
            }
        }

        @Override
        protected void onPostExecute(Void aVoid) {
            loadfinish = true;
        }
    }


    public void startValid(String uuid, JSONObject jsonObject) {
        ValidTask task = new ValidTask(this, uuid, jsonObject);
        task.execute();
    }
    public void showQRCode() {
        Intent intent = new Intent(this, ObjectQRActivity.class);
        intent.putExtra("UUID", uuid);
        startActivity(intent);
        finish();
    }

    public void showOptions() {
        progressBar.setVisibility(View.GONE);
        Toast.makeText(this, "Wrong Answer", Toast.LENGTH_SHORT).show();
    }


    private class ValidTask extends AsyncTask<Void, Void, Boolean> {
        private Context context;
        private String uuid;
        private JSONObject jsonObject;
        public ValidTask(Context context, String uuid, JSONObject jsonObject) {
            this.context = context;
            this.uuid = uuid;
            this.jsonObject = jsonObject;
        }

        @Override
        protected Boolean doInBackground(Void... keys) {
            return NetworkManager.tryToValid(uuid, jsonObject, context);
        }


        @Override
        protected void onPostExecute(final Boolean success) {
            if(success) {
                showQRCode();
            }
            else {
                showOptions();
            }
        }
    }

}
