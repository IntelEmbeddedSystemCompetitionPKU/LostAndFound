package com.example.richsoap.lostandfound;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.graphics.Bitmap;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.ImageView;

public class ObjectQRActivity extends AppCompatActivity {
    private String uuid;
    private ImageView imageView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_item_qr);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
        imageView = findViewById(R.id.objectqr_image);
        Intent intent = getIntent();
        uuid = intent.getStringExtra("UUID");
        startGetQRcode();
    }
    public void startGetQRcode() {
        ImageTask imageTask = new ImageTask(this, uuid);
        imageTask.execute();
    }

    public void setImage(Bitmap bitmap) {
        if(bitmap != null) {
            imageView.setImageBitmap(bitmap);
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

    private class ImageTask extends AsyncTask<Void, Void, Bitmap> {
        private Context context;
        private String uuid;
        public ImageTask(Context context, String uuid) {
            this.uuid = uuid;
            this.context = context;
        }

        @Override
        protected Bitmap doInBackground(Void... keys) {
            Bitmap result = NetworkManager.getQRImage(uuid, context);
            return result;
        }

        @Override
        protected void onPostExecute(Bitmap result) {
            setImage(result);
        }
    }

}
