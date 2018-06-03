package com.example.richsoap.lostandfount;

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

}
