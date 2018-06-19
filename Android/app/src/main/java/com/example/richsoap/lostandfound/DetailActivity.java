package com.example.richsoap.lostandfound;

import android.content.Context;
import android.content.Intent;
import android.graphics.Bitmap;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.v7.app.ActionBar;
import android.support.v7.widget.DefaultItemAnimator;
import android.support.v7.widget.GridLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.util.Log;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.TextView;

import com.example.richsoap.lostandfound.Adapters.DetailImageAdapter;

import java.util.List;

/**
 * This Activity is designed for showing some detail information for objects, which is selected by user
 * Step1, get resource list for the uuid passed by ListActivity
 * Step2, display every HD photo in a recycerview, which works with DetailImageAdapter
 * Step3, if user want to answer questions about this object, click the OK button at topright on the screen, and jump to AnswerActivity
 */

public class DetailActivity extends AppCompatActivity {
    private static final String TAG = "DetailActivity";

    private List<String> imgList;
    private String description;
    private String date;
    private int number;
    private RecyclerView recyclerView;
    private String uuid;
    private DetailImageAdapter adapter;
    private ImageTask imageTask;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_detail);
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
        date = intent.getStringExtra("Date");
        number = intent.getIntExtra("Number", 0);
        TextView textView = findViewById(R.id.detail_description);
        textView.setText(description);
        recyclerView = (RecyclerView) findViewById(R.id.detail_recyclerview);
        adapter = new DetailImageAdapter(this);
        recyclerView.setAdapter(adapter);
        GridLayoutManager layoutManager = new GridLayoutManager(this,2);
        recyclerView.setLayoutManager(layoutManager);
        recyclerView.setItemAnimator(new DefaultItemAnimator());
        getImages();
    }


    private void getImages() {
        imageTask = new ImageTask(this);
        imageTask.execute();
    }
    private void addImageToList(Bitmap img) {
        adapter.addData(Bitmap.createBitmap(img));
    }

    @Override
    protected void onStop() {
        super.onStop();
        if(imageTask != null) {
            imageTask.cancel(true);
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
                Intent intent = new Intent(this, AnswerActivity.class);
                intent.putExtra("UUID", uuid);
                startActivity(intent);
                break;
        }
        return true;
    }

    private class ImageTask extends AsyncTask<Void, Bitmap, Void> {
        private Context context;
        public ImageTask(Context context) {
            this.context = context;
        }

        @Override
        protected Void doInBackground(Void... keys) {
            Log.d(TAG, "doInBackground: " + Integer.toString(number));
            for(int i = 0;i < number;i ++) {
                Log.d(TAG, "doInBackground: Start getting image " + Integer.toString(i));
                Bitmap result = NetworkManager.getImage(uuid, "LD", i, context);
                publishProgress(result);
                if(isCancelled()) {
                    return null;
                }
            }
            return null;
        }

        @Override
        protected void onProgressUpdate(Bitmap... details) {
            Log.d(TAG, "onProgressUpdate: " + details[0]);
            if(details[0] != null) {
                addImageToList(details[0]);
            }
        }

    }


}
