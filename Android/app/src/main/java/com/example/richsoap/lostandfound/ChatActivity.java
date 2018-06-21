package com.example.richsoap.lostandfound;

import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;

import com.example.richsoap.lostandfound.Table.ChatPiece;
import com.example.richsoap.lostandfound.Table.OtherUser;
import com.raizlabs.android.dbflow.sql.language.SQLite;

import java.util.List;

public class ChatActivity extends AppCompatActivity {
    List<ChatPiece> chatList;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_chat);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
    }
}
