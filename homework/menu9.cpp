#define _CRT_SECURE_NO_WARNINGS 1
/* -------------------------------------------------------------------
                   中年人学C语言Windows程序设计
--------------------------------------------------------------------*/

#include <windows.h>
#include<strsafe.h>
#include"sysmets.h"
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
//主函数
// 四个参数：
//hInstance : 程序当前实例的句柄(handle to current instance)，以后随时可以用GetModuleHandle(0)来获得
//hPrevInstance : 前一个实例的句柄(handle to previous instance)，在Win32中，每一个进程都有一个独立的4G地址空间，从0到2G属于进程私有，对其他进程来说是不可见的。所以，在Win32中，hPrevInstance总是为NULL。
//szCmdLine : 指向以 / 0结尾的命令行，不包括EXE本身的文件名(pointer to command line)，以后随时可以用GetCommandLine()来获取完整的命令行。
//iCmdShow : 指明应该以什么方式显示主窗口(show state of window)。

{
    static TCHAR szAppName[] = TEXT("MyWindows");
    HWND hwnd;//句柄
    MSG msg;//消息
    WNDCLASS wndclass;//定义窗口类结构
    HBRUSH hCulorBrush = CreateSolidBrush(RGB(200, 200, 200));//设定背景颜色

    //结构成员：
    wndclass.style = CS_HREDRAW | CS_VREDRAW; //窗口类型
    wndclass.lpfnWndProc = WndProc;  //窗口过程（必须是回调函数）
    wndclass.cbClsExtra = 0;//预留的额外空间，一般为0
    wndclass.cbWndExtra = 0;//预留的额外空间，一般为0
    wndclass.hInstance = hInstance;//应用程序的实例句柄
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);//为所有基于该窗口类的窗口设定一个图标
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);//为所有基于该窗口类的窗口设定一个鼠标指针
    //wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);//指定窗口背景色
    wndclass.hbrBackground = hCulorBrush;//指定窗口背景色
    wndclass.lpszMenuName = NULL; //指定窗口菜单
    wndclass.lpszClassName = szAppName; //指定窗口类名

    //注册窗口类
    if (!RegisterClass(&wndclass))
        /*  RegisterClass：注册在随后调用CreateWindow函数和CreateWindowEx函数中使用的窗口类。
          参数为lpWndClass，指向一个WNDCLASS结构的指针
          返回值：ATOM的宏定义
          typedef WORD ATOM;
          typedef unsigned short WORD;
          关于RegisterClassEx:参数lpwcx指向一个WNDCLASSEX结构的指针如果函数成功，返回这个窗口类型的标识号；
          如果函数失败，返回值为0。若想获得更多错误信息，请调用GetLastError函数。*/
    {
        MessageBox(NULL, TEXT("这个程序需要在Windows系统下运行！"), szAppName, MB_ICONERROR);
        return 0;
    }
    //实例化创建窗口
    hwnd = CreateWindow(szAppName,// 窗口类名称
        TEXT("中年人学C语言Windows程序设计"),// 窗口标题
        WS_OVERLAPPEDWINDOW | WS_VSCROLL,// 窗口风格，或称窗口格式
        CW_USEDEFAULT,// 初始 x 坐标
        CW_USEDEFAULT, // 初始 y 坐标
        CW_USEDEFAULT,// 初始 x 方向尺寸
        CW_USEDEFAULT,// 初始 y 方向尺寸
        NULL,// 父窗口句柄
        NULL,// 窗口菜单句柄
        hInstance,// 程序实例句柄
        NULL);// 创建参数

    /*_In_说明该参数是输入的，_opt_说明该参数是可选参数
        函数成功返回窗口句柄，否则返回NULL*/

        //显示窗口
    ShowWindow(hwnd, iCmdShow);
    /* 第一次调用时应使用WinMain的参数nCmdShow作为参数
         如果窗口之前可见，则返回非0否则返回0*/

         //更新窗口
    UpdateWindow(hwnd);
    /* 绕过消息队列直接向窗口过程发送WM_PAINT消息
         函数调用成功返回非0*/

         //消息循环
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    /*作用：从当前线程的消息队列里取出一个消息并放入MSG结构中，不能获得其他线程的消息
        若消息队列为空，函数会一直等待到有消息到来才有返回值
        返回值：
        函数出现错误则返回 - 1，
        获得WM_QUIT消息返回0
        否则返回非0*/

    return msg.wParam;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    回调函数
    参数：
    hwnd : 窗口句柄
    message : 消息ID
    wParam和lParam：消息参数
        //int i;
        //size_t j;
    TCHAR strBuffer[100];
    TEXTMETRIC tm;
    SCROLLINFO si;
    PAINTSTRUCT ps;
    size_t iLength;
    static int cxChar, cyChar, yVscrollPos, cxClient, cyClient, yPage, cxCaps, FirstLine, LastLine;

    switch (message)
    {

    case WM_CREATE:  // 获得字体的大小、高度、宽度等信息
    {
        HDC hdc;
        hdc = GetDC(hWnd);
        GetTextMetrics(hdc, &tm);
        cxChar = tm.tmAveCharWidth;//获得字体宽度
        cyChar = tm.tmHeight + tm.tmExternalLeading;//获得字体高度
        cxCaps = (tm.tmPitchAndFamily & 1 ? 3 : 2) * cxChar / 2;//获取大写字符宽度
        ReleaseDC(hWnd, hdc);
        return 0;
    }
    case WM_SIZE://窗体大小改变
    {
        cxClient = LOWORD(lParam);//宽度
        cyClient = HIWORD(lParam);//高度
        yPage = cyClient / cyChar;    // y表示一页里有多少行
        //yPage = 20;    // 每页显示20g个
        si.cbSize = sizeof(SCROLLINFO);   // 以下为设置滚动条1. 该结构的大小（以字节为单位）
                                                           //2. 通常使用 sizeof(SCROLLINFO) 获得
        si.fMask = SIF_ALL;// SIF_ALL相当于 SIF_PAGE | SIF_POS | SIF_RANGE | SIF_TRACKPOS
        //si.fMask = SIF_RANGE | SIF_PAGE;
        si.nMin = 0;//滚动条范围的最小值
        si.nMax = NUMLINES - 1;//滚动条范围的最大值
        si.nPage = yPage; //页面的大小，滚动条通过这个值来动态确定滑块的大小
        SetScrollInfo(hWnd, SB_VERT, &si, TRUE);
        //函数用于设置滚动条的参数，其中包括：滚动范围的最小值和最大值，
        //页面的大小，以及滑块的位置。如果需要，该函数还可以重绘滚动条。

        return 0;
    }
    case WM_PAINT:
    {

        HDC hdc = BeginPaint(hWnd, &ps);
        si.cbSize = sizeof(si);    // 以下获得滚动条信息
        si.fMask = SIF_POS;

        //获取当前滚动条位置，
        GetScrollInfo(hWnd, SB_VERT, &si);
        yVscrollPos = si.nPos;

        //获得重绘的区域信息
        FirstLine = max(0, yVscrollPos + ps.rcPaint.top / cyChar);//绘制区第一行
        LastLine = min(NUMLINES - 1, yVscrollPos + ps.rcPaint.bottom / cyChar);//绘制区尾行

        //开始绘制文字
        int xText, yText;
        for (xText = FirstLine; xText <= LastLine; xText++)
        {
            yText = cyChar * (xText - yVscrollPos);//计算绘制文字的  y轴 坐标数值
            SetTextAlign(hdc, TA_LEFT | TA_TOP);
            StringCchLength(sysmetrics[xText].szLabel, 128, &iLength);
            TextOut(hdc, 10 + cxChar, yText, sysmetrics[xText].szLabel, iLength);
            StringCchLength(sysmetrics[xText].szDesc, 128, &iLength);
            TextOut(hdc, 10 + cxChar + 20 * cxCaps, yText, sysmetrics[xText].szDesc, iLength);
            StringCchPrintf(strBuffer, 128, TEXT("%d"), GetSystemMetrics(sysmetrics[xText].iIndex));
            StringCchLength(strBuffer, 128, &iLength);
            SetTextAlign(hdc, TA_RIGHT | TA_TOP);
            TextOut(hdc, 10 + cxChar + 60 * cxCaps, yText, strBuffer, iLength);
        }
        EndPaint(hWnd, &ps);
        return 0;
    }

    case WM_VSCROLL://滚动条动作事件
    {
        si.cbSize = sizeof(si);
        si.fMask = SIF_ALL;
        GetScrollInfo(hWnd, SB_VERT, &si);
        yVscrollPos = si.nPos;//获取当前滚动条位置
        switch (LOWORD(wParam))
        {
        case SB_LINEDOWN://滚动条向下一行
            si.nPos += 1;
            break;
        case SB_LINEUP://滚动条向上一行
            si.nPos -= 1;
            break;
        case SB_PAGEDOWN://滚动条向下一页
            si.nPos += yPage;
            break;
        case SB_PAGEUP://滚动条向上一页
            si.nPos -= yPage;
            break;
        case SB_THUMBTRACK://拖动滚动条
            si.nPos = si.nTrackPos;
            break;
        case SB_TOP://滚动条 置顶
            si.nPos = si.nMin;
            break;
        case SB_BOTTOM://滚动条 置底
            si.nPos = si.nMax;
            break;
        }
        si.nPos = min(NUMLINES - yPage, max(0, si.nPos));//限定滚动条位置的最小最大值
        si.fMask = SIF_POS;
        SetScrollInfo(hWnd, SB_VERT, &si, TRUE);//重新设置滚动条
        GetScrollInfo(hWnd, SB_VERT, &si);//取得设置滚动条

        if (yVscrollPos != si.nPos)//如果如果不相等，说明滚动条移动就进行重绘
        {
            ScrollWindow(hWnd, 0, cyChar * (yVscrollPos - si.nPos), NULL, NULL);//函数滚动指定窗口的客户区内容
            UpdateWindow(hWnd);//重绘用户区窗口，系统会调用WM_PAINT,重绘用户区
        }
        return 0;
    }
    case WM_KEYDOWN://相应键盘消息
        switch (wParam)
        {
        case VK_DOWN://按下 下 按键
            SendMessage(hWnd, WM_VSCROLL, SB_LINEDOWN, 0);
            break;
        case VK_UP://按下 上 按键
            SendMessage(hWnd, WM_VSCROLL, SB_LINEUP, 0);
            break;
        case VK_PRIOR://按下 pageup 按键
            SendMessage(hWnd, WM_VSCROLL, SB_PAGEUP, 0);
            break;
        case VK_NEXT://按下 pagedown 按键
            SendMessage(hWnd, WM_VSCROLL, SB_PAGEDOWN, 0);
            break;
        case VK_HOME://按下 home 按键
            SendMessage(hWnd, WM_VSCROLL, SB_TOP, 0);
            break;
        case VK_END://按下 end 按键
            SendMessage(hWnd, WM_VSCROLL, SB_BOTTOM, 0);
            break;
        }
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

