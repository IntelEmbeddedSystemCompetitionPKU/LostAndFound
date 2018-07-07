package com.example.richsoap.lostandfound;

import android.content.Context;
import android.content.Intent;
import android.graphics.Bitmap;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.v7.app.ActionBar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;

import com.example.richsoap.lostandfound.NormalObject.GenerateQRCode;
import com.example.richsoap.lostandfound.Table.GenerateQRCodeStore;
import com.example.richsoap.lostandfound.Table.GenerateQRCodeStore_Table;
import com.raizlabs.android.dbflow.sql.language.Delete;
import com.raizlabs.android.dbflow.sql.language.SQLite;

import java.util.ArrayList;
import java.util.List;

public class GenerateQRCodeActivity extends AppCompatActivity {
    private EditText editText;
    private ImageView imageView;
    private Button button;
    private String uuid;
    private String description;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_ask_for_qrcode);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
        ActionBar actionBar = getSupportActionBar();
        if(actionBar != null) {
            actionBar.setDisplayHomeAsUpEnabled(true);
            actionBar.setDisplayShowTitleEnabled(true);
        }

        editText = findViewById(R.id.askforqr_edit);
        imageView = findViewById(R.id.askforqr_image);
        button = findViewById(R.id.askforqr_button);

        Intent intent = getIntent();
        description = intent.getStringExtra("description");
        uuid = intent.getStringExtra("uuid");

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                description = editText.getText().toString();
                if(description.length() > 0) {
                    List<GenerateQRCodeStore> list = SQLite.select().from(GenerateQRCodeStore.class).where(GenerateQRCodeStore_Table.uuid.eq(uuid)).queryList();
                    if(list.size() > 0) {
                        SQLite.update(GenerateQRCodeStore.class).set(GenerateQRCodeStore_Table.description.eq(description)).where(GenerateQRCodeStore_Table.uuid.eq(uuid)).query();
                    }
                    else {
                        GenerateQRCodeStore generateQrCodeStore = new GenerateQRCodeStore();
                        generateQrCodeStore.insert(description, uuid);
                        generateQrCodeStore.save();
                    }
                    startGetQRCode();
                }
            }
        });
        editText.setText(description);
        if(!description.equals("")) {
            startGetQRCode();
        }

    }
    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        //Log.d(TAG, "onOptionsItemSelected: " + Integer.toString(item.getItemId()) + "----" + R.id.home);
        switch (item.getItemId()) {
            case android.R.id.home:
                finish();
                break;
        }
        return true;
    }


    private void startGetQRCode() {
        GetQRCodeTask getQRCodeTask = new GetQRCodeTask(this);
        getQRCodeTask.execute(description);
    }

    private void setQRCode(Bitmap bitmap) {
        imageView.setImageBitmap(bitmap);
    }


    private class GetQRCodeTask extends AsyncTask<String, Void, Bitmap> {
        private Context context;
        public GetQRCodeTask(Context context) {
            this.context = context;
        }

        @Override
        protected Bitmap doInBackground(String... keys) {
            return NetworkManager.generateQRCode(keys[0], context);
        }
        @Override
        protected void onPostExecute(Bitmap bitmap) {
            if(bitmap != null) {
                setQRCode(bitmap);
            }
        }
    }
}
