package com.example.richsoap.lostandfound;

import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class SetServerActivity extends AppCompatActivity {
    EditText editip ;
    EditText editport ;
    Button button ;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_set_server);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        editip = (EditText) findViewById(R.id.server_ip);
        editport = (EditText) findViewById(R.id.server_port);
        button = (Button) findViewById(R.id.server_button);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String ip = editip.getText().toString();
                String port = editport.getText().toString();
                NetworkManager.setServer(ip, port);
                Toast.makeText(SetServerActivity.this, ip + ":" + port,Toast.LENGTH_SHORT).show();
            }
        });
    }

}
