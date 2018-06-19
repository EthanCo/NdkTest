#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

//��ȡ�ı��ļ�
void method1(){
	char path[] = "F:\\VersionManager\\WorkSpace\\NDK\\08_08_C_05_2_io\\files\\friends.txt"; // б����Ҫ���\\ת��
	//��
	FILE *fp = fopen(path, "r");
	if (fp == NULL)
	{
		printf("�ļ���ʧ��.....");
		getchar();
		return;
	}
	//��ȡ
	char buff[50]; //����
	while (fgets(buff, 50, fp))
	{
		printf("%s", buff);
	}
	//�ر�
	fclose(fp);

	getchar();
}

//д���ı��ļ�
void method2(){
	char path[] = "F:\\VersionManager\\WorkSpace\\NDK\\08_08_C_05_2_io\\files\\friends_new.txt";
	//��
	FILE *fp = fopen(path, "w");
	char *text = "Hello World ! ";
	fputs(text, fp);

	//�ر���
	fclose(fp);
	getchar();
}

/*
�������ļ�
��������ļ��洢�������϶��Ƕ�����
�ı��ļ��Ͷ����Ƶ�֮�֣���ʵ��һ���߼�֮��
C��д�ı��ļ���������ļ��Ĳ����������ڻس����з�
д�ı�ʱ��ÿ����һ��'\n'���ͻὫ��ת��Ϊ'\r\n'(�س�����)
*/
//�ļ�����
void method3(){
	char* read_path = "F:\\VersionManager\\WorkSpace\\NDK\\08_08_C_05_2_io\\files\\liuyan.png";
	char* write_path = "F:\\VersionManager\\WorkSpace\\NDK\\08_08_C_05_2_io\\files\\liuyan_new.png";

	//char* read_path = "F:\\VersionManager\\WorkSpace\\NDK\\08_08_C_05_2_io\\files\\LogViewPro.exe";
	//char* write_path = "F:\\VersionManager\\WorkSpace\\NDK\\08_08_C_05_2_io\\files\\LogViewPro_new.exe";
	//�����ļ���b�ַ���ʾ�����������ļ�binary
	FILE* read_fp = fopen(read_path, "rb");
	//д�ļ�
	FILE* write_fp = fopen(write_path, "wb");
	//����
	int buff[50]; //��������
	int len = 0; //ÿ�ζ�ȡ�����ݳ���
	while ((len=fread(buff,sizeof(int),50,read_fp))!=0){ //һ�ζ�ȡ50���ֽڣ���λ��С4�ֽ�(int)
		//������������д���µ��ļ�
		fwrite(buff, sizeof(int), len, write_fp);
	}
	fclose(read_fp);
	fclose(write_fp);
	getchar();
}

/*
��ȡ�ļ��Ĵ�С ? 
*/
void method4(){
	char *read_path = "F:\\VersionManager\\WorkSpace\\NDK\\08_08_C_05_2_io\\files\\liuyan.png";
	FILE *fp = fopen(read_path, "r");
	//���¶�λ�ļ�ָ��
	//SEEK_END�ļ�ĩβ��0ƫ����
	fseek(fp, 0, SEEK_END); //�൱��Java��ReadAccessFile
	//���ص�ǰ���ļ�ָ�룬������ļ���ͷ��λ����
	long filesize = ftell(fp);
	printf("%d\n", filesize);

	getchar();
}

/*
��ϰ:�ı��ļ��ӽ���

���: ��ͬΪ0����ͬΪ1
*/
//����
void crpypt(char* normal_path[], char* crypt_path[]){
	//���ļ�
	FILE *normal_fp = fopen(normal_path, "r");
	FILE *crypt_fp = fopen(crypt_path, "w");
	//һ�ζ�ȡһ���ַ�
	int ch;
	while ((ch = fgetc(normal_fp)) != EOF) //End of File
	{
		//д��(�������)
		fputc(ch ^ 9, crypt_fp);
	}

	//�ر�
	fclose(normal_fp);
	fclose(crypt_fp);
}

//����
void decrpypt(char crypt_path[], char decrypt_path[]){
	//���ļ�
	FILE *normal_fp = fopen(crypt_path, "r");
	FILE *crypt_fp = fopen(decrypt_path, "w");
	//һ�ζ�ȡһ���ַ�
	int ch;
	while ((ch = fgetc(normal_fp)) != EOF){ //End of File
		//д�루������㣩
		fputc(ch ^ 9, crypt_fp);
	}
	//�ر�
	fclose(crypt_fp);
	fclose(normal_fp);

}

void method5(){
	char *normal_path = "F:\\VersionManager\\WorkSpace\\NDK\\08_08_C_05_2_io\\files\\friends.txt";
	char *crypt_path = "F:\\VersionManager\\WorkSpace\\NDK\\08_08_C_05_2_io\\files\\friends_crpypt.txt";
	char *decode_path = "F:\\VersionManager\\WorkSpace\\NDK\\08_08_C_05_2_io\\files\\friends_decode.txt";
	//����
	//crpypt(normal_path, crypt_path);
	//����
	decrpypt(crypt_path, decode_path);

	getchar();
}

//�������ļ��ӽ���
//��ȡ�������ļ��е�����ʱ��һ��һ���ַ���ȡ
//���룺ilovely
void crpypt_2(char normal_path[], char crypt_path[], char password[]){
	//���ļ�
	FILE *normal_fp = fopen(normal_path, "rb");
	FILE *crypt_fp = fopen(crypt_path, "wb");
	//һ�ζ�ȡһ���ַ�
	int ch;
	int i = 0; //ѭ��ʹ�������е���ĸ�����������
	int pwd_len = strlen(password); //����ĳ���
	while ((ch = fgetc(normal_fp)) != EOF){ //End of File
		//д�루������㣩
		fputc(ch ^ password[i % pwd_len], crypt_fp);
		i++;
	}
	//�ر�
	fclose(crypt_fp);
	fclose(normal_fp);
}

//����
void decrpypt_2(char crypt_path[], char decrypt_path[], char password[]){
	//���ļ�
	FILE *normal_fp = fopen(crypt_path, "rb");
	FILE *crypt_fp = fopen(decrypt_path, "wb");
	//һ�ζ�ȡһ���ַ�
	int ch;
	int i = 0; //ѭ��ʹ�������е���ĸ�����������
	int pwd_len = strlen(password); //����ĳ���
	while ((ch = fgetc(normal_fp)) != EOF){ //End of File
		//д�루������㣩
		fputc(ch ^ password[i % pwd_len], crypt_fp);
		i++;
	}
	//�ر�
	fclose(crypt_fp);
	fclose(normal_fp);
}

void method6(){
	char *normal_path = "F:\\VersionManager\\WorkSpace\\NDK\\08_08_C_05_2_io\\files\\liuyan.png";
	char *crypt_path = "F:\\VersionManager\\WorkSpace\\NDK\\08_08_C_05_2_io\\files\\liuyan_crypt.png";
	char *decode_path = "F:\\VersionManager\\WorkSpace\\NDK\\08_08_C_05_2_io\\files\\liuyan_decode.png";
	//����
	//crpypt_2(normal_path, crypt_path,"iloveqq");
	//����
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
