package com.example.richsoap.lostandfound.NormalObject;

import android.graphics.Bitmap;

/**
 * Created by richsoap on 18-6-3.
 */

public class Blanks {
    private int number;
    private Bitmap image;
    //private Bitmap image;
    public Blanks(int number) {
        this.number = number;
        image = null;
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
