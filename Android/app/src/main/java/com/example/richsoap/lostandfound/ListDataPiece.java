package com.example.richsoap.lostandfound;

/**
 * Created by richsoap on 18-6-3.
 */

public class ListDataPiece {
    private String uuid;
    private String detail;
    public ListDataPiece(String uuid, String detail) {
        this.uuid = uuid;
        this.detail = detail;
    }
    public String getUuid() {
        return uuid;
    }
    public String getDetail() {
        return detail;
    }
    public void setUuid(String uuid) {
        this.uuid = uuid;
    }
    public void setDetail(String detail) {
        this.detail = detail;
    }
}
