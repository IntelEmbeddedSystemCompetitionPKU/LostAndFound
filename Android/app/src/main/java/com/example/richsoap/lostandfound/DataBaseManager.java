package com.example.richsoap.lostandfound;

import com.raizlabs.android.dbflow.annotation.Database;

/**
 * Created by richsoap on 18-6-19.
 */
@Database(name = DataBaseManager.NAME, version = DataBaseManager.VERSION)

public class DataBaseManager {
    public static final String NAME = "dbFlowDataBase";
    public static final int VERSION = 1;
}
