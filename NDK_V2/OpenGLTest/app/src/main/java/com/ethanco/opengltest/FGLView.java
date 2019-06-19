package com.ethanco.opengltest;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.util.AttributeSet;

/**
 * GLSurfaceView继承自SurfaceView，自带渲染线程GLThread
 *
 * @author EthanCo
 * @since 2019/6/19
 */
public class FGLView extends GLSurfaceView {
    public FGLView(Context context) {
        super(context);
    }

    //绘制三角形 、等腰三角形、正方形、立方体
    public FGLView(Context context, AttributeSet attrs) {
        super(context, attrs);
        setEGLContextClientVersion(2); //设置版本
        setRenderer(new FGLRender(this));
        requestRender();
        //RENDERMODE_WHEN_DIRTY 效率高，自己调用渲染
        setRenderMode(GLSurfaceView.RENDERMODE_WHEN_DIRTY);
    }
}
