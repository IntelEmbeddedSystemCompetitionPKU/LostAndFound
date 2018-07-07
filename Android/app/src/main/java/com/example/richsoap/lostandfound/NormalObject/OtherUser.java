package com.example.richsoap.lostandfound.NormalObject;

import com.example.richsoap.lostandfound.Table.OtherUserStore;

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
    public OtherUser(OtherUserStore otherUserStore) {
        uuid = otherUserStore.getUuid();
        kind = otherUserStore.getKind();
        description = otherUserStore.getDescription();
    }
    public OtherUser(String uuid) {
        this.uuid = uuid;
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
