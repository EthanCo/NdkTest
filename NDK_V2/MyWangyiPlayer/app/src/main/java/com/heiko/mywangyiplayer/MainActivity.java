package com.heiko.mywangyiplayer;

import android.Manifest;
import android.os.Bundle;
import android.os.Environment;
import android.support.v4.app.ActivityCompat;
import android.support.v7.app.AppCompatActivity;
import android.view.SurfaceView;
import android.view.View;
import android.view.WindowManager;
import android.widget.Toast;

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

        ActivityCompat.requestPermissions(this, new String[]{
                Manifest.permission.READ_EXTERNAL_STORAGE,
                Manifest.permission.WRITE_EXTERNAL_STORAGE}, 1220);

        surfaceView = findViewById(R.id.surfaceView);

        player = new Player();
        player.setSurfaceView(surfaceView);
    }

    public void open(View view) {
        Toast.makeText(getApplicationContext(), "open", Toast.LENGTH_SHORT).show();
        String input = new File(Environment.getExternalStorageDirectory(), "input.mp4").getAbsolutePath();
        File file = new File(input);
        if (!file.exists()) {
            Toast.makeText(MainActivity.this, "文件不存在", Toast.LENGTH_SHORT).show();
            return;
        }
        player.start(input);
    }
}
