package com.example.richsoap.lostandfound.Table;

import com.example.richsoap.lostandfound.DataBaseManager;
import com.example.richsoap.lostandfound.NormalObject.ChatPiece;
import com.raizlabs.android.dbflow.annotation.Column;
import com.raizlabs.android.dbflow.annotation.Database;
import com.raizlabs.android.dbflow.annotation.PrimaryKey;
import com.raizlabs.android.dbflow.annotation.Table;
import com.raizlabs.android.dbflow.structure.BaseModel;

/**
 * Created by richsoap on 18-6-19.
 */

@Table(database = DataBaseManager.class, name = "ChatPieceStore_Table")
public class ChatPieceStore extends BaseModel {

    @PrimaryKey(autoincrement = true)
    private long id;

    @Column
    public String user;

    @Column
    public String text;

    @Column
    public long date;

    @Column
    public int dir;

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

    public long getDate() {
        return date;
    }

    public void setDate(int date) {
        this.date = date;
    }

    public int getDir() {
        return dir;
    }

    public void setDir(int dir) {
        this.dir = dir;
    }

    public void insert(String user, String text, long date, int dir) {
        this.user = user;
        this.text = text;
        this.date = date;
        this.dir = dir;
    }
    public void insert(ChatPiece chatPiece) {
        user = chatPiece.getUser();
        text = chatPiece.getText();
        date = chatPiece.getDate();
        dir = chatPiece.getDir();
    }
}
