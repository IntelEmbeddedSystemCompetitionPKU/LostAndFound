package com.example.richsoap.lostandfound.Services;

import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.graphics.BitmapFactory;
import android.os.IBinder;
import android.support.v4.app.NotificationCompat;
import android.util.Log;

import com.example.richsoap.lostandfound.ChatActivity;
import com.example.richsoap.lostandfound.DetailActivity;
import com.example.richsoap.lostandfound.NetworkManager;
import com.example.richsoap.lostandfound.NormalObject.LostObject;
import com.example.richsoap.lostandfound.NormalObject.OtherUser;
import com.example.richsoap.lostandfound.R;
import com.example.richsoap.lostandfound.Table.GettableLostObject;
import com.example.richsoap.lostandfound.Table.GettableLostObject_Table;
import com.example.richsoap.lostandfound.Table.OtherUserStore;
import com.raizlabs.android.dbflow.sql.language.SQLite;

import java.util.ArrayList;
import java.util.List;
import java.util.Timer;
import java.util.TimerTask;

public class CheckService extends Service {
    private List<LostObject> itemList;
    private List<OtherUser> userList;
    private Timer timer;
    private Context context;
    private int counter;
    private static final String TAG = "CheckService";

    public CheckService() {

    }

    @Override
    public IBinder onBind(Intent intent) {
        // TODO: Return the communication channel to the service.
        throw new UnsupportedOperationException("Not yet implemented");
    }

    @Override
    public void onCreate() {
        super.onCreate();
        itemList = new ArrayList<>();
        itemList.add(new LostObject("null"));
        userList = new ArrayList<>();
        userList.add(new OtherUser("null"));
        timer = new Timer();
        context = this;
        counter = 1;
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        TimerTask task = new TimerTask() {
            @Override
            public void run() {
                NotificationManager manager = (NotificationManager) getSystemService(Context.NOTIFICATION_SERVICE);
                List<LostObject> tempItemList = NetworkManager.getUnreadGetableItemList(context);
                for(int i = 0;i < tempItemList.size();i ++) {
                    int mark = 0;
                    for(int j = 0; j < itemList.size();j ++) {
                        if(itemList.get(j).getUuid().equals(tempItemList.get(i).getUuid())) {
                            mark = 1;
                        }
                    }
                    if(mark == 0) {
                        Intent intent = new Intent(context, DetailActivity.class);
                        intent.putExtra("UUID", tempItemList.get(i).getUuid());
                        intent.putExtra("Date", tempItemList.get(i).getDate());
                        Log.d(TAG, "run: Item date is " + tempItemList.get(i).getDate());
                        intent.putExtra("Description", tempItemList.get(i).getDescription());
                        intent.putExtra("Command","getable");
                        intent.putExtra("Number", tempItemList.get(i).getNumber());
                        PendingIntent pendingIntent = PendingIntent.getActivity(context,0,intent,PendingIntent.FLAG_UPDATE_CURRENT);
                        Notification notification = new NotificationCompat.Builder(context)
                                .setContentTitle("新物品")
                                .setContentText("New Item")////// Description
                                .setWhen(System.currentTimeMillis())
                                .setLargeIcon(BitmapFactory.decodeResource(getResources(), R.mipmap.objects))
                                .setSmallIcon(R.mipmap.objects)
                                .setContentIntent(pendingIntent)
                                .setAutoCancel(true)
                                .build();
                        manager.notify(counter, notification);
                        counter ++;
                        itemList.add(tempItemList.get(i));
                    }
                }
                List<OtherUser> tempUserList = NetworkManager.getWaitUserList(context);
                for(int i = 0;i < tempUserList.size();i ++) {
                    for(int j = 0;j < userList.size();j ++) {
                        if(!userList.get(j).getUuid().equals(tempUserList.get(i).getUuid())) {
                            Intent intent = new Intent(context, ChatActivity.class);
                            intent.putExtra("uuid", tempUserList.get(i).getUuid());
                            intent.putExtra("kind", 0); // 0 =receive
                            intent.putExtra("description", "Need auth");
                            // Description??
                            PendingIntent pendingIntent = PendingIntent.getActivity(context,0,intent,PendingIntent.FLAG_UPDATE_CURRENT);
                            Notification notification = new NotificationCompat.Builder(context)
                                    .setContentTitle("新消息")
                                    .setContentText("New Text")////// Description
                                    .setWhen(System.currentTimeMillis())
                                    .setLargeIcon(BitmapFactory.decodeResource(getResources(), R.mipmap.user))
                                    .setSmallIcon(R.mipmap.user)
                                    .setContentIntent(pendingIntent)
                                    .setAutoCancel(true)
                                    .build();
                            manager.notify(counter, notification);
                            counter ++;
                            userList.add(tempUserList.get(i));
                        }
                    }
                }
            }
        };
        timer.schedule(task,3000,5000);
        return super.onStartCommand(intent, flags, startId);
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
        if(timer != null) {
            timer.cancel();
        }
    }
}
