#include <iostream>
#include <windows.h>
#include <Mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;

int main() {
	MCI_OPEN_PARMS open;
	open.lpstrDeviceType = NULL;
	open.lpstrElementName = L"D:\\C.mp3"; //这里是音乐文件的位置
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT, (DWORD)&open); //打开设备
	UINT wdd;
	MCI_PLAY_PARMS play;
	play.dwFrom = 1000;//指定开始播放的位置，单位ms
	wdd = open.wDeviceID;//wdd储存设备id
	mciSendCommand(wdd, MCI_PLAY, MCI_WAIT, (DWORD)&play);
	system ("pause");
	return;
}