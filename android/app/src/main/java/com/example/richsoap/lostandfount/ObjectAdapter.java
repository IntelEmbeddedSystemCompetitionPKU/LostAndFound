package com.example.richsoap.lostandfount;

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
    private List<String> mStringList;
    private Context mContext;

    public ObjectAdapter(Context context) {
        mStringList = new ArrayList<>();
        mContext = context;
    }

    public void setData(List<String> list) {
        mStringList.clear();
        mStringList.addAll(list);
        notifyDataSetChanged();
    }

    public void addData(String dataPiece) {
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
    public void onBindViewHolder(final MyViewHolder viewHolder, int position) {
        viewHolder.textView.setText(mStringList.get(position));
        viewHolder.textView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Toast.makeText(mContext, viewHolder.textView.getText().toString(), Toast.LENGTH_SHORT).show();
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
