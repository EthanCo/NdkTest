package com.heiko.mywangyiplayer;

import android.os.Bundle;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.view.SurfaceView;
import android.view.View;
import android.view.WindowManager;

import java.io.File;

public class MainActivity extends AppCompatActivity {



    private SurfaceView surfaceView;
    private Player player;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        getWindow().setFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON,
                WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
        setContentView(R.layout.activity_main);
        surfaceView = findViewById(R.id.surfaceView);

        player = new Player();
        player.setSurfaceView(surfaceView);
    }

    public void open(View view) {
        String input = new File(Environment.getExternalStorageDirectory(),"input.mp3").getAbsolutePath();
        player.start(input);
    }
}
