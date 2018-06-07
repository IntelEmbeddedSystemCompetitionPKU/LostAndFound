package com.example.richsoap.lostandfound;

import android.content.Context;
import android.graphics.Bitmap;
import android.util.Log;
import android.widget.ImageView;

import com.yanzhenjie.nohttp.NoHttp;
import com.yanzhenjie.nohttp.RequestMethod;
import com.yanzhenjie.nohttp.rest.ImageRequest;
import com.yanzhenjie.nohttp.rest.Request;
import com.yanzhenjie.nohttp.rest.Response;
import com.yanzhenjie.nohttp.rest.SyncRequestExecutor;

import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;
import java.util.UUID;

/**
 * Created by richsoap on 18-5-29.
 */

public class NetworkManager {
    private static final String TAG = "NetworkManager";
    private static String ip = "127.0.0.1";
    private static String port = "22";
    public enum LoginResult {
        SUCCESS, ERRORPASSWORD, NETERROR;
    }

    static public void setServer(String _ip, String _port) {
        ip = _ip;
        port = _port;

    }

    static public LoginResult isValidUser(String userName, String password, Context mContext) {
        NoHttp.initialize(mContext);
        JSONObject jsonObject = new JSONObject();
        jsonObject.put("username", userName);

        String url = "http://" + ip + ":" + port +"/sign/signup";
        String result = null;
		Request<String> request = NoHttp.createStringRequest(url, RequestMethod.POST);
		if(request.isSucceed()) {
			result = request.get();
		}
		else {
			return NETERROR;
		}
		if(result.equals("1")) {
			return SUCCESS;
		}
		url = "http://" + ip + ":" + port + "/sign/signin";
		request = NoHttp.createStringRequest(url, RequestMethod.POST);
		if(request.isSucceed()) {
			result = request.get();
		}
		else {
			return NETERROR;
		}
		if(result.equals("1")) {
			return SUCCESS;
		}
		return ERRORPASSWORD;
    }

    static public List<String> getUUIDList(String date, String keywords, Context mContext) {
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

    static public String getUUIDDetail(String uuid, Context mContext) {
        try {
            Thread.sleep(2000);
        }
        catch (InterruptedException e) {

        }
        return uuid + "--" + uuid + "--" + uuid;
    }

    static public List<String> getImageList(String uuid, Context mContext) {
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

    static public String getImage(String uuid, Context mContext) {
        try {
            Thread.sleep(2000);
        }
        catch (InterruptedException e) {

        }
        return uuid + "\n" + uuid + "\n" + uuid;
    }

    static public List<Blanks> getBlanksList(String uuid, Context mContext) {
        List<Blanks> list = new ArrayList<>();
        for(int i = 0;i < 3;i ++) {
            list.add(new Blanks(UUID.randomUUID().toString(), i + 2, Blanks.useforwhat.DATAPIECE));
        }
        return list;
    }

    static public Bitmap getImageByUrl(String url, Context mContext) {
        NoHttp.initialize(mContext);
        ImageRequest req = new ImageRequest(url,RequestMethod.GET,1280,1280, Bitmap.Config.RGB_565, ImageView.ScaleType.CENTER);
        Response<Bitmap> response = SyncRequestExecutor.INSTANCE.execute(req);
        if (response.isSucceed()) {
            return response.get();
        } else {
            return null;
        }
    }

}
