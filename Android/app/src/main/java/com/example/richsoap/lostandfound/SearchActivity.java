package com.example.richsoap.lostandfound;

import android.app.DatePickerDialog;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.support.design.widget.NavigationView;
import android.support.v4.view.GravityCompat;
import android.support.v4.widget.DrawerLayout;
import android.support.v7.app.ActionBarDrawerToggle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.MenuItem;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.EditText;
import android.widget.TextView;

import com.example.richsoap.lostandfound.DebugActivity.NetworkTestActivity;

import java.util.Calendar;

/**
* This Activity is designed for searching uuid list from server via date and key words, and this activity will jump to ListActivity.
* */
public class SearchActivity extends AppCompatActivity
        implements NavigationView.OnNavigationItemSelectedListener {
    private TextView mDateText;
    private Button mButton;
    private EditText mEditText;

    private int year;
    private int month;
    private int day;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_search);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
        mDateText = (TextView) findViewById(R.id.searchactivity_date);
        mButton = (Button) findViewById(R.id.searchactivity_button);
        mEditText = (EditText) findViewById(R.id.searchactivity_keywords);
        setDatePicker();
        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        ActionBarDrawerToggle toggle = new ActionBarDrawerToggle(
                this, drawer, toolbar, R.string.navigation_drawer_open, R.string.navigation_drawer_close);
        drawer.addDrawerListener(toggle);
        toggle.syncState();

        NavigationView navigationView = (NavigationView) findViewById(R.id.nav_view);
        navigationView.setNavigationItemSelectedListener(this);
        mButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(SearchActivity.this, ListActivity.class);
                String keywords = mEditText.getText().toString();
                String date = mDateText.getText().toString();
                intent.putExtra("keywords", keywords);
                intent.putExtra("date", date);
                startActivity(intent);
            }
        });
    }

    @Override
    public void onBackPressed() {
        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        if (drawer.isDrawerOpen(GravityCompat.START)) {
            drawer.closeDrawer(GravityCompat.START);
        } else {
            super.onBackPressed();
        }
    }

    @SuppressWarnings("StatementWithEmptyBody")
    @Override
    public boolean onNavigationItemSelected(MenuItem item) {
        // Handle navigation view item clicks here.
        int id = item.getItemId();

        if (id == R.id.nav_camera) {
            // Handle the camera action
        } else if (id == R.id.nav_gallery) {
            Intent intent = new Intent(this, NetworkTestActivity.class);
            startActivity(intent);
        } else if (id == R.id.nav_slideshow) {

        } else if (id == R.id.nav_manage) {

        } else if (id == R.id.nav_share) {

        } else if (id == R.id.nav_send) {

        }

        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        drawer.closeDrawer(GravityCompat.START);
        return true;
    }

    private void setDatePicker() {
        final DatePickerDialog.OnDateSetListener pickerlistener = new DatePickerDialog.OnDateSetListener() {
            @Override
            public void onDateSet(DatePicker picker, int selyear, int selmonth, int selday) {
                mDateText.setText(Integer.toString(selyear) + "-" + Integer.toString(selmonth) +  "-" + Integer.toString(selday));
                year = selyear;
                month = selmonth;
                day = selday;
            }
        };

        mDateText.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                DatePickerDialog datePickerDialog = new DatePickerDialog(SearchActivity.this, pickerlistener, year, month, day);
                datePickerDialog.show();
            }
        });

        Calendar calendar = Calendar.getInstance();
        year = calendar.get(Calendar.YEAR);
        month = calendar.get(Calendar.MONTH);
        day = calendar.get(Calendar.DAY_OF_MONTH);

        mDateText.setText(Integer.toString(year) + "-" + Integer.toString(month + 1) +  "-" + Integer.toString(day));

    }
}
