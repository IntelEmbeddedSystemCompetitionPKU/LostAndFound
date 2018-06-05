package com.example.richsoap.lostandfound;

import android.content.Context;
import android.content.Intent;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by richsoap on 18-5-29.
 */

public class ObjectAdapter extends RecyclerView.Adapter<ObjectAdapter.MyViewHolder> {
    private List<ListDataPiece> mStringList;
    private ListActivity mContext;

    public ObjectAdapter(ListActivity activity) {
        mStringList = new ArrayList<>();
        mContext = activity;
    }

    public void setData(List<ListDataPiece> list) {
        mStringList.clear();
        mStringList.addAll(list);
        notifyDataSetChanged();
    }

    public void addData(ListDataPiece dataPiece) {
        mStringList.add(dataPiece);
        notifyItemInserted(mStringList.size());
    }

    static class MyViewHolder extends RecyclerView.ViewHolder {
        TextView textView;
        public MyViewHolder(View view) {
            super(view);
            textView = (TextView)view.findViewById(R.id.list_cardview_text);
        }
    }

    @Override
    public void onBindViewHolder(final MyViewHolder viewHolder, final int position) {
        viewHolder.textView.setText(mStringList.get(position).getDetail());
        viewHolder.textView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mContext.cancleTask();
                Intent intent = new Intent(mContext, DetailActivity.class);
                intent.putExtra("UUID", mStringList.get(position).getUuid());
                intent.putExtra("Detail", mStringList.get(position).getDetail());
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
        return mStringList.size();
    }
}
