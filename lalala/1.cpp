#include <iostream>
#include <windows.h>
#include <Mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;

int main() {
	MCI_OPEN_PARMS open;
	open.lpstrDeviceType = NULL;
	open.lpstrElementName = L"D:\\C.mp3"; //�����������ļ���λ��
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT, (DWORD)&open); //���豸
	UINT wdd;
	MCI_PLAY_PARMS play;
	play.dwFrom = 1000;//ָ����ʼ���ŵ�λ�ã���λms
	wdd = open.wDeviceID;//wdd�����豸id
	mciSendCommand(wdd, MCI_PLAY, MCI_WAIT, (DWORD)&play);
	system ("pause");
	return;
}