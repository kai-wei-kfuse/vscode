#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
//�ʶ�����

int main() {

	while(1){ //�������
            char userkey[1024] ="";
                cout << "������Ҫ�ʶ������ݣ�";
		gets(userkey);
                
                FILE* fp = fopen("speak.vbs", "w");  //�Զ��ķ�ʽ���ļ�
		//c��������Щ�ַ���û�а취��ӡ������
		//����/+�����ַ��ķ�ʽ����ת��
		fprintf(fp, "CreateObject(\"SAPI.Spvoice\").speak(\"%s\")", userkey);
		fclose(fp);
		system("speak.vbs"); //���нű�������Ҫ�ʶ����ݼ��ɽ����ʶ�
		system("del speak.vbs"); //���й���ɾ�������ļ�
        getchar();
        getchar();
        }

	return 0;
}

