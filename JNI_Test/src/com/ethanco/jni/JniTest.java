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
	
	//�������ԣ������޸�֮�������
	public native String accessField();
	
	//���ʾ�̬����
	public native void accessStaticField();
	
	//���ʷ���
	public native void accessMethod();
	
	//���ʾ�̬����
	public native void accessStaticMethod();
	
	//���ʹ��췽��
	public native Date accessConstructor();
	
	//���ʸ��෽��
	public native void accessNonvirtualMethod();
	
	//�������ģ���������
	public native String chineseChars(String in);
	
	//�������� (��һ�����������������)
	public native void giveArray(int[] array);
	
	//�������� (����һ������)
	public native int[] getArray(int len);
	
	//�ֲ����� �ͷŶ���
	public native void localRef();
	
	//����ȫ������
	public native void createGlobalRef();
	
	//��ȡȫ������
	public native String getGlobalRef();
	
	//�ͷ�ȫ�ֱ���
	public native void deleteGlobalRef();
	
	//�쳣����
	public native void exeception();
	
	//�������
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
		System.out.println("�޸�ǰkey:"+jniTest.key);
		System.out.println(jniTest.accessField());
		System.out.println("�޸ĺ�key:"+jniTest.key);
		
		System.out.println("�޸�ǰcount:"+count);
		jniTest.accessStaticField();
		System.out.println("�޸ĺ�count:"+count);
		
		jniTest.accessMethod();
		
		jniTest.accessStaticMethod();
		
		jniTest.accessConstructor();
		
		jniTest.accessNonvirtualMethod();
		
		String result = jniTest.chineseChars("123abc�ν�");
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
		//����֮���ͷ�
		jniTest.deleteGlobalRef();
		//System.out.println("�ͷ���֮��:"+jniTest.getGlobalRef());
		
		try {
			jniTest.exeception();
		} catch(Exception e) {
			System.out.println("�����쳣:"+e.getMessage());
		}
		
		System.out.println("---------�쳣������--------");
		
		try {
			jniTest.exeception();
		}catch(Exception e) {
			System.out.println(e.getMessage());
		}
		
		//���ϵ���cached����
		for(int i=0;i<100;i++) {
			jniTest.cached();
		}
	}
	
	//����ָ����Χ�������
	public int getRandomInt(int max) {
		System.out.println("getRandomInt max:"+max);
		return new Random().nextInt(max);
	}
	
	//��ȡһ��UUID
	public static String getUUID() {
		return UUID.randomUUID().toString();
	}
	
	static {
		System.loadLibrary("jni_study");
		initIds();
	}
}
