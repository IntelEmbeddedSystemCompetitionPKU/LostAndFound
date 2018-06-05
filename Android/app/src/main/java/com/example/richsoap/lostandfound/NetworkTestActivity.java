package com.example.richsoap.lostandfound;

import android.content.Context;
import android.content.Intent;
import android.graphics.Bitmap;
import android.media.Image;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;

public class NetworkTestActivity extends AppCompatActivity {
    private Button button;
    private EditText editText;
    private ImageView imageView;
    private ImageTask task;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_network_test);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        button = findViewById(R.id.test_button);
        editText = findViewById(R.id.test_edit);
        imageView = findViewById(R.id.test_image);
        task = new ImageTask(this);

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String url = editText.getText().toString();
                tryToGetImage(url);
            }
        });

    }

    private void tryToGetImage(String url) {
        task.execute(url);
    }

    private class ImageTask extends AsyncTask<String, Void, Bitmap> {

        private Context context;
        public ImageTask(Context context) {
            this.context = context;
        }

        @Override
        protected Bitmap doInBackground(String... url) {
            return NetworkManager.getImageByUrl(url[0], context);
        }

        @Override
        protected void onPostExecute(final Bitmap result) {
            if(result != null){
                imageView.setImageBitmap(result);
            }
        }
    }


}
