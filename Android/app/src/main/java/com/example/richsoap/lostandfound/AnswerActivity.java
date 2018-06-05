package com.example.richsoap.lostandfound;

import android.content.Intent;
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
import android.widget.Toast;

import java.util.List;

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
        blanksListTask = new BlanksListTask();
        blanksListTask.execute(uuid);
    }

    private void addBlankToList(Blanks blanks) {
        adapter.addData(blanks);
        for(int i = 0;i < blanks.getNumber();i ++) {
            adapter.addEditor();
        }
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
                List<String> list = adapter.getStrings();
                Toast.makeText(this, list.get(0), Toast.LENGTH_SHORT).show();
                break;
        }
        return true;
    }

    private class BlanksListTask extends AsyncTask<String, Blanks, Void> {

        public BlanksListTask() {
        }

        @Override
        protected Void doInBackground(String... keys) {
            blanksList = NetworkManager.getBlanksList(keys[0]);
            for(int i = 0;i < blanksList.size();i ++) {
                String result = NetworkManager.getImage(blanksList.get(i).getImageUUID());
                blanksList.get(i).setImage(result);
                blanksList.get(i).setType(Blanks.useforwhat.IMAGE);
                publishProgress(blanksList.get(i));
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
