package com.heiko.socketevolvetest;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import com.heiko.socketevolve.SocketEvolve;

public class MainActivity extends AppCompatActivity {

    private Button btnUdpSend;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        btnUdpSend = findViewById(R.id.btn_udp_send);
        btnUdpSend.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Toast.makeText(getApplicationContext(), "send Udp", Toast.LENGTH_SHORT).show();
                new Thread(){
                    @Override
                    public void run() {
                        super.run();
                        SocketEvolve evolve = new SocketEvolve();
                        evolve.sendUdp("{\"head\":{\"ukey\":\"b4f9b1535e2553fcd34fd5fbf8eb4090\",\"ts\":\"20170601102100\",\"method\":\"6002\" ,\"proto_version\":\"V2.0\"}}","192.168.39.255",8977);
                    }
                }.start();
            }
        });
    }
}
