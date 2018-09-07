package com.ethanco.ndktttttt;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;

import org.fmod.FMOD;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    private ExecutorService fixedThreadPool;
    private PlayerThread playerThread;
    private String path = "file:///android_asset/singing.wav";
    private int type;

    private Button normal, luoli, dashu, jingsong, gaoguai, kongling;

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

        fixedThreadPool = Executors.newFixedThreadPool(1);
        FMOD.init(this);
    }

    class PlayerThread implements Runnable {
        @Override
        public void run() {
            Utils.fix(path, type);
        }
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.normal:
                type = Utils.MODE_NORMAL;
                break;
            case R.id.luoli:
                type = Utils.MODE_LUOLI;
                break;
            case R.id.dashu:
                type = Utils.MODE_DASHU;
                break;
            case R.id.jingsong:
                type = Utils.MODE_JINGSONG;
                break;
            case R.id.gaoguai:
                type = Utils.MODE_GAOGUAI;
                break;
            case R.id.kongling:
                type = Utils.MODE_KONGLING;
                break;
        }

        playerThread = new PlayerThread();
        fixedThreadPool.execute(playerThread);
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        FMOD.close();
    }
}
