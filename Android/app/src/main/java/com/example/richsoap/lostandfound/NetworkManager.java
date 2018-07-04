package com.example.richsoap.lostandfound;

import android.content.Context;
import android.graphics.Bitmap;
import android.util.Log;

import com.example.richsoap.lostandfound.NormalObject.Blanks;
import com.example.richsoap.lostandfound.NormalObject.ChatPiece;
import com.example.richsoap.lostandfound.NormalObject.LostObject;
import com.example.richsoap.lostandfound.NormalObject.OtherUser;
import com.example.richsoap.lostandfound.Table.GettableLostObject;
import com.example.richsoap.lostandfound.Table.OtherUserStore;
import com.yanzhenjie.nohttp.InitializationConfig;
import com.yanzhenjie.nohttp.NoHttp;
import com.yanzhenjie.nohttp.RequestMethod;
import com.yanzhenjie.nohttp.cache.DBCacheStore;
import com.yanzhenjie.nohttp.cookie.DBCookieStore;
import com.yanzhenjie.nohttp.rest.CacheMode;
import com.yanzhenjie.nohttp.rest.Request;
import com.yanzhenjie.nohttp.rest.Response;

import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;
import java.util.UUID;

import static com.example.richsoap.lostandfound.NetworkManager.LoginResult.ERRORPASSWORD;
import static com.example.richsoap.lostandfound.NetworkManager.LoginResult.NETERROR;
import static com.example.richsoap.lostandfound.NetworkManager.LoginResult.SUCCESS;

/**
 * Created by richsoap on 18-5-29.
 */

public class NetworkManager {
    private static final String TAG = "NetworkManager";
    private static String ip = "162.105.91.179";
    private static String port = "5000";
    private static String userName = "tester";
    private static String password = "testing";
    public enum LoginResult {
        SUCCESS, ERRORPASSWORD, NETERROR;
    }

    static public void setServer(String _ip, String _port) {
        ip = _ip;
        port = _port;
    }

    static public void setUserInfo(String _username, String _userpassword) {
        userName = _username;
        password = _userpassword;
    }

    static public LoginResult isValidUser(Context mContext) {
        // login with input userName and password, if not exists, register it
        //return SUCCESS;/*
        NoHttp.initialize(mContext);
        JSONObject jsonObject = new JSONObject();
        try {
            jsonObject.put("username", userName);
            jsonObject.put("password", password);
        }
        catch(JSONException e) {
            return NETERROR;
        }
        String url = "http://" + ip + ":" + port +"/sign/signup";
        String result = null;
        Log.d(TAG, "isValidUser: " + jsonObject.toString());
        Request<String> request = NoHttp.createStringRequest(url, RequestMethod.POST);
		request.setDefineRequestBodyForJson(jsonObject);
		Response<String> response = NoHttp.startRequestSync(request);
		if(response.isSucceed()) {
			result = response.get();
            Log.d(TAG, "isValidUser: signin " + result);
        }
		else {
			return NETERROR;
		}
		if(result.equals("True")) {
			return SUCCESS;
		}
		url = "http://" + ip + ":" + port + "/sign/signin";
		request = NoHttp.createStringRequest(url, RequestMethod.POST);
		response = NoHttp.startRequestSync(request);
		if(response.isSucceed()) {
			result = response.get();
            Log.d(TAG, "isValidUser: signup " + result);
		}
		else {
			return NETERROR;
		}
		if(result.equals("True")) {
			return SUCCESS;
		}
		return ERRORPASSWORD;
    }

    static public List<String> getUUIDList(String date, String keywords, Context mContext) { //PASS
        NoHttp.initialize(mContext);
        String url = "http://" + ip + ":" + port +"/query/lostlist";
        JSONObject sendjsonObject = new JSONObject();
        try{
            sendjsonObject.put("date", date);
            sendjsonObject.put("description", keywords);
        }
        catch (JSONException e) {
            return null;
        }
        Log.d(TAG, "getUUIDList: send json in string" + sendjsonObject.toString());
        Request<String> request = NoHttp.createStringRequest(url,  RequestMethod.POST);
        request.setDefineRequestBodyForJson(sendjsonObject);
        Response<String> response = NoHttp.startRequestSync(request);
        List<String> imageList = new ArrayList<>();
        if(response.isSucceed()) {
            try {
                String resString = response.get();
                Log.d(TAG, "getUUIDList: response get " + resString);
                JSONObject jsonObject = new JSONObject(resString);
                int count = jsonObject.getInt("uuid_num");
                Log.d(TAG, "getUUIDList: uuid_num = " + Integer.toString(count));
                for(int i = 0;i < count;i ++) {
                    imageList.add(jsonObject.getString("uuid" + Integer.toString(i)));
                }
            }
            catch (JSONException e) {
                Log.d(TAG, "getUUIDList: JSONException");
                return imageList;
            }
        }
        else {
            Log.d(TAG, "getUUIDList: Something wrong with response");
        }
        return imageList;
    }

    static public LostObject getUUIDDetail(String uuid, Context mContext) { //PASS
        NoHttp.initialize(mContext);
        String url = "http://" + ip + ":" + port +"/query/getinfo/" + uuid;
        Request<String> request = NoHttp.createStringRequest(url,  RequestMethod.GET);
        Response<String> response = NoHttp.startRequestSync(request);
        if(response.isSucceed()) {
            try {
                Log.d(TAG, "getUUIDDetail: " + response.get());
                JSONObject jsonObject = new JSONObject(response.get());
                String date;
                String description;
                int number;
                date = jsonObject.getString("time");
                description = jsonObject.getString("description");
                number = jsonObject.getInt("LD_num");
                LostObject lostObject = new LostObject(uuid);
                lostObject.setDate(date);
                lostObject.setDescription(description);
                lostObject.setNumber(number);
                return lostObject;
            }
            catch (JSONException e) {
                Log.d(TAG, "getUUIDDetail: JSONException");
                return null;
            }
        }
        else {
            Log.d(TAG, "getUUIDDetail: Unsucceed");
            return null;
        }
    }

    static public Bitmap getImage(String uuid, String kind, int number, Context mContext) {// For every image from server
        InitializationConfig initializationConfig = InitializationConfig.newBuilder(mContext)
                .cacheStore(new DBCacheStore(mContext).setEnable(true))
                .cookieStore(new DBCookieStore(mContext).setEnable(true))
                .build();
        NoHttp.initialize(initializationConfig);
        //NoHttp.initialize(mContext);
        String url = "http://" + ip + ":" + port +"/query/" + uuid + "/" + kind + "/" + Integer.toString(number);
        NoHttp.initialize(mContext);
        Log.d(TAG, "getImage: Try to get " + url);
        Request<Bitmap> req = NoHttp.createImageRequest(url);
        req.setCacheMode(CacheMode.NONE_CACHE_REQUEST_NETWORK);
        Response<Bitmap> response = NoHttp.startRequestSync(req);
        if (response.isSucceed()) {
            Log.d(TAG, "getImage: Get image success");
            return response.get();
        } else {
            Log.d(TAG, "getImage: Get image fail");
            return null;
        }
    }

    static public Bitmap getQRImage(String uuid, Context mContext) {// For every image from server
        NoHttp.initialize(mContext);/////////need more logic here
        String url = "http://" + ip + ":" + port +"/query/qrcode";
        NoHttp.initialize(mContext);
        Log.d(TAG, "getQRImage: Try to get QRcode:" + url);
        JSONObject jsonObject = new JSONObject();
        try {
            jsonObject.put("useruuid", userName);
            jsonObject.put("itemuuid", uuid);
        }
        catch (JSONException e) {
            return null;
        }
        Log.d(TAG, "getQRImage: json is: " + jsonObject.toString());
        Request<Bitmap> req = NoHttp.createImageRequest(url, RequestMethod.POST);
        req.setDefineRequestBodyForJson(jsonObject);
        Response<Bitmap> response = NoHttp.startRequestSync(req);
        if (response.isSucceed()) {
            Log.d(TAG, "getQRImage: Success");
            return response.get();
        } else {
            Log.d(TAG, "getQRImage: Fail");
            return null;
        }
    }

    static public List<Blanks> getBlanksList(String uuid, Context mContext) {// get blank id list from server
        String url = "http://" + ip + ":" + port + "/query/maskinfo/" + uuid;
        NoHttp.initialize(mContext);
        Request<String> request = NoHttp.createStringRequest(url,  RequestMethod.GET);
        Response<String> response = NoHttp.startRequestSync(request);
        if(response.isSucceed()) {

            int count;
            List<Blanks> maskList = new ArrayList<>();
            try {
                JSONObject jsonObject = new JSONObject(response.get());
                count = jsonObject.getInt("mask_num");
                for(int i = 0;i < count;i ++) {
                    maskList.add(new Blanks(jsonObject.getInt("block" + Integer.toString(i) + "_num"))); // knowing how many blanks for each mask is enough
                }
            }
            catch (JSONException e) {
                Log.d(TAG, "getBlanksList: " + response.get());
                Log.d(TAG, "getBlanksList: JSONException");
                return null;
            }
            return maskList;
        }
        else {
            return null;
        }
    }

    static public Bitmap getImageByUrl(String url, Context mContext) {// for test image download
        NoHttp.initialize(mContext);
        Request<Bitmap> req = NoHttp.createImageRequest(url);
        Response<Bitmap> response = NoHttp.startRequestSync(req);
        if (response.isSucceed()) {
            Log.d(TAG, "getImageByUrl: Success");
            return response.get();
        } else {
            Log.d(TAG, "getImageByUrl: Null");
            return null;
        }
    }

    static public boolean tryToValid(String uuid, JSONObject jsonObject, Context mContext) {
        return true;
    }

    static public boolean sendMessage(ChatPiece message, Context mContext) {
        return true;
    }
    static public List<ChatPiece> getMessages(String uuid, long time, Context mContext) {
        return null;
    }

    static public Bitmap generateQRCode(String description, Context mContext) {
        return null;
        /*NoHttp.initialize(mContext);
        String url = "test";/////////////////////////////////////
        Request<Bitmap> req = NoHttp.createImageRequest(url);
        JSONObject jsonObject = new JSONObject();
        try {
            jsonObject.put("description", description);
        }
        catch (JSONException e) {
            return null;
        }
        req.setDefineRequestBodyForJson(jsonObject);
        Response<Bitmap> response = NoHttp.startRequestSync(req);
        if(response.isSucceed()) {
            Log.d(TAG, "generateQRCode: Generate QRCode return successed");
            return response.get();
        }
        else {
            Log.d(TAG, "generateQRCode: Generate QRCode failed");
            return null;
        }*/
    }

    static public List<OtherUserStore> getWaitUserList() {
        return new ArrayList<>();
    }

    static public List<String> getGetableItemList() {
        return new ArrayList<>();
    }
    static public List<GettableLostObject> getUnreadGetableItemList() {
        return new ArrayList<>();
    }

}
