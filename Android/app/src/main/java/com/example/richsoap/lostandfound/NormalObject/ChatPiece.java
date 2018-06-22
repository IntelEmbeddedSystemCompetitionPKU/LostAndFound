package com.example.richsoap.lostandfound.NormalObject;

import com.example.richsoap.lostandfound.Table.ChatPieceStore;
import com.raizlabs.android.dbflow.annotation.Column;

/**
 * Created by richsoap on 18-6-20.
 */

public class ChatPiece {
    private String user;

    private String text;

    private long date;

    private int dir;

    public ChatPiece() {
        user = null;
        text = null;
        date = 0;
        dir = 0;
    }

    public ChatPiece(ChatPieceStore chatPieceStore) {
        user = chatPieceStore.getUser();
        text = chatPieceStore.getText();
        date = chatPieceStore.getDate();
        dir = chatPieceStore.getDir();
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
}
