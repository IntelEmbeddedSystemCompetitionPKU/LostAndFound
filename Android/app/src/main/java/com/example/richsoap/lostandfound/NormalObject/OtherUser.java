package com.example.richsoap.lostandfound.NormalObject;

import com.raizlabs.android.dbflow.annotation.Column;

/**
 * Created by richsoap on 18-6-19.
 */

public class OtherUser {
    private String uuid;
    private int kind;
    private String description;

    public OtherUser() {
        uuid = null;
        kind = 0;
        description = null;
    }
    public OtherUser(com.example.richsoap.lostandfound.Table.OtherUser otherUser) {
        uuid = otherUser.getUuid();
        kind = otherUser.getKind();
        description = otherUser.getDescription();
    }

    public String getUuid() {
        return uuid;
    }

    public void setUuid(String uuid) {
        this.uuid = uuid;
    }

    public int getKind() {
        return kind;
    }

    public void setKind(int kind) {
        this.kind = kind;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }
}
