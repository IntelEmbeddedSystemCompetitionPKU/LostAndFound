package com.example.richsoap.lostandfound.Adapters;

import android.content.Context;
import android.content.Intent;
import android.support.v7.widget.CardView;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import com.example.richsoap.lostandfound.ChatActivity;
import com.example.richsoap.lostandfound.GenerateQRCodeActivity;
import com.example.richsoap.lostandfound.GenerateQRListActivity;
import com.example.richsoap.lostandfound.NormalObject.GenerateQRCode;
import com.example.richsoap.lostandfound.NormalObject.OtherUser;
import com.example.richsoap.lostandfound.R;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by richsoap on 18-7-3.
 */

public class GenerateQRCodeAdapter extends RecyclerView.Adapter<GenerateQRCodeAdapter.MyViewHolder> {
    private List<GenerateQRCode> descriptionList;
    private Context mContext;

    public GenerateQRCodeAdapter(Context activity) {
        descriptionList = new ArrayList<>();
        mContext = activity;
    }

    public void setData(List<GenerateQRCode> list) {
        descriptionList.clear();
        descriptionList.addAll(list);
        notifyDataSetChanged();
    }

    public void addData(GenerateQRCode dataPiece) {
        descriptionList.add(dataPiece);
        notifyItemInserted(descriptionList.size());
    }

    static class MyViewHolder extends RecyclerView.ViewHolder {
        TextView kindText;
        TextView descriptionText;
        CardView cardView;
        public MyViewHolder(View view) {
            super(view);
            cardView = (CardView)view.findViewById(R.id.userlist_cardview);
            kindText = (TextView)view.findViewById(R.id.userlist_cardview_kind);
            descriptionText = (TextView)view.findViewById(R.id.userlist_cardview_description);
        }
    }

    @Override
    public void onBindViewHolder(final MyViewHolder viewHolder, final int position) {
        final GenerateQRCode qrCode = descriptionList.get(position);
        viewHolder.descriptionText.setText(qrCode.getDescription());
        viewHolder.kindText.setVisibility(View.GONE);
        viewHolder.cardView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(mContext, GenerateQRCodeActivity.class);
                intent.putExtra("description", qrCode.getDescription());
                intent.putExtra("uuid", qrCode.getUuid());
                mContext.startActivity(intent);
            }
        });
    }

    @Override
    public MyViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.content_user_list_cardview, parent, false);
        MyViewHolder holder = new MyViewHolder(view);
        return holder;
    }

    @Override
    public int getItemCount() {
        return descriptionList.size();
    }
}