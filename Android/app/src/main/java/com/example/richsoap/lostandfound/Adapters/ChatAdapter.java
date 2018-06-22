package com.example.richsoap.lostandfound.Adapters;

import android.content.Context;
import android.icu.text.SimpleDateFormat;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import com.example.richsoap.lostandfound.NormalObject.ChatPiece;
import com.example.richsoap.lostandfound.R;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

/**
 * Created by richsoap on 18-6-20.
 */

public class ChatAdapter extends RecyclerView.Adapter<ChatAdapter.MyViewHolder> {
    private List<ChatPiece> chatList;
    private Context mContext;

    public ChatAdapter(Context context) {
        chatList = new ArrayList<>();
        mContext = context;
    }

    public void setData(List<ChatPiece> list) {
        chatList.clear();
        chatList.addAll(list);
        notifyDataSetChanged();
    }

    public void addData(ChatPiece dataPiece) {
        chatList.add(dataPiece);
        notifyItemInserted(chatList.size());
    }

    static class MyViewHolder extends RecyclerView.ViewHolder {
        TextView leftText;
        TextView rightText;
        TextView timeText;
        static long lasttime = 0;
        public MyViewHolder(View view) {
            super(view);
            leftText= (TextView) view.findViewById(R.id.chat_cardview_left);
            rightText = (TextView) view.findViewById(R.id.chat_cardview_right);
            timeText = (TextView) view.findViewById(R.id.chat_time);
        }
    }

    @Override
    public void onBindViewHolder(final MyViewHolder viewHolder, final int position) {
        ChatPiece chatPiece = chatList.get(position);
        if(chatPiece.getDate() - MyViewHolder.lasttime > 60000) {
            //String format0 = SimpleDateFormat.M;
            //SimpleDateFormat sf0 = new SimpleDateFormat(format0);
            String format1 = "MMMMd日H:mm";
            SimpleDateFormat sf1 = new SimpleDateFormat(format1);
            Date date = new Date(chatPiece.getDate());
            viewHolder.timeText.setText(sf1.format(date));
        }
        else {
            viewHolder.timeText.setVisibility(View.GONE);
        }
        MyViewHolder.lasttime = chatPiece.getDate();
        if(chatPiece.getDir() == 0) { //receive chatpiece
            viewHolder.rightText.setVisibility(View.GONE);
            viewHolder.leftText.setText(chatPiece.getText());
        }
        else {
            viewHolder.leftText.setVisibility(View.GONE);
            viewHolder.rightText.setText(chatPiece.getText());
        }
    }

    @Override
    public MyViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.content_chat_cardview, parent, false);
        MyViewHolder holder = new MyViewHolder(view);
        return holder;
    }

    @Override
    public int getItemCount() {
        return chatList.size();
    }
}
