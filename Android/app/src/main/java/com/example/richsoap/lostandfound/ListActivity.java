package com.example.richsoap.lostandfound;

import android.content.Context;
import android.content.Intent;
import android.graphics.Canvas;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.ActionBar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.DefaultItemAnimator;
import android.support.v7.widget.DividerItemDecoration;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.MenuItem;
import android.view.View;

import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.CopyOnWriteArrayList;

import static android.os.Build.VERSION_CODES.O;

public class ListActivity extends AppCompatActivity {

    private String date;
    private String keywords;
    private View mProcess;
    private UUIDListTask uuidListTask;
    private JsonListTask jsonListTask;
    private RecyclerView recyclerView;
    private List<String> uuidList;
    private ObjectAdapter objectAdapter;
    private static final String TAG = "ListActivity";
    private int stopIndex;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_list);
        Toolbar toolbar = (Toolbar) findViewById(R.id.list_toolbar);
        setSupportActionBar(toolbar);
        ActionBar actionBar = getSupportActionBar();
        if(actionBar != null) {
            actionBar.setDisplayHomeAsUpEnabled(true);
            actionBar.setDisplayShowTitleEnabled(true);
        }
        Intent intent = getIntent();
        date = intent.getStringExtra("date");
        keywords = intent.getStringExtra("keywords");
        mProcess = (View) findViewById(R.id.list_progress);
        recyclerView = (RecyclerView) findViewById(R.id.list_recycleview);
        objectAdapter = new ObjectAdapter(this);
        recyclerView.setAdapter(objectAdapter);
        LinearLayoutManager layoutManager = new LinearLayoutManager(this);
        recyclerView.setLayoutManager(layoutManager);
        recyclerView.setItemAnimator(new DefaultItemAnimator());
        recyclerView.addOnScrollListener(new RecyclerView.OnScrollListener() {
            @Override
            public void onScrollStateChanged(RecyclerView recyclerView, int newState) {
                super.onScrollStateChanged(recyclerView, newState);
                LinearLayoutManager manager = (LinearLayoutManager) recyclerView.getLayoutManager();
                int totalItemCount = recyclerView.getAdapter().getItemCount();
                int lastVisialOne = manager.findLastVisibleItemPosition();
                int visialCount = recyclerView.getChildCount();

                if(newState == RecyclerView.SCROLL_STATE_IDLE && lastVisialOne == totalItemCount - 1 && visialCount > 0) {
                    Log.d(TAG, "onScrollStateChanged: try to get more" );
                    tryToGetUUIDDetail();
                }
            }
        });
        stopIndex = 0;
        tryToGetUUIDList();
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        Log.d(TAG, "onOptionsItemSelected: " + Integer.toString(item.getItemId()) + "----" + R.id.home);
        switch (item.getItemId()) {
            case android.R.id.home:
                finish();
                break;
        }
        return true;
    }

    @Override
    protected void onStop() {
        super.onStop();
        jsonListTask.cancel(true);
    }

    private void addObjectToList(String data, String uuid) {
        objectAdapter.addData(new ListDataPiece(uuid, data));
    }

    private void tryToGetUUIDList() {
        uuidListTask = new UUIDListTask(date, keywords, mProcess, this);
        uuidListTask.execute();
    }

    public void cancleTask() {
        jsonListTask.cancel(true);
    }

    private void tryToGetUUIDDetail() {
        jsonListTask = new JsonListTask(this);
        if(uuidList.size() - stopIndex > 10) {
            jsonListTask.execute(uuidList.subList(stopIndex,10 + stopIndex));
            stopIndex += 10;
        }
        else {
            jsonListTask.execute(uuidList.subList(stopIndex, uuidList.size()));
            stopIndex = uuidList.size();
        }
    }

    private class UUIDListTask extends AsyncTask<Void, Void, List<String>> {
        private String date;
        private String keywords;
        private View mProcess;
        private Context context;
        public UUIDListTask(String date, String keywords, View mProcess, Context context) {
            this.date = date;
            this.keywords = keywords;
            this.mProcess = mProcess;
            this.context = context;
        }

        @Override
        protected void onPreExecute() {
            mProcess.setVisibility(View.VISIBLE);
        }

        @Override
        protected List<String> doInBackground(Void... keys) {
            return NetworkManager.getUUIDList(date, keywords, context);
        }

        @Override
        protected void onPostExecute(final List<String> lists) {
            mProcess.setVisibility(View.GONE);
            uuidList = lists;
            tryToGetUUIDDetail();
        }

        @Override
        protected void onCancelled() {
            mProcess.setVisibility(View.GONE);
        }

    }

    private class JsonListTask extends AsyncTask<List<String>, String, Void> {
        private Context context;
        public JsonListTask(Context context) {
            this.context = context;
        }

        @Override
        protected Void doInBackground(List<String>... keys) {
            Log.d(TAG, "doInBackground: " + Integer.toString(keys[0].size()));
            for(int i = 0;i < keys[0].size();i ++) {
                String result = NetworkManager.getUUIDDetail(keys[0].get(i), context);
                publishProgress(result, keys[0].get(i));
                if(isCancelled()) {
                    return null;
                }
            }
            return null;
        }

        @Override
        protected void onProgressUpdate(String... details) {
            Log.d(TAG, "onProgressUpdate: " + details[0]);
            addObjectToList(details[0], details[1]);
        }

        @Override
        protected void onCancelled() {
            super.onCancelled();
            Log.d(TAG, "onCancelled: ");
        }
        

    }

}