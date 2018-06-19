package com.example.richsoap.lostandfound.Adapters;

import android.content.Context;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.LinearLayout;

import com.example.richsoap.lostandfound.NormalObject.Blanks;
import com.example.richsoap.lostandfound.R;

import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by richsoap on 18-5-29.
 */

public class BlanksAdapter extends RecyclerView.Adapter<BlanksAdapter.MyViewHolder> {
    private List<Blanks> blanksList;
    private List<EditText> editTextList;// a list to store every edittext, so that we can get the answers easily
    private Context mContext;

    public BlanksAdapter(Context context) {
        blanksList = new ArrayList<>();
        mContext = context;
        editTextList = new ArrayList<>();
    }

    public void setData(List<Blanks> list) {
        blanksList.clear();
        blanksList.addAll(list);
        notifyDataSetChanged();
    }

    public void addData(Blanks dataPiece) {
        blanksList.add(dataPiece);
        notifyItemInserted(blanksList.size());
    }


    public JSONObject getStrings() {
        JSONObject outObject = new JSONObject();
        JSONObject tempObject;
        int count = 0;
        try {
            for(int i = 0;i < blanksList.size();i ++) {
                tempObject = new JSONObject();
                for(int j = 0;j < blanksList.get(i).getNumber();j ++) {
                    tempObject.put("blank" + Integer.toString(j), editTextList.get(count).getText().toString());
                    count ++;
                }
                outObject.put("mask" + Integer.toString(i), tempObject.toString());
            }
        }
        catch (JSONException e) {
            return outObject;
        }
        return outObject;
    }

    static class MyViewHolder extends RecyclerView.ViewHolder {
        ImageView imageView;
        LinearLayout linearLayout;
        public MyViewHolder(View view) {
            super(view);
            imageView = (ImageView) view.findViewById(R.id.answer_cardview_image);
            linearLayout = (LinearLayout) view.findViewById(R.id.answer_cardview_linearlayout);
        }
    }

    @Override
    public void onBindViewHolder(final MyViewHolder viewHolder, final int position) {
        Blanks blank = blanksList.get(position);
        viewHolder.imageView.setImageBitmap(blank.getImage());
        for(int i = 0;i < blank.getNumber();i ++) {
            EditText editText = new EditText(mContext);
            editText.setMaxLines(1);
            editTextList.add(editText);
            viewHolder.linearLayout.addView(editText);
        }
    }

    @Override
    public MyViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.content_answer_cardview, parent, false);
        MyViewHolder holder = new MyViewHolder(view);
        return holder;
    }

    @Override
    public int getItemCount() {
        return blanksList.size();
    }
}
