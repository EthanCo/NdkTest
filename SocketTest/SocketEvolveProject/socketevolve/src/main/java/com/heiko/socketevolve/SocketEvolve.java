package com.heiko.socketevolve;

import android.util.Log;

import java.util.ArrayList;
import java.util.List;

/**
 * SocketEvolve
 *
 * @author EthanCo
 * @since 2018/8/29
 */
public class SocketEvolve {
    private static final String TAG = "Z-SocketEvolve";

    static {
        System.loadLibrary("socket-evolve-lib");
    }

    public interface SocketEvolveCallBack {
        void onNotify(String message);
    }

    private List<SocketEvolveCallBack> callbacks = new ArrayList<>();

    public void registerSocketEvolvoCallBack(SocketEvolveCallBack listener) {
        if (!callbacks.contains(listener)) {
            callbacks.add(listener);
        }
    }

    public void unregisterSocketEvolvoCallBack(SocketEvolveCallBack listener) {
        callbacks.remove(listener);
    }

    public void notifyCallBack(String message) {
        Log.i(TAG, "notify:" + message);
        for (SocketEvolveCallBack callback : callbacks) {
            callback.onNotify(message);
        }
    }

    public native void sendUdp(String message, String hostName, int portno);
}
