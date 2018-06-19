package com.example.richsoap.lostandfound.Table;

import com.example.richsoap.lostandfound.DataBaseManager;
import com.raizlabs.android.dbflow.annotation.Column;
import com.raizlabs.android.dbflow.annotation.Database;
import com.raizlabs.android.dbflow.annotation.PrimaryKey;
import com.raizlabs.android.dbflow.annotation.Table;

/**
 * Created by richsoap on 18-6-19.
 */

@Table(database = DataBaseManager.class)
public class ChatPiece {

    @PrimaryKey(autoincrement = true)
    private long id;

    @Column
    private String user;

    @Column
    private String text;

    @Column
    private int date;

    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    public String getUser() {
        return user;
    }

    public void setUser(String user) {
        this.user = user;
    }

    public String getText() {
        return text;
    }

    public void setText(String text) {
        this.text = text;
    }

    public int getDate() {
        return date;
    }

    public void setDate(int date) {
        this.date = date;
    }

    public void insert(String user, String text, int date) {
        this.user = user;
        this.text = text;
        this.date = date;
    }
}
