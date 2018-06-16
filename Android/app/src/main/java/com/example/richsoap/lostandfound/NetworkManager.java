package com.example.richsoap.lostandfound;

import android.content.Context;
import android.graphics.Bitmap;
import android.util.Log;
import android.widget.ImageView;

import com.yanzhenjie.nohttp.NoHttp;
import com.yanzhenjie.nohttp.RequestMethod;
import com.yanzhenjie.nohttp.rest.ImageRequest;
import com.yanzhenjie.nohttp.rest.JsonObjectRequest;
import com.yanzhenjie.nohttp.rest.Request;
import com.yanzhenjie.nohttp.rest.Response;
import com.yanzhenjie.nohttp.rest.SyncRequestExecutor;

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

    static public List<String> getUUIDList(String date, String keywords, Context mContext) {
        /*try{
            Thread.sleep(500);
        }
        catch (InterruptedException e) {

        }
        List<String> list = new ArrayList<>();
        for(int i = 0;i <7;i ++) {
            list.add(UUID.randomUUID().toString());
            list.add(UUID.randomUUID().toString());
        }
        return list;*/

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

    static public LostObject getUUIDDetail(String uuid, Context mContext) {
        /*try {
            Thread.sleep(500);
        }
        catch (InterruptedException e) {

        }
        return new LostObject(uuid);*/
        NoHttp.initialize(mContext);
        String url = "http://" + ip + ":" + port +"/sign/signup";
        Request<JSONObject> request = NoHttp.createJsonObjectRequest(url,  RequestMethod.POST);
        request.add("uuid", "uuid");
        Response<JSONObject> response = NoHttp.startRequestSync(request);
        if(response.isSucceed()) {
            JSONObject jsonObject = response.get();
            try {
                String date;
                String description;
                int number;
                date = jsonObject.getString("date");
                description = jsonObject.getString("description");
                number = jsonObject.getInt("number");
                LostObject lostObject = new LostObject(uuid);
                lostObject.setDate(date);
                lostObject.setDescription(description);
                lostObject.setNumber(number);
                return lostObject;
            }
            catch (JSONException e) {
                return null;
            }
        }
        else {
            return null;
        }
    }

    static public List<String> getImageList(String uuid, Context mContext) {// For HD image list
        List<String> imgList = new ArrayList<>();
        for(int i = 0;i < 10;i ++) {
            imgList.add(Integer.toString(i));
        }
        try {
            Thread.sleep(500);
        }
        catch (InterruptedException e) {

        }
        return imgList;
        /*NoHttp.initialize(mContext);
        String url = "http://" + ip + ":" + port +"/sign/signup";
        Request<JSONObject> request = NoHttp.createJsonObjectRequest(url,  RequestMethod.POST);
        request.add("uuid",uuid);
        Response<JSONObject> response = NoHttp.startRequestSync(request);
        if(response.isSucceed()) {
            JSONObject jsonObject = response.get();
            int count;
            List<String> imageList = new ArrayList<>();
            try {
                count = jsonObject.getInt("img_num");
                for(int i = 0;i < count;i ++) {
                    imageList.add(jsonObject.getString("img" + Integer.toString(i)));
                }
            }
            catch (JSONException e) {
                return null;
            }
        }
        else {
            return null;
        }*/
    }

    static public Bitmap getImage(String uuid, String kind, int number, Context mContext) {// For every image from server
        NoHttp.initialize(mContext);
        String url = "http://" + ip + ":" + port +"/query/" + uuid + "/" + kind + "/" + Integer.toString(number);
        NoHttp.initialize(mContext);
        Request<Bitmap> req = NoHttp.createImageRequest(url);
        Response<Bitmap> response = NoHttp.startRequestSync(req);
        if (response.isSucceed()) {
            return response.get();
        } else {
            return null;
        }
    }

    static public List<Blanks> getBlanksList(String uuid, Context mContext) {// get blank id list from server
        List<Blanks> list = new ArrayList<>();
        for(int i = 0;i < 3;i ++) {
            list.add(new Blanks(UUID.randomUUID().toString(), i + 2));
        }
        return list;
        /*String url = "http://" + ip + ":" + port +"/sign/signup";
        NoHttp.initialize(mContext);
        Request<JSONObject> request = NoHttp.createJsonObjectRequest(url,  RequestMethod.POST);
        request.add("uuid",uuid);
        Response<JSONObject> response = NoHttp.startRequestSync(request);
        if(response.isSucceed()) {
            JSONObject jsonObject = response.get();
            int count;
            List<String> imageList = new ArrayList<>();
            try {
                count = jsonObject.getInt("block_num");
                for(int i = 0;i < count;i ++) {
                    imageList.add(jsonObject.getString("block" + Integer.toString(i)));
                }
            }
            catch (JSONException e) {
                return null;
            }
        }
        else {
            return null;
        }*/
    }

    static public Bitmap getImageByUrl(String url, Context mContext) {// for test image download
        NoHttp.initialize(mContext);
        /*ImageRequest req = new ImageRequest(url,RequestMethod.GET,1280,1280, Bitmap.Config.RGB_565, ImageView.ScaleType.CENTER);
        Response<Bitmap> response = SyncRequestExecutor.INSTANCE.execute(req);
        */
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

}
