package com.example.richsoap.lostandfound.Table;

import com.example.richsoap.lostandfound.DataBaseManager;
import com.raizlabs.android.dbflow.annotation.Column;
import com.raizlabs.android.dbflow.annotation.PrimaryKey;
import com.raizlabs.android.dbflow.annotation.Table;
import com.raizlabs.android.dbflow.structure.BaseModel;

/**
 * Created by richsoap on 18-7-3.
 */
@Table(database = DataBaseManager.class, name = "GenerateQRCodeStore_Table")

public class GenerateQRCodeStore extends BaseModel {
    @PrimaryKey(autoincrement = true)
    public long id;

    @Column
    private String description;

    @Column
    private String uuid;

    public String getUuid() {
        return uuid;
    }

    public void setUuid(String uuid) {
        this.uuid = uuid;
    }

    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public void insert(String description, String uuid) {
        this.description = description;
        this.uuid = uuid;
    }
    public GenerateQRCodeStore() {
        this.description = null;
        this.uuid = null;
    }
}
