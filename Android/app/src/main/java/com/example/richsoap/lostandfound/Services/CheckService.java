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
        userList = new ArrayList<>();
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
                    if(!itemList.contains(tempItemList.get(i))) {
                        Intent intent = new Intent(context, ChatActivity.class);
                        intent.putExtra("uuid", tempItemList.get(i).getUuid());
                        intent.putExtra("kind",1);
                        intent.putExtra("date", tempItemList.get(i).getDate());
                        intent.putExtra("description", tempItemList.get(i).getDescription());
                        // Description??
                        PendingIntent pendingIntent = PendingIntent.getActivity(context,0,intent,0);
                        Notification notification = new NotificationCompat.Builder(context)
                                .setContentTitle("新消息")
                                .setContentText("New Text")////// Description
                                .setWhen(System.currentTimeMillis())
                                .setLargeIcon(BitmapFactory.decodeResource(getResources(), R.mipmap.user))
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
                    if(!userList.contains(tempUserList.get(i))) {
                        Intent intent = new Intent(context, ChatActivity.class);
                        intent.putExtra("uuid", tempUserList.get(i).getUuid());
                        intent.putExtra("kind", 1);
                        intent.putExtra("description", "Need auth");
                        // Description??
                        PendingIntent pendingIntent = PendingIntent.getActivity(context,0,intent,0);
                        Notification notification = new NotificationCompat.Builder(context)
                                .setContentTitle("新物品")
                                .setContentText("New Text")////// Description
                                .setWhen(System.currentTimeMillis())
                                .setLargeIcon(BitmapFactory.decodeResource(getResources(), R.mipmap.objects))
                                .setSmallIcon(R.mipmap.objects)
                                .setContentIntent(pendingIntent)
                                .setAutoCancel(true)
                                .build();
                        manager.notify(counter, notification);
                        counter ++;
                        userList.add(tempUserList.get(i));
                    }
                }
            }
        };
        timer.schedule(task,3000);
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
