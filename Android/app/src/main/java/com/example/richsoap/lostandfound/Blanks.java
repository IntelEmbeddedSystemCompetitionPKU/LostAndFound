package com.example.richsoap.lostandfound;

import android.graphics.Bitmap;

/**
 * Created by richsoap on 18-6-3.
 */

public class Blanks {
    private String imageUUID;
    private int number;
    private Bitmap image;
    //private Bitmap image;
    public Blanks(String uuid, int number) {
        imageUUID = uuid;
        this.number = number;
        image = null;
    }

    public String getImageUUID() {
        return imageUUID;
    }

    public void setImageUUID(String imageUUID) {
        this.imageUUID = imageUUID;
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }

    public Bitmap getImage() {
        return image;
    }

    public void setImage(Bitmap image) {
        this.image = image;
    }

}
