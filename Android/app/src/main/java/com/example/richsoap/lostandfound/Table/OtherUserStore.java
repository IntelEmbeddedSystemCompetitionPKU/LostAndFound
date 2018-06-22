package com.example.richsoap.lostandfound.Table;

import com.example.richsoap.lostandfound.DataBaseManager;
import com.raizlabs.android.dbflow.annotation.Column;
import com.raizlabs.android.dbflow.annotation.PrimaryKey;
import com.raizlabs.android.dbflow.annotation.Table;
import com.raizlabs.android.dbflow.structure.BaseModel;

/**
 * Created by richsoap on 18-6-19.
 */

@Table(database = DataBaseManager.class, name = "OtherUserStore_Table")

public class OtherUserStore extends BaseModel {
    @PrimaryKey(autoincrement = true)
    public long id;

    @Column
    private String uuid;

    @Column
    private int kind;

    @Column
    private String description;

    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
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

    public void insert(String uuid, int kind, String description) {
        this.uuid = uuid;
        this.kind = kind;
        this.description = description;
    }

}
