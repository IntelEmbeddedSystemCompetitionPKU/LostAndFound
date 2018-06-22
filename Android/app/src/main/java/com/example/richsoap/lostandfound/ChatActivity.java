package com.example.richsoap.lostandfound;

import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.ActionBar;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.DefaultItemAnimator;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.example.richsoap.lostandfound.Adapters.ChatAdapter;
import com.example.richsoap.lostandfound.Adapters.UserlistAdapter;
import com.example.richsoap.lostandfound.NormalObject.ChatPiece;
import com.example.richsoap.lostandfound.Table.ChatPieceStore;
import com.example.richsoap.lostandfound.Table.ChatPieceStore_Table;
import com.example.richsoap.lostandfound.Table.OtherUserStore;
import com.raizlabs.android.dbflow.sql.language.Delete;
import com.raizlabs.android.dbflow.sql.language.SQLite;

import java.util.ArrayList;
import java.util.List;

public class ChatActivity extends AppCompatActivity {
    private static final String TAG = "ChatActivity";
    private String uuid;
    private int kind;
    private RecyclerView recyclerView;
    private ChatAdapter adapter;
    private Button sendButton;
    private EditText editText;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_chat);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
        ActionBar actionBar = getSupportActionBar();
        if(actionBar != null) {
            actionBar.setDisplayHomeAsUpEnabled(true);
            actionBar.setDisplayShowTitleEnabled(true);
        }

        Intent intent = getIntent();
        uuid = intent.getStringExtra("uuid");
        kind = intent.getIntExtra("kind", 0);
        adapter = new ChatAdapter(this);
        recyclerView = (RecyclerView) findViewById(R.id.chat_recyclerview);
        recyclerView.setAdapter(adapter);
        LinearLayoutManager layoutManager = new LinearLayoutManager(this);
        recyclerView.setLayoutManager(layoutManager);
        recyclerView.setItemAnimator(new DefaultItemAnimator());

        sendButton = (Button) findViewById(R.id.chat_sendbutton);
        editText = (EditText) findViewById(R.id.chat_edit);
        sendButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String input = editText.getText().toString();
                editText.setText("");
                addData(input);
            }
        });
        readData();
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.toolbar_check, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()) {
            case android.R.id.home:
                finish();
                break;
            case R.id.toolbar_check:
                AlertDialog.Builder builder = new AlertDialog.Builder(this);
                builder.setPositiveButton("确认", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {

                    }
                });
                builder.setNegativeButton("取消", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {

                    }
                });
                builder.setTitle("请再次确认");
                builder.setMessage("你确认要给予对方获取权限吗?");
                builder.show();
                break;
        }
        return true;
    }

    private void readData() {
        List<ChatPiece> chatList = new ArrayList<>();
        List<ChatPieceStore> chatPieceStoreList = SQLite.select().from(ChatPieceStore.class).where(ChatPieceStore_Table.user.eq(uuid)).orderBy(ChatPieceStore_Table.date, true).queryList();
        for(int i = 0;i < chatPieceStoreList.size();i ++) {
            chatList.add(new ChatPiece(chatPieceStoreList.get(i)));
        }
        adapter.setData(chatList);
    }
    private void addData(String input) {
        ChatPieceStore chatPieceStore = new ChatPieceStore();
        chatPieceStore.insert(uuid, input, System.currentTimeMillis(),1);
        boolean result = chatPieceStore.save();
        Log.d(TAG, "addData: " + (result ? "Success" : "Fail"));
        adapter.addData(new ChatPiece(chatPieceStore));
    }
}
