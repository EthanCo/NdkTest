#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

//读取文本文件
void method1(){
	char path[] = "F:\\VersionManager\\WorkSpace\\NDK\\08_08_C_05_2_io\\files\\friends.txt"; // 斜杠需要变成\\转义
	//打开
	FILE *fp = fopen(path, "r");
	if (fp == NULL)
	{
		printf("文件打开失败.....");
		getchar();
		return;
	}
	//读取
	char buff[50]; //缓存
	while (fgets(buff, 50, fp))
	{
		printf("%s", buff);
	}
	//关闭
	fclose(fp);

	getchar();
}

//写入文本文件
void method2(){
	char path[] = "F:\\VersionManager\\WorkSpace\\NDK\\08_08_C_05_2_io\\files\\friends_new.txt";
	//打开
	FILE *fp = fopen(path, "w");
	char *text = "Hello World ! ";
	fputs(text, fp);

	//关闭流
	fclose(fp);
	getchar();
}

/*
二进制文件
计算机的文件存储在物理上都是二进制
文本文件和二进制的之分，其实是一个逻辑之分
C读写文本文件与二进制文件的差别仅仅体现在回车换行符
写文本时，每遇到一个'\n'，就会将其转换为'\r\n'(回车换行)
*/
//文件复制
void method3(){
	char* read_path = "F:\\VersionManager\\WorkSpace\\NDK\\08_08_C_05_2_io\\files\\liuyan.png";
	char* write_path = "F:\\VersionManager\\WorkSpace\\NDK\\08_08_C_05_2_io\\files\\liuyan_new.png";

	//char* read_path = "F:\\VersionManager\\WorkSpace\\NDK\\08_08_C_05_2_io\\files\\LogViewPro.exe";
	//char* write_path = "F:\\VersionManager\\WorkSpace\\NDK\\08_08_C_05_2_io\\files\\LogViewPro_new.exe";
	//读的文件，b字符表示操作二进制文件binary
	FILE* read_fp = fopen(read_path, "rb");
	//写文件
	FILE* write_fp = fopen(write_path, "wb");
	//复制
	int buff[50]; //缓冲区域
	int len = 0; //每次读取的数据长度
	while ((len=fread(buff,sizeof(int),50,read_fp))!=0){ //一次读取50个字节，单位大小4字节(int)
		//将读到的内容写入新的文件
		fwrite(buff, sizeof(int), len, write_fp);
	}
	fclose(read_fp);
	fclose(write_fp);
	getchar();
}

/*
获取文件的大小 ? 
*/
void method4(){
	char *read_path = "F:\\VersionManager\\WorkSpace\\NDK\\08_08_C_05_2_io\\files\\liuyan.png";
	FILE *fp = fopen(read_path, "r");
	//重新定位文件指针
	//SEEK_END文件末尾，0偏移量
	fseek(fp, 0, SEEK_END); //相当于Java的ReadAccessFile
	//返回当前的文件指针，相对于文件开头的位移量
	long filesize = ftell(fp);
	printf("%d\n", filesize);

	getchar();
}

/*
练习:文本文件加解密

异或: 相同为0，不同为1
*/
//加密
void crpypt(char* normal_path[], char* crypt_path[]){
	//打开文件
	FILE *normal_fp = fopen(normal_path, "r");
	FILE *crypt_fp = fopen(crypt_path, "w");
	//一次读取一个字符
	int ch;
	while ((ch = fgetc(normal_fp)) != EOF) //End of File
	{
		//写入(异或运算)
		fputc(ch ^ 9, crypt_fp);
	}

	//关闭
	fclose(normal_fp);
	fclose(crypt_fp);
}

//解密
void decrpypt(char crypt_path[], char decrypt_path[]){
	//打开文件
	FILE *normal_fp = fopen(crypt_path, "r");
	FILE *crypt_fp = fopen(decrypt_path, "w");
	//一次读取一个字符
	int ch;
	while ((ch = fgetc(normal_fp)) != EOF){ //End of File
		//写入（异或运算）
		fputc(ch ^ 9, crypt_fp);
	}
	//关闭
	fclose(crypt_fp);
	fclose(normal_fp);

}

void method5(){
	char *normal_path = "F:\\VersionManager\\WorkSpace\\NDK\\08_08_C_05_2_io\\files\\friends.txt";
	char *crypt_path = "F:\\VersionManager\\WorkSpace\\NDK\\08_08_C_05_2_io\\files\\friends_crpypt.txt";
	char *decode_path = "F:\\VersionManager\\WorkSpace\\NDK\\08_08_C_05_2_io\\files\\friends_decode.txt";
	//加密
	//crpypt(normal_path, crypt_path);
	//解密
	decrpypt(crypt_path, decode_path);

	getchar();
}

//二进制文件加解密
//读取二进制文件中的数据时，一个一个字符读取
//密码：ilovely
void crpypt_2(char normal_path[], char crypt_path[], char password[]){
	//打开文件
	FILE *normal_fp = fopen(normal_path, "rb");
	FILE *crypt_fp = fopen(crypt_path, "wb");
	//一次读取一个字符
	int ch;
	int i = 0; //循环使用密码中的字母进行异或运算
	int pwd_len = strlen(password); //密码的长度
	while ((ch = fgetc(normal_fp)) != EOF){ //End of File
		//写入（异或运算）
		fputc(ch ^ password[i % pwd_len], crypt_fp);
		i++;
	}
	//关闭
	fclose(crypt_fp);
	fclose(normal_fp);
}

//解密
void decrpypt_2(char crypt_path[], char decrypt_path[], char password[]){
	//打开文件
	FILE *normal_fp = fopen(crypt_path, "rb");
	FILE *crypt_fp = fopen(decrypt_path, "wb");
	//一次读取一个字符
	int ch;
	int i = 0; //循环使用密码中的字母进行异或运算
	int pwd_len = strlen(password); //密码的长度
	while ((ch = fgetc(normal_fp)) != EOF){ //End of File
		//写入（异或运算）
		fputc(ch ^ password[i % pwd_len], crypt_fp);
		i++;
	}
	//关闭
	fclose(crypt_fp);
	fclose(normal_fp);
}

void method6(){
	char *normal_path = "F:\\VersionManager\\WorkSpace\\NDK\\08_08_C_05_2_io\\files\\liuyan.png";
	char *crypt_path = "F:\\VersionManager\\WorkSpace\\NDK\\08_08_C_05_2_io\\files\\liuyan_crypt.png";
	char *decode_path = "F:\\VersionManager\\WorkSpace\\NDK\\08_08_C_05_2_io\\files\\liuyan_decode.png";
	//加密
	//crpypt_2(normal_path, crypt_path,"iloveqq");
	//解密
	decrpypt_2(crypt_path, decode_path, "iloveqq");

	getchar();
}

void main(){
	//method1();
	//method2();
	//method3();
	//method4();
	//method5();
	method6();
}
