package com.example.richsoap.lostandfound;

/**
 * Created by richsoap on 18-6-3.
 */

public class Blanks {
    private String imageUUID;
    private int number;
    private useforwhat type;
    private String image;
    public Blanks(String uuid, int number, useforwhat type) {
        imageUUID = uuid;
        this.number = number;
        this.type = type;
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

    public useforwhat getType() {
        return type;
    }

    public void setType(useforwhat type) {
        this.type = type;
    }

    public String getImage() {
        return image;
    }

    public void setImage(String image) {
        this.image = image;
    }

    public enum useforwhat {
        DATAPIECE, IMAGE, EDIT;
    }
}
