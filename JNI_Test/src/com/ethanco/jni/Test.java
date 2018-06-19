package com.ethanco.jni;

//类名不符无法执行
public class Test {
	public native static String getStringFromC();
	
	public static void main(String[] args) {
		System.out.println("Hello world!");
		String text = getStringFromC();
		System.out.println(text);
	}
	
	static {
		System.loadLibrary("jni_study");
	}
}
