package com.example.richsoap.lostandfound.NormalObject;

import com.example.richsoap.lostandfound.Table.GenerateQRCodeStore;

/**
 * Created by richsoap on 18-7-3.
 */

public class GenerateQRCode {
    private String description;
    private String uuid;
    public GenerateQRCode() {
        description = null;
        uuid = null;
    }

    public GenerateQRCode(GenerateQRCodeStore generateQrCodeStore) {
        description = generateQrCodeStore.getDescription();
        uuid = generateQrCodeStore.getUuid();
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public String getUuid() {
        return uuid;
    }

    public void setUuid(String uuid) {
        this.uuid = uuid;
    }
}
