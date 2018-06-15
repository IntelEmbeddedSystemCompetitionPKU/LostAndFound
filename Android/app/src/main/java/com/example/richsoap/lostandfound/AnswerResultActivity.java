package com.example.richsoap.lostandfound;

import android.content.Context;
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

        Intent intent = getIntent();
        textView = (TextView)findViewById(R.id.answer_result_text);
        textView.setText(intent.getStringExtra("answer"));
        uuid = intent.getStringExtra("uuid");
        try {
            jsonObject = new JSONObject(intent.getStringExtra("answer"));
            Toast.makeText(this,jsonObject.toString(), Toast.LENGTH_SHORT);
        }
        catch (JSONException e) {
            Toast.makeText(this, "Network error", Toast.LENGTH_SHORT);
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
                Intent intent = new Intent(this, SearchActivity.class);
                startActivity(intent);
                break;
        }
        return true;
    }


}
