package com.ethanco.jni;

import java.util.Date;
import java.util.Random;
import java.util.UUID;

import com.ethanco.jni.bean.Human;
import com.ethanco.jni.bean.Man;

//javah com.ethanco.jni.JniTest
public class JniTest {
	public String key ="jason";
	
	public Human man001 = new Man();
	
	public static int count = 15;
	
	public native static String getStringFromC();
	
	public native String getStringFromC2();
	
	//访问属性，返回修改之后的属性
	public native String accessField();
	
	//访问静态变量
	public native void accessStaticField();
	
	//访问方法
	public native void accessMethod();
	
	//访问静态方法
	public native void accessStaticMethod();
	
	//访问构造方法
	public native Date accessConstructor();
	
	//访问父类方法
	public native void accessNonvirtualMethod();
	
	//传入中文，返回中文
	public native String chineseChars(String in);
	
	//处理数组 (传一个数组对它进行排序)
	public native void giveArray(int[] array);
	
	//处理数组 (返回一个数组)
	public native int[] getArray(int len);
	
	//局部引用 释放对象
	public native void localRef();
	
	//创建全局引用
	public native void createGlobalRef();
	
	//获取全局引用
	public native String getGlobalRef();
	
	//释放全局变量
	public native void deleteGlobalRef();
	
	//异常处理
	public native void exeception();
	
	//缓存策略
	public native void cached();
	
	//
	public native static void initIds();
	
	public static void main(String[] args) {
		System.out.println("Hello world!");
		String text = getStringFromC();
		System.out.println(text);
		JniTest jniTest = new JniTest();
		String text2 = jniTest.getStringFromC2();
		System.out.println(text2);
		System.out.println("修改前key:"+jniTest.key);
		System.out.println(jniTest.accessField());
		System.out.println("修改后key:"+jniTest.key);
		
		System.out.println("修改前count:"+count);
		jniTest.accessStaticField();
		System.out.println("修改后count:"+count);
		
		jniTest.accessMethod();
		
		jniTest.accessStaticMethod();
		
		jniTest.accessConstructor();
		
		jniTest.accessNonvirtualMethod();
		
		String result = jniTest.chineseChars("123abc宋江");
		System.out.println("result:"+result);
		
		int[] array = {9,100,10,37,5,10};
		jniTest.giveArray(array);
		for(int i : array) {
			System.out.println(String.valueOf(i));
		}
		
		System.out.println("---------array2----------------");
		int[] array2 = jniTest.getArray(10);
		for(int i : array2) {
			System.out.println(String.valueOf(i));
		}
		
		System.out.println("---------global----------------");
		jniTest.createGlobalRef();
		System.out.println(jniTest.getGlobalRef());
		//用完之后释放
		jniTest.deleteGlobalRef();
		//System.out.println("释放完之后:"+jniTest.getGlobalRef());
		
		try {
			jniTest.exeception();
		} catch(Exception e) {
			System.out.println("发生异常:"+e.getMessage());
		}
		
		System.out.println("---------异常发生后--------");
		
		try {
			jniTest.exeception();
		}catch(Exception e) {
			System.out.println(e.getMessage());
		}
		
		//不断调用cached方法
		for(int i=0;i<100;i++) {
			jniTest.cached();
		}
	}
	
	//产生指定范围的随机数
	public int getRandomInt(int max) {
		System.out.println("getRandomInt max:"+max);
		return new Random().nextInt(max);
	}
	
	//获取一个UUID
	public static String getUUID() {
		return UUID.randomUUID().toString();
	}
	
	static {
		System.loadLibrary("jni_study");
		initIds();
	}
}
