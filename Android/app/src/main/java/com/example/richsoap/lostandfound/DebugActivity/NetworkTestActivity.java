package com.example.richsoap.lostandfound.DebugActivity;

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
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;

import com.example.richsoap.lostandfound.NetworkManager;
import com.example.richsoap.lostandfound.R;

public class NetworkTestActivity extends AppCompatActivity {
    private Button button;
    private EditText editText;
    private ImageView imageView;
    private ImageTask task;
    private static final String TAG = "NetworkTestActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_network_test);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        button = findViewById(R.id.test_button);
        editText = findViewById(R.id.test_edit);
        imageView = findViewById(R.id.test_image);

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String url = editText.getText().toString();
                tryToGetImage(url);
            }
        });

    }

    private void tryToGetImage(String url) {
        task = new ImageTask(this);
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
                Log.d(TAG, "onPostExecute: Set Image");
                imageView.setImageBitmap(result);
            }
        }
    }


}
