package com.example.richsoap.lostandfound;

import android.content.Intent;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.ActionBar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.DefaultItemAnimator;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Toast;

import com.example.richsoap.lostandfound.Adapters.ObjectAdapter;
import com.example.richsoap.lostandfound.Adapters.UserlistAdapter;
import com.example.richsoap.lostandfound.Table.OtherUser;
import com.raizlabs.android.dbflow.sql.language.Delete;
import com.raizlabs.android.dbflow.sql.language.SQLite;

import java.util.ArrayList;
import java.util.List;
import java.util.UUID;

public class UserListActivity extends AppCompatActivity {

    List<com.example.richsoap.lostandfound.NormalObject.OtherUser> userList = new ArrayList<>();
    RecyclerView recyclerView;
    UserlistAdapter userlistAdapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_user_list);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
        ActionBar actionBar = getSupportActionBar();
        if(actionBar != null) {
            actionBar.setDisplayHomeAsUpEnabled(true);
            actionBar.setDisplayShowTitleEnabled(true);
        }
        init_data();
        recyclerView = (RecyclerView) findViewById(R.id.userlist_recyclerview);
        userlistAdapter = new UserlistAdapter(this);
        recyclerView.setAdapter(userlistAdapter);
        LinearLayoutManager layoutManager = new LinearLayoutManager(this);
        recyclerView.setLayoutManager(layoutManager);
        recyclerView.setItemAnimator(new DefaultItemAnimator());
        read_data();
    }
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.toolbar_trash, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        //Log.d(TAG, "onOptionsItemSelected: " + Integer.toString(item.getItemId()) + "----" + R.id.home);
        switch (item.getItemId()) {
            case android.R.id.home:
                finish();
                break;
            case R.id.toolbar_trash:
                Delete.table(OtherUser.class);
                read_data();
                break;
        }
        return true;
    }

    private void init_data() {
        for(int i = 0;i < 3;i ++) {
            OtherUser otherUser = new OtherUser();
            otherUser.insert(UUID.randomUUID().toString(),0,"test" + Integer.toString(i));
            boolean save = otherUser.save();
            Toast.makeText(this, save? "Succeed" : "Failed", Toast.LENGTH_SHORT).show();
        }
    }

    private void read_data() {
        List<OtherUser> users = SQLite.select().from(OtherUser.class).queryList();
        userList.clear();
        for(int i = 0;i < users.size();i ++) {
            userList.add(new com.example.richsoap.lostandfound.NormalObject.OtherUser(users.get(i)));
        }
        userlistAdapter.setData(userList);
    }
}
