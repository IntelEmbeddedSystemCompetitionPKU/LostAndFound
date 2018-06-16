package com.example.richsoap.lostandfound;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.v7.app.ActionBar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.DefaultItemAnimator;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.widget.Toast;

import org.json.JSONException;
import org.json.JSONObject;

import java.util.List;

/**
 * This Activity is designed for showing whether user passed the test
 * Step1, post the json string from AnswerActivity to server, and get if pass or not
 * Step2, refresh text and image
 */


// TODO: Try to get QRCode for the uuid
public class AnswerResultActivity extends AppCompatActivity {
    private JSONObject jsonObject;
    private TextView textView;
    private String uuid;
    private ProgressBar progressBar;
    private static final String TAG = "AnswerResultActivity";
    
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_answer_result);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
        ActionBar actionBar = getSupportActionBar();
        if(actionBar != null) {
            actionBar.setDisplayHomeAsUpEnabled(true);
            actionBar.setDisplayShowTitleEnabled(true);
        }
        progressBar = (ProgressBar) findViewById(R.id.answer_result_progress);
        progressBar.setVisibility(View.VISIBLE);

        Intent intent = getIntent();
        uuid = intent.getStringExtra("UUID");
        try {
            jsonObject = new JSONObject(intent.getStringExtra("answer"));
            startValid(uuid, jsonObject);
        }
        catch (JSONException e) {
            Toast.makeText(this, "Network error", Toast.LENGTH_SHORT);
        }
    }

    public void showQRCode() {
        Intent intent = new Intent(this, ObjectQRActivity.class);
        intent.putExtra("UUID", uuid);
        startActivity(intent);
        finish();
    }

    public void showOptions() {
        progressBar.setVisibility(View.GONE);
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
                Intent intent = new Intent(this, SearchActivity.class);
                startActivity(intent);
                break;
        }
        return true;
    }

    public void startValid(String uuid, JSONObject jsonObject) {
        ValidTask task = new ValidTask(this, uuid, jsonObject);
        task.execute();
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
