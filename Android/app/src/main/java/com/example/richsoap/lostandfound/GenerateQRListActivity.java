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
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;

import com.example.richsoap.lostandfound.Adapters.GenerateQRCodeAdapter;
import com.example.richsoap.lostandfound.NormalObject.GenerateQRCode;
import com.example.richsoap.lostandfound.Table.OtherUserStore;
import com.example.richsoap.lostandfound.Table.GenerateQRCodeStore;
import com.raizlabs.android.dbflow.sql.language.Delete;
import com.raizlabs.android.dbflow.sql.language.SQLite;

import java.util.ArrayList;
import java.util.List;
import java.util.UUID;

public class GenerateQRListActivity extends AppCompatActivity {

    RecyclerView recyclerView;
    GenerateQRCodeAdapter adapter;
    List<GenerateQRCode> list = new ArrayList<>();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_generate_qrlist);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
        ActionBar actionBar = getSupportActionBar();
        if(actionBar != null) {
            actionBar.setDisplayHomeAsUpEnabled(true);
            actionBar.setDisplayShowTitleEnabled(true);
        }
        FloatingActionButton fab = (FloatingActionButton) findViewById(R.id.generate_fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startGenerateNew();
            }
        });

        recyclerView = findViewById(R.id.generate_recyclerview);
        adapter = new GenerateQRCodeAdapter(this);
        recyclerView.setAdapter(adapter);
        LinearLayoutManager layoutManager = new LinearLayoutManager(this);
        recyclerView.setLayoutManager(layoutManager);
        recyclerView.setItemAnimator(new DefaultItemAnimator());
    }

    @Override
    protected void onResume() {
        super.onResume();
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
                Delete.table(GenerateQRCodeStore.class);
                adapter.setData(new ArrayList<GenerateQRCode>());
                break;
        }
        return true;
    }

    private void startGenerateNew() {
        Intent intent = new Intent(this, GenerateQRCodeActivity.class);
        intent.putExtra("uuid", UUID.randomUUID().toString());
        intent.putExtra("description", "");
        startActivity(intent);
    }

    private void read_data() {
        List<GenerateQRCodeStore> qrCodes = SQLite.select().from(GenerateQRCodeStore.class).queryList();
        list.clear();
        for(int i = 0;i < qrCodes.size();i ++) {
            list.add(new GenerateQRCode(qrCodes.get(i)));
        }
        adapter.setData(list);
    }
}
