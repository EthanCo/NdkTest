package com.heiko.mywangyiplayer;

import android.view.Surface;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

/**
 * 播放器
 *
 * @author EthanCo
 * @since 2019/5/31
 */
public class Player implements SurfaceHolder.Callback {
    static {
        System.loadLibrary("native-lib");
    }

    public native String stringFromJNI();

    private SurfaceHolder surfaceHolder;

    public void setSurfaceView(SurfaceView surfaceView) {
        if (null != this.surfaceHolder) {
            this.surfaceHolder.removeCallback(this);
        }
        this.surfaceHolder = surfaceView.getHolder();
        this.surfaceHolder.addCallback(this);
    }

    @Override
    public void surfaceCreated(SurfaceHolder holder) {

    }

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
        this.surfaceHolder = holder;
    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {

    }

    public void start(String path) {
        native_start(path,surfaceHolder.getSurface());
    }

    public native void native_start(String path, Surface surface);
}
