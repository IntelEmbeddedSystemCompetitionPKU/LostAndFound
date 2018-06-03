package com.example.richsoap.lostandfound;

import android.app.DatePickerDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.EditText;

import java.util.Calendar;
import java.util.Date;

public class MainActivity extends AppCompatActivity {

    public int year = 2018;
    public int month = 1;
    public int day = 1;
    public long longtime = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button searchButton = findViewById(R.id.main_button_search);
        final Button dateButton = findViewById(R.id.main_button_date);
        final DatePickerDialog.OnDateSetListener pickerlistener = new DatePickerDialog.OnDateSetListener() {
            @Override
            public void onDateSet(DatePicker picker, int selyear, int selmonth, int selday) {
                dateButton.setText(Integer.toString(selyear) + "-" + Integer.toString(selmonth) +  "-" + Integer.toString(selday));
                year = selyear;
                month = selmonth;
                day = selday;
            }
        };

        dateButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                DatePickerDialog datePickerDialog = new DatePickerDialog(MainActivity.this, pickerlistener, year, month, day);
                datePickerDialog.show();
            }
        });

        Calendar calendar = Calendar.getInstance();
        year = calendar.get(Calendar.YEAR);
        month = calendar.get(Calendar.MONTH);
        day = calendar.get(Calendar.DAY_OF_MONTH);

        dateButton.setText(Integer.toString(year) + "-" + Integer.toString(month + 1) +  "-" + Integer.toString(day));
    }
}
