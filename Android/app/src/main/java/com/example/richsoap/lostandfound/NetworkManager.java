package com.example.richsoap.lostandfound;

import android.util.Log;

import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;
import java.util.UUID;

/**
 * Created by richsoap on 18-5-29.
 */

public class NetworkManager {
    private static final String TAG = "NetworkManager";
    public enum LoginResult {
        SUCCESS, ERRORPASSWORD;
    }
    static public LoginResult isValidUser(String userName, String password) {
        try {
            Thread.sleep(2000);
        }
        catch (InterruptedException e) {
            //return LoginResult.ERRORPASSWORD;
        }
        if(password.equals("testing")) {
            Log.w(TAG, "isValidUser: Right Password");
            return LoginResult.SUCCESS;
        } else {
            Log.w(TAG, "isValidUser: Wrong Password " + password);
            return LoginResult.ERRORPASSWORD;
        }
    }

    static public List<String> getUUIDList(String date, String keywords) {
        try{
            Thread.sleep(2000);
        }
        catch (InterruptedException e) {

        }
        List<String> list = new ArrayList<>();
        for(int i = 0;i <7;i ++) {
            list.add(UUID.randomUUID().toString());
            list.add(UUID.randomUUID().toString());
        }
        return list;
    }

    static public String getUUIDDetail(String uuid) {
        try {
            Thread.sleep(2000);
        }
        catch (InterruptedException e) {

        }
        return uuid + "--" + uuid + "--" + uuid;
    }

    static public List<String> getImageList(String uuid) {
        List<String> imgList = new ArrayList<>();
        for(int i = 0;i < 10;i ++) {
            imgList.add(Integer.toString(i));
        }
        try {
            Thread.sleep(2000);
        }
        catch (InterruptedException e) {

        }
        return imgList;
    }

    static public String getImage(String uuid) {
        try {
            Thread.sleep(2000);
        }
        catch (InterruptedException e) {

        }
        return uuid + "\n" + uuid + "\n" + uuid;
    }

    static public List<Blanks> getBlanksList(String uuid) {
        List<Blanks> list = new ArrayList<>();
        for(int i = 0;i < 3;i ++) {
            list.add(new Blanks(UUID.randomUUID().toString(), i + 2, Blanks.useforwhat.DATAPIECE));
        }
        return list;
    }

}
