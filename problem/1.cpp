#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <cstring>
#include <iostream>
#pragma comment(lib, "WINMM.LIB")
using namespace std;
string a =
    "3."
    "14159265358979323846264338327950288419716939937510582097494459230781640628"
    "62089986280348253421170679821480865132823066470938446095505822317253594081"
    "28481117450284102701938521105559644622948954930381964428810975665933446128"
    "47564823378678316527120190914564856692346034861045432664821339360726024914"
    "12737245870066063155881748815209209628292540917153643678925903600113305305"
    "48820466521384146951941511609433057270365759591953092186117381932611793105"
    "11854807446237996274956735188575272489122793818301194912983367336244065664"
    "30860213949463952247371907021798609437027705392171762931767523846748184676"
    "69405132000568127145263560827785771342757789609173637178721468440901224953"
    "430146549585371050792279689258923542019956112129021960"
    "86403441815981362977477130996051870721134999999837297804995105973173281609"
    "63185950244594553469083026425223082533446850352619311881710100031378387528"
    "86587533208381420617177669147303598253490428755468731159562863882353787593"
    "7519577818577805321712268066130019278766111959092164201989";
void SetFont(int size = 100) {     // hello imX2G
    CONSOLE_FONT_INFOEX cfi;       // hello imX2G
    cfi.cbSize = sizeof cfi;       // hello imX2G
    cfi.nFont = 0;                 // hello imX2G
    cfi.dwFontSize.X = 0;          // hello imX2G
    cfi.dwFontSize.Y = size;       //���������С
    cfi.FontFamily = FF_DONTCARE;  // hello imX2G
    cfi.FontWeight = FW_BOLD;      //�����ϸ FW_BOLDFW_NORMAL
    // wcscpy_s(cfi.FaceName, L"����");  //�������壬�����ǿ���̨���е�
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE,
                            &cfi);                              // hello imX2G
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);            // hello imX2G
    CONSOLE_FONT_INFO consoleCurrentFont;                       // hello imX2G
    GetCurrentConsoleFont(handle, FALSE, &consoleCurrentFont);  // hello imX2G
}  // hello imX2G
int main() {
    string s;
    SetFont();

    while (1) {
        cout << "������Բ���ʣ�";
        cin >> s;
        char userkey[2048] = {"Բ������ȷλ����С�����"};
        for (int i = 0; i < 1000; i++) {
            if (s[i] != a[i]) {
                cout << "Բ������ȷλ����С�����" << i - 2 << "λ" << endl
                     << endl;
                string tmp = to_string(i - 2);
                tmp += "λ";
                for (int i = 0, j = strlen(userkey); i < tmp.length();
                     i++, j++) {
                    userkey[j] = tmp[i];
                }
                break;
            }
        }
        // cout << userkey << endl;
        FILE* fp = fopen("speak.vbs", "w");  //�Զ��ķ�ʽ���ļ�
        // c��������Щ�ַ���û�а취��ӡ������
        //����/+�����ַ��ķ�ʽ����ת��
        fprintf(fp, "CreateObject(\"SAPI.Spvoice\").speak(\"%s\")", userkey);
        fclose(fp);
        system("speak.vbs");  //���нű�������Ҫ�ʶ����ݼ��ɽ����ʶ�
        system("del speak.vbs");  //���й���ɾ�������ļ�
        printf("---�������������������,����ֱ�ӹرռ���---\n");
        while (!kbhit()) {
        }
        system("cls");
    }
}