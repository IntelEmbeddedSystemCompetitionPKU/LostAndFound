package com.example.richsoap.lostandfound.Adapters;

import android.content.Context;
import android.graphics.Bitmap;
import android.support.v7.widget.RecyclerView;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;

import com.example.richsoap.lostandfound.R;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by richsoap on 18-5-29.
 */

public class DetailImageAdapter extends RecyclerView.Adapter<DetailImageAdapter.MyViewHolder> {
    private List<Bitmap> mImageList;
    private Context mContext;
    private static final String TAG = "DetailImageAdapter";

    public DetailImageAdapter(Context context) {
        mImageList = new ArrayList<>();
        mContext = context;
    }

    public void setData(List<Bitmap> list) {
        mImageList.clear();
        mImageList.addAll(list);
        notifyDataSetChanged();
    }

    public void addData(Bitmap dataPiece) {
        mImageList.add(dataPiece);
        notifyItemInserted(mImageList.size());
    }

    static class MyViewHolder extends RecyclerView.ViewHolder {
        ImageView imageView;
        public MyViewHolder(View view) {
            super(view);
            imageView = (ImageView) view.findViewById(R.id.detail_cardview_image);
        }
    }

    @Override
    public void onBindViewHolder(final MyViewHolder viewHolder, final int position) {
        Log.d(TAG, "onBindViewHolder: " + Integer.toString(position));
        if(mImageList.get(position) == null) {
            Log.d(TAG, "onBindViewHolder: Null Object");
        }
        else {
            viewHolder.imageView.setImageBitmap(mImageList.get(position));
        }
    }

    @Override
    public MyViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.content_detail_cardview, parent, false);
        MyViewHolder holder = new MyViewHolder(view);
        return holder;
    }

    @Override
    public int getItemCount() {
        return mImageList.size();
    }
}
