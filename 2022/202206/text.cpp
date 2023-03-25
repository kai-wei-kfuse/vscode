#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
//朗读工具

int main() {

	while(1){ //多次输入
            char userkey[1024] ="";
                cout << "请输入要朗读的内容：";
		gets(userkey);
                
                FILE* fp = fopen("speak.vbs", "w");  //以读的方式打开文件
		//c语言中有些字符是没有办法打印出来的
		//采用/+特殊字符的方式进行转义
		fprintf(fp, "CreateObject(\"SAPI.Spvoice\").speak(\"%s\")", userkey);
		fclose(fp);
		system("speak.vbs"); //运行脚本，输入要朗读内容即可进行朗读
		system("del speak.vbs"); //运行过后删除生成文件
        getchar();
        getchar();
        }

	return 0;
}

