package com.example.richsoap.lostandfound;

import android.content.Context;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by richsoap on 18-5-29.
 */

public class BlanksAdapter extends RecyclerView.Adapter<BlanksAdapter.MyViewHolder> {
    private List<Blanks> blanksList;
    private List<EditText> editTextList;
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

    public void addEditor() {
        blanksList.add(new Blanks(null, 1, Blanks.useforwhat.EDIT));
        notifyItemChanged(blanksList.size());
    }

    public List<String> getStrings() {
        List<String> result = new ArrayList<>();
        for(int i = 0;i < editTextList.size();i ++) {
            result.add(editTextList.get(i).getText().toString());
        }
        return result;
    }

    static class MyViewHolder extends RecyclerView.ViewHolder {
        TextView textView;
        EditText editText;
        public MyViewHolder(View view) {
            super(view);
            textView = (TextView)view.findViewById(R.id.answer_cardview_tips);
            editText = (EditText)view.findViewById(R.id.answer_cardview_text);
        }
    }

    @Override
    public void onBindViewHolder(final MyViewHolder viewHolder, final int position) {
        switch (blanksList.get(position).getType()) {
            case EDIT:
                editTextList.add(viewHolder.editText);
                viewHolder.editText.setVisibility(View.VISIBLE);
                viewHolder.textView.setVisibility(View.GONE);
            break;
            case IMAGE:
                viewHolder.textView.setText(blanksList.get(position).getImage());
                viewHolder.editText.setVisibility(View.GONE);
                viewHolder.textView.setVisibility(View.VISIBLE);
        }
    }

    @Override
    public MyViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.content_answer_cardview_img, parent, false);
        MyViewHolder holder = new MyViewHolder(view);
        return holder;
    }

    @Override
    public int getItemCount() {
        return blanksList.size();
    }
}
