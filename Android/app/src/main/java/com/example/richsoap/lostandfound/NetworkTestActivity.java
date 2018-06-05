package com.example.richsoap.lostandfound;

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

            }
        });

    }

    private class ImageTask extends AsyncTask<String, Image, Void> {

        public ImageTask() {
        }

        @Override
        protected Void doInBackground(String... url) {

            return NetworkManager.getImage(url[0]);
        }
    }


}
