package com.heiko.ndkfilepatchtest;

/**
 * @author EthanCo
 * @since 2018/7/4
 */
public class NDKFileUtils {
    static{
        System.loadLibrary("native-lib");
    }

    public static native String stringFromJNI();

    /**
     * 拆分
     *
     * @param path
     * @param count
     */
    public static native void diff(String path,String patternPath, int count);

    /**
     * 合并
     *
     * @param path
     * @param count
     */
    public static native void patch(String path,String patternPath, int count);
}