package com.example.richsoap.lostandfound.Adapters;

import android.content.Context;
import android.content.Intent;
import android.support.v7.widget.CardView;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import com.example.richsoap.lostandfound.DetailActivity;
import com.example.richsoap.lostandfound.R;
import com.example.richsoap.lostandfound.NormalObject.OtherUser;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by richsoap on 18-6-19.
 */

public class UserlistAdapter extends RecyclerView.Adapter<UserlistAdapter.MyViewHolder> {
    private List<OtherUser> userList;
    private Context mContext;

    public UserlistAdapter(Context activity) {
        userList = new ArrayList<>();
        mContext = activity;
    }

    public void setData(List<OtherUser> list) {
        userList.clear();
        userList.addAll(list);
        notifyDataSetChanged();
    }

    public void addData(OtherUser dataPiece) {
        userList.add(dataPiece);
        notifyItemInserted(userList.size());
    }

    static class MyViewHolder extends RecyclerView.ViewHolder {
        TextView dateText;
        TextView descriptionText;
        ImageView image;
        CardView cardView;
        public MyViewHolder(View view) {
            super(view);
            cardView = (CardView)view.findViewById(R.id.list_cardview);
            dateText = (TextView)view.findViewById(R.id.list_cardview_date);
            descriptionText = (TextView)view.findViewById(R.id.list_cardview_description);
            image = (ImageView)view.findViewById(R.id.list_cardview_image);
        }
    }

    @Override
    public void onBindViewHolder(final MyViewHolder viewHolder, final int position) {
        viewHolder.cardView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(mContext, DetailActivity.class);
                intent.putExtra("uuid", userList.get(position).getUuid());
                intent.putExtra("Description", userList.get(position).getDescription());
                intent.putExtra("kind", userList.get(position).getKind());
                mContext.startActivity(intent);
            }
        });
    }

    @Override
    public MyViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.content_list_cardview, parent, false);
        MyViewHolder holder = new MyViewHolder(view);
        return holder;
    }

    @Override
    public int getItemCount() {
        return userList.size();
    }
}
