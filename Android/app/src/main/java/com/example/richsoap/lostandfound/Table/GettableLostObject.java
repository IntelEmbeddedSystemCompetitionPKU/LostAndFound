package com.example.richsoap.lostandfound.Table;

import com.example.richsoap.lostandfound.DataBaseManager;
import com.raizlabs.android.dbflow.annotation.Column;
import com.raizlabs.android.dbflow.annotation.PrimaryKey;
import com.raizlabs.android.dbflow.annotation.Table;
import com.raizlabs.android.dbflow.structure.BaseModel;

/**
 * Created by richsoap on 18-6-19.
 */
@Table(database = DataBaseManager.class)

public class GettableLostObject extends BaseModel {

    @PrimaryKey(autoincrement = true)
    private long id;

    @Column
    private String uuid;

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

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public void insert(String uuid, String description) {
        this.uuid = uuid;
        this.description = description;
    }
}
