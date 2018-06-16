package com.example.richsoap.lostandfound;

import android.graphics.Bitmap;

/**
 * Created by richsoap on 18-6-15.
 */

public class LostObject {
    private String uuid;
    private String date;
    private String description;
    private Bitmap photo;
    private int number;
    public LostObject(String _uuid) {
        uuid = _uuid;
        date = null;
        date = null;
        description = null;
        photo = null;
        number = 0;
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }

    public String getUuid() {
        return uuid;
    }

    public void setUuid(String uuid) {
        this.uuid = uuid;
    }

    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        this.date = date;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public Bitmap getPhoto() {
        return photo;
    }

    public void setPhoto(Bitmap photo) {
        this.photo = photo;
    }
}
