package com.example.richsoap.lostandfound.Adapters;

import android.content.Intent;
import android.support.v7.widget.CardView;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import com.example.richsoap.lostandfound.DetailActivity;
import com.example.richsoap.lostandfound.ListActivity;
import com.example.richsoap.lostandfound.NormalObject.LostObject;
import com.example.richsoap.lostandfound.R;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by richsoap on 18-5-29.
 */

public class ObjectAdapter extends RecyclerView.Adapter<ObjectAdapter.MyViewHolder> {
    private List<LostObject> lostObjectList;
    private ListActivity mContext;

    public ObjectAdapter(ListActivity activity) {
        lostObjectList = new ArrayList<>();
        mContext = activity;
    }

    public void setData(List<LostObject> list) {
        lostObjectList.clear();
        lostObjectList.addAll(list);
        notifyDataSetChanged();
    }

    public void addData(LostObject dataPiece) {
        lostObjectList.add(dataPiece);
        notifyItemInserted(lostObjectList.size());
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
        final LostObject lostObject = lostObjectList.get(position);
        viewHolder.dateText.setText(lostObject.getDate());
        viewHolder.descriptionText.setText(lostObject.getDescription());
        viewHolder.image.setImageBitmap(lostObject.getPhoto());
        viewHolder.cardView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mContext.cancleTask();
                Intent intent = new Intent(mContext, DetailActivity.class);
                intent.putExtra("UUID", lostObject.getUuid());
                intent.putExtra("Description", lostObject.getDescription());
                intent.putExtra("Number", lostObject.getNumber());
                intent.putExtra("Date", lostObject.getDate());
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
        return lostObjectList.size();
    }
}
