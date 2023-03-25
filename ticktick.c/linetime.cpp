//软件名称：经典时钟
//文件名：main.cpp
//版本：2020.02.15
//软件说明：本程序是嵌入式经典时钟，你可以把这个代码嵌入到任何图形界面程序项目中，
//			你只修改时钟输出位置和大小就可以在任何窗口程序中直接调用。
//作者：A贝尔（Abr）
//时间：2020年02月15日20：55分

#define _CRT_SECURE_NO_WARNINGS//跳过安全检查
#include <conio.h>//getch()函数头
#include <graphics.h>//图形库头文件
#include <math.h>//数学运算公式头
#include <time.h>//时间头

#define PI 3.1415926535898//π约等于3.1415926535898			这个项目对精度的要求非常高
#define ONERAND PI/180//一度等于ONERAND弧度


//**************函数成名**************//
int timess();//生成钟表
int setkey();//生成开关
int keymsg();//检测那一键被点击
int setp(int ts,int tm,int th);//画表针
int nsetp(int ts, int tm, int th);//删除表针
int Interface();//打印界面
int mainmsg(int id);//消息处理


//*******全局变量声明********//

//钟表打印坐标和半径
int x = 150, y = 200, r = 100;

//保存开关对象的结构体变量
struct skey
{
	int rx;//开关左定点x坐标
	int ry;//开关左定点y坐标
	int lenx;//开关长度
	int leny;//开关宽度
	wchar_t name[20];//开关标题
	COLORREF keyfillcolor;//开关填充颜色
	COLORREF keylinecolor;//开关边框颜色
	COLORREF keytextlcolor;//开关字体颜色
	unsigned int linestyle;
}skeys[19];

//线程列表结构体变量
struct Thread
{
	HANDLE handle = NULL;//线程列表
	char name[10] = { '\0' };//线程名
	bool nots = FALSE;
}Threads[10];

//默认色值
COLORREF bkcolor   = WHITE;//默认背景颜色
COLORREF fillcolor = BLACK;//默认填充颜色
COLORREF linecolor = BLACK;//默认边框颜色


//主函数
int main()
{
	initgraph(640, 480);//初始化窗口，尺寸制定窗口
	Interface();		//打印界面函数
	Threads[1].handle = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)keymsg, NULL, NULL, NULL);//创建一个线程并运行 keymsg()函数（检测那一键被点击函数）,存储线程 handle
	strcpy(Threads[1].name, "Hkeymsg");//线程名称
	Threads[1].nots = TRUE;//线程运行标识符
	while (true);//一直等待线程
	return 0;
}


//画表针
int setp(int ts, int tm, int th)
{
	//画秒针
	setlinecolor(BLUE);
	setlinestyle(PS_SOLID, 2);
	double xl = r * cos((ts - 15) * ONERAND * 6);
	double yl = r * sin((ts - 15) * ONERAND * 6);
	line(x, y, (int)xl + x, (int)yl + y);

	//画分针
	setlinecolor(RED);
	setlinestyle(PS_SOLID, 3);
	double xlm = r * 2 / 3 * cos((tm - 15) * ONERAND * 6);
	double ylm = r * 2 / 3 * sin((tm - 15) * ONERAND * 6);
	line(x, y, (int)xlm + x, (int)ylm + y);

	//画时针
	setlinecolor(LIGHTRED);
	setlinestyle(PS_SOLID, 4);
	double xlh = r * 2 / 5 * cos((th - 3) * ONERAND * 30);
	double ylh = r * 2 / 5 * sin((th - 3) * ONERAND * 30);
	line(x, y, (int)xlh + x, (int)ylh + y);

	//画中间节点
	setfillcolor(BLUE);
	solidcircle(x, y, 5);

	return 0;
}

//删除表针
int nsetp(int ts, int tm, int th)
{
	setlinecolor(bkcolor);//用背景色覆盖表针
	//删除秒针
	setlinestyle(PS_SOLID, 2);
	double xl = r * cos((ts - 15) * ONERAND * 6);
	double yl = r * sin((ts - 15) * ONERAND * 6);
	line(x, y, (int)xl + x, (int)yl + y);

	//删除分针
	setlinestyle(PS_SOLID, 3);
	double xlm = r * 2 / 3 * cos((tm - 15) * ONERAND * 6);
	double ylm = r * 2 / 3 * sin((tm - 15) * ONERAND * 6);
	line(x, y, (int)xlm + x, (int)ylm + y);

	//删除时针
	setlinestyle(PS_SOLID, 4);
	double xlh = r * 2 / 5 * cos((th - 3) * ONERAND * 30);
	double ylh = r * 2 / 5 * sin((th - 3) * ONERAND * 30);
	line(x, y, (int)xlh + x, (int)ylh + y);

	//删除画中间节点
	setfillcolor(bkcolor);
	solidcircle(x, y, 5);
	return 0;
}

//检测那一键被点击
int keymsg()
{
	MOUSEMSG ms;//存储鼠标消息的结构体
	while (true)//消息循环
	{
		if (MouseHit())//检测鼠标消息
		{
			ms = GetMouseMsg();//获取鼠标消息
			if (ms.mkLButton)//判断鼠标左键是否被按下
			{
				int x, y;
				x = ms.x,y = ms.y;//赋值鼠标坐标

				for (int id = 0; skeys[id].lenx != 0; id++)//循环到案件长度等于0为止
				{	
					//根据按键的左上方坐标和右下方坐标来判断鼠标按下的模拟键
					if ((skeys[id].rx < x && (skeys[id].rx + skeys[id].lenx) > x) && (skeys[id].ry < y && (skeys[id].ry + skeys[id].leny) > y))
					{

						mainmsg(id);//消息处理函数 根据开关的 id 处理相应事件
	
						FlushMouseMsgBuffer();// 清空鼠标消息缓冲区
						x = 0,y = 0;		  // 删除干扰
						memset(&ms, NULL, sizeof(ms));//清空存储鼠标消息结构体内容
						break;				  // 跳出循环 已找到那一件被按下没必要循环下去
					}
				}
			}
		}
	}
	return 0;
}

//生成开关函数
int setkey()//开关控制函数
{
	memset(skeys, NULL, sizeof(skeys));
	//在这里添加按键，给按键对象的属性赋值
	skeys[0] = { 0, 0, 50, 30,_T("开始") ,LIGHTGRAY,BLACK,MAGENTA ,1};
	skeys[1] = { 50, 0, 50, 30,_T("编辑"),LIGHTGRAY,BLACK,MAGENTA ,1 };
	skeys[2] = { 100, 0, 50, 30,_T("样式"),LIGHTGRAY,BLACK,MAGENTA ,1 };
	skeys[3] = { 150, 0, 50, 30,_T("定时"),LIGHTGRAY,BLACK,MAGENTA ,1 };
	skeys[4] = { 200, 0, 50, 30,_T("倒计"),LIGHTGRAY,BLACK,MAGENTA ,1 };
	skeys[5] = { 250, 0, 50, 30,_T("工具"),LIGHTGRAY,BLACK,MAGENTA ,1 };
	skeys[6] = { 300, 0, 50, 30,_T("帮助"),LIGHTGRAY,BLACK,MAGENTA ,1 };
	skeys[7] = { 20,449,30,30,_T(""),WHITE,BLACK,BLACK ,1 };
	skeys[8] = { 50,449,30,30,_T(""),BROWN,BLACK,BLACK ,1 };
	skeys[9] = { 80,449,30,30,_T(""),YELLOW,BLACK,BLACK ,1 };
	skeys[10] = { 110,449,30,30,_T(""),DARKGRAY,BLACK,BLACK ,1 };
	skeys[11] = { 140,449,30,30,_T(""),GREEN,BLACK,BLACK ,1 };
	skeys[12] = { 170,449,30,30,_T(""),CYAN,BLACK,BLACK ,1 };
	skeys[13] = { 200,449,30,30,_T(""),LIGHTGRAY,BLACK,BLACK ,1 };
	skeys[14] = { 230,449,30,30,_T(""),MAGENTA,BLACK,BLACK ,1 };

	settextstyle(20, 0, _T("荣体"));//按键标题颜色

	for (int id = 0; skeys[id].lenx!=0; id++)
	{
		//备份各个属性颜色
		COLORREF bk_temp_color	 = getbkcolor();//背景颜色
		COLORREF fill_temp_color = getfillcolor();//填充颜色
		COLORREF line_temp_color = getlinecolor();//边框颜色
		COLORREF text_temp_color = gettextcolor();//字体颜色

		//画按键
		setlinestyle(PS_SOLID,skeys[id].linestyle);
		setfillcolor(skeys[id].keyfillcolor);
		setlinecolor(skeys[id].keylinecolor);
		setbkcolor(skeys[id].keyfillcolor);
		settextcolor(skeys[id].keytextlcolor);
		
		fillrectangle(skeys[id].rx, skeys[id].ry, skeys[id].lenx + skeys[id].rx, skeys[id].ry + skeys[id].leny);//按键边框
		outtextxy(skeys[id].rx + 5, skeys[id].ry + 5, skeys[id].name);//按键标题

		//怀原各个属性颜色
		setfillcolor(bk_temp_color);//背景颜色
		setlinecolor(fill_temp_color);//填充颜色
		setbkcolor(line_temp_color);//边框颜色
		settextcolor(text_temp_color);//字体颜色
	}
	return 0;
}

//生成钟表函数
int timess()
{
	int rp = r * 12 / 10;
	int ts = 0, tm = 0, th = 0;
	wchar_t time_text[20] = { '\0' };
	_SYSTEMTIME temp_time;//时间结构体

	setfillcolor(BLUE);//填充颜色
	setlinecolor(BLACK);//边框颜色
	setlinestyle(PS_SOLID, 6);//线厚度
	circle(x, y, r*12/10);//画圆，钟表身体

	setlinestyle(PS_SOLID, 2);//画线属性 线宽度为2
	for (double ct = 0; ct < 2 * PI; ct += 6 * ONERAND)//画秒钟刻度
	{
		line((r*11/10 * cos(ct)+x), (r * 11 / 10 * sin(ct)+y),(rp * cos(ct)+x),(rp* sin(ct)+y));
	}

	setlinecolor(RED);
	setlinestyle(PS_SOLID, 4);
	for (double ct = 0; ct < 2 * PI; ct += 30 * ONERAND)//画时钟刻度
	{
		line(((r + 3) * cos(ct) + x), ((r + 3) * sin(ct) + y), ((rp-4) * cos(ct) + x), ((rp - 4) * sin(ct) + y));
	}

	while (true)
	{
		//按ESC键退出图形界面
		if (_kbhit())
			if (_getch() == 27)
				goto FEI;//直接跳转到有FEI标签处

		//setwritemode(R2_XORPEN);//XOR模式画图
		GetSystemTime(&temp_time);//获取的是UTC时间
		ts = temp_time.wSecond;//秒钟
		tm = temp_time.wMinute;//分钟
		th = temp_time.wHour + 8;//时钟 中国内地的时间与UTC的时差为 + 8，也就是UTC + 8。美国是UTC - 5
		th = th >= 24 ? th - 24 : th;//UTC时间本来就是24个小时我们在上面加了八个小时，它的取值范围会变为8-32小时，我们在这一步它满24是减去24，就解决这一问题。

		setp(ts, tm, th);//画表针

		//打印时间
		wsprintf(time_text, _T("%02d:%02d:%02d"), th, tm, ts);
		settextstyle(20, 0, _T("荣体"));
		settextcolor(BLACK);
		outtextxy(550, 5, time_text);
		Sleep(1000);//等待一千毫秒， 也就是一秒

		nsetp(ts, tm, th);//删除表针


		for (int i = 0; Threads[i].handle != NULL; i++)
		{
			if (strcmp(Threads[i].name, "Htimess") == 0)
			{
				if (!Threads->nots)//检测是否继续线程  
				{
					Threads[i].handle = NULL;
					memset(Threads[i].name, NULL, sizeof(Threads[i].name));
					ExitThread(0);//结束本线程
				}
			}
		}

	}
FEI:
	closegraph();
	exit(0);
}

//打印界面函数
int Interface()
{
	setbkcolor(bkcolor);//设置背景颜色
	cleardevice();//删除屏幕内容
	setkey();//开关控制函数
	Threads[0].handle = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)timess, NULL, NULL, NULL);//创建一个线程
	strcpy(Threads[0].name, "Htimess");
	Threads[0].nots = TRUE;
	return 0;
}

//消息处理函数
int mainmsg(int id)
{
	//在这里可以写自己的鼠标消息处理程序
	if (id > 6)
	{
		
		Threads[0].nots = FALSE;//给0号进程发送退出进程消息
		DWORD dwd = WaitForSingleObject(Threads[0].handle, INFINITE);//等待进程完全推出
		bkcolor = skeys[id].keyfillcolor;//更换背景颜色
		Interface();//重画界面
	}
	else
	{
		MessageBox(NULL, skeys[id].name, L"这键没有设置处理鼠标消息语句", MB_OK);
	}

	return 0;
}