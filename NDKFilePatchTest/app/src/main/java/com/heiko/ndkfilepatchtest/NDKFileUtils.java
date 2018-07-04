package com.heiko.ndkfilepatchtest;

/**
 * @author EthanCo
 * @since 2018/7/4
 */
public class NDKFileUtils {
    /**
     * 拆分
     *
     * @param path
     * @param count
     */
    public static native void diff(String path, int count);

    /**
     * 合并
     *
     * @param path
     * @param count
     */
    public static native void patch(String path, int count);
}