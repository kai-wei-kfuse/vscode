#include<stdio.h>
#include <Windows.h>
#include <mmsystem.h>	
#pragma comment(lib,"WinMM.Lib")
 
int main() {
	mciSendString(TEXT("open 03.wav"), NULL, 0, NULL);
	mciSendString(TEXT("play 03.wav"), NULL, 0, NULL);
	getchar();
    return 0;
}