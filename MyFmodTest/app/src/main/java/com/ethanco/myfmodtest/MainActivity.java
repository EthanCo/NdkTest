package com.ethanco.myfmodtest;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;

import org.fmod.FMOD;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    private int type;
    private Button normal, luoli, dashu, jingsong, gaoguai, kongling;
    private String path = "file:///android_asset/singing.wav";
    private ExecutorService crackThreadPool;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        normal = findViewById(R.id.normal);
        luoli = findViewById(R.id.luoli);
        dashu = findViewById(R.id.dashu);
        jingsong = findViewById(R.id.jingsong);
        gaoguai = findViewById(R.id.gaoguai);
        kongling = findViewById(R.id.kongling);
        normal.setOnClickListener(this);
        luoli.setOnClickListener(this);
        dashu.setOnClickListener(this);
        jingsong.setOnClickListener(this);
        gaoguai.setOnClickListener(this);
        kongling.setOnClickListener(this);

        crackThreadPool = Executors.newFixedThreadPool(1);
        FMOD.init(this);
    }

    class PlayerRunnable implements Runnable {
        @Override
        public void run() {
            FmodUtil.crack(path, type);
        }
    }

    private PlayerRunnable playerRunnable = new PlayerRunnable();

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.normal:
                type = FmodUtil.MODE_NORMAL;
                break;
            case R.id.luoli:
                type = FmodUtil.MODE_LUOLI;
                break;
            case R.id.dashu:
                type = FmodUtil.MODE_DASHU;
                break;
            case R.id.jingsong:
                type = FmodUtil.MODE_JINGSONG;
                break;
            case R.id.gaoguai:
                type = FmodUtil.MODE_GAOGUAI;
                break;
            case R.id.kongling:
                type = FmodUtil.MODE_KONGLING;
                break;
        }

        crackThreadPool.execute(playerRunnable);
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        FMOD.close();
    }
}
