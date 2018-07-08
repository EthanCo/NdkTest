package com.heiko.ndkfilepatchtest;

import android.os.Bundle;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import java.io.File;

public class MainActivity extends AppCompatActivity {
    /*static {
        System.loadLibrary("native-lib");
    }*/

    private String SD_CARD_PATH;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        SD_CARD_PATH = Environment.getExternalStorageDirectory().getAbsolutePath();

        TextView tv = findViewById(R.id.sample_text);
        //tv.setText(stringFromJNI()+calcValue(1,2));
        tv.setText(NDKFileUtils.stringFromJNI());

        Button btnDiff = findViewById(R.id.btn_diff);
        btnDiff.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String path = SD_CARD_PATH + File.separatorChar+ "img.jpg";
                String path_pattern = SD_CARD_PATH +File.separatorChar+ "img_%d.jpg";
                NDKFileUtils.diff(path, path_pattern, 3);
                Log.d("jason", "拆分完毕..");
            }
        });
    }

   /* public native String stringFromJNI();

    public native int calcValue(int a,int b);*/
}
