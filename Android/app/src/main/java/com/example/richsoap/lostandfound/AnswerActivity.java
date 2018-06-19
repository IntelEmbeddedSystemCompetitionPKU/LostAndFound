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

import com.example.richsoap.lostandfound.Adapters.BlanksAdapter;
import com.example.richsoap.lostandfound.NormalObject.Blanks;

import org.json.JSONObject;

import java.util.List;

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

        adapter = new BlanksAdapter(this);
        recyclerView = (RecyclerView) findViewById(R.id.answer_recyclerview);
        recyclerView.setAdapter(adapter);
        LinearLayoutManager layoutManager = new LinearLayoutManager(this);
        recyclerView.setLayoutManager(layoutManager);
        recyclerView.setItemAnimator(new DefaultItemAnimator());
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


    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.toolbar_ok, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        //Log.d(TAG, "onOptionsItemSelected: " + Integer.toString(item.getItemId()) + "----" + R.id.home);
        switch (item.getItemId()) {
            case android.R.id.home:
                finish();
                break;
            case R.id.toolbar_ok:
                JSONObject jsonObject = adapter.getStrings();
                Intent intent = new Intent(this, AnswerResultActivity.class);
                intent.putExtra("answer", jsonObject.toString());
                intent.putExtra("uuid", uuid);
                startActivity(intent);
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
            for(int i = 0;i < blanksList.size();i ++) {
                Bitmap result = NetworkManager.getImage(uuid, "LD", i, context);
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
            addBlankToList(details[0]);
        }
    }


}
