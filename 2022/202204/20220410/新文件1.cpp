#include <conio.h>
#include <pthread_unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define max1 5000
#define max2 (max1 + 50)
int cntuser;
int now;
//登录
//注册

typedef struct user1 {
	char account[20];   //账户
	char password[20];  // 密码
	int flag;           //标记学生还是管理员  学生为1 管理员为0
} user1;
user1 user[max1];

void admenu() {
	return;
}

void studentmenu() {
	return;
}

void land() { //登陆账户  自动识别管理员学生账户
	char s1[20], s2[20];
	int i;
	int flag = 1;
	while (flag) {
		system("cls");
		printf("请输入用户名：");
		scanf("%s", s1);
		printf("请输入密码：");
		scanf("%s", s2);
		for (i = 0; i < cntuser; i++) {
			if (strcmp(s1, user[i].account) == 0) {
				if (strcmp(s2, user[i].password) != 0)
					printf("用户名或密码错误！请重新登陆！\n");
				else {
					now = i;
					printf("\t\t登陆成功！");
					flag = 0;
					if (user[i].flag == 0)
						admenu();
					else
						studentmenu();
				}
				break;
			}
		}
		if (i == cntuser)
			printf("用户名或密码错误！请重新登陆！\n");
		system("pause");
	}
}

void registerstudent() { //注册 学生用户
	int i;
	FILE *fp;
	fp = fopen("user.txt", "ab");
	char sr[20], sr1[20], sr2[20];
	while (1) {
		system("cls");
		printf("请输入用户名：(学号)");
		scanf("%s", sr);
		for (i = 0; i < cntuser; i++) {
			if (strcmp(sr, user[i].account) == 0)
				break;
		}
		if (i < cntuser) {
			printf("该用户名已存在，请重新输入！\n");
			system("pause");
			continue;
		}
		printf("请输入密码：");
		scanf("%s", sr1);
		printf("请再输入一次密码：");
		scanf("%s", sr2);

		if (strcmp(sr1, sr2) == 0) {
			strcpy(user[cntuser].account, sr);
			strcpy(user[cntuser].password, sr1);
			user[cntuser].flag = 1;
			fwrite(&user[cntuser], sizeof(user1), 1, fp);
			printf("注册成功！ 文件信息已保存！");
			system("pause");
			fclose(fp);
			cntuser++;
			break;
		} else
			printf("两次密码输入不一致，请重新注册!\n");
	}
}

//定义一个学生
typedef struct _student {
	char name[1000];  //学生姓名
	int age;          //年龄
	int stuNum;       //学号
	int score;        //成绩
} student;

//节点
typedef struct _Node {
	student stu;          //学生
	struct _Node *pNext;  //指向下一个节点的指针
} Node;
Node *g_pHead = NULL;  //头结点

void land();  //登录

void welcome();  //欢迎
void welcome1() { //欢迎
	char heart[30][120] = {
		"                        0                               000       "
		"                  ",
		"                       0                               0          "
		"                  ",
		"     000000000000     000000000000            0       0         "
		"000000000           ",
		"                0    0           0             0      0         0 "
		"      0           ",
		"               0    0      0     0        000000      0         0 "
		"      0           ",
		"      0       0            0                   0      0         0 "
		"      0           ",
		"       0     0             0                   0      0         0 "
		"    0 0           ",
		"        0   0              0                   0      0000000   0 "
		"     00           ",
		"         0 0               0                   0                0 "
		"                  ",
		"          0               0 0                  0                0 "
		"                  ",
		"         0 0             0   0                 0                0 "
		"                  ",
		"        0   0           0     0                0                0 "
		"                  ",
		"       0     0         0       0            "
		"0000000000000000000000000000            ",
		"                      0         0                                 "
		"                  ",
		"                                                                  "
		"                  ",
		"    8      8      8 8       888888  8888888       8       8      "
		"8888888            ",
		"     8     8     8  8       8       8     8      8 8     8 8     "
		"8                  ",
		"      8   8 8   8   8       8       8     8     8   8   8   8    "
		"8888888            ",
		"       8 8   8 8    8       8       8     8    8     8 8     8   "
		"8                  ",
		"        8     8     888888  888888  8888888   8       8       8  "
		"8888888            ",
		"------------------------------------------------------------------"
		"------------------",
	};
}
void inputstudent();  //录入学生成绩

void printstudent();  //打印学生信息

void savestudent();  //保存学生信息

Node *findStudent();  //查找学生信息

void modifystudent();  //修改学生信息

void deletestudent();  //删除学生信息

int main() {
	printf("是否已注册?\n是扣1，否扣2\n");
	char ch = getch();
	switch (ch) {
		case '1':
			land();
			break;
		case '2':
			registerstudent();
			break;
			welcome1();
			system("pause");  //暂停
			system("cls");    //清屏
			while (1) {
				welcome();  //调用欢迎

				char ch = getch();  //从键盘上输入数字 getch要用conio.h
				switch (ch) {
					case '1':  //录入学生成绩
						inputstudent();
						break;
					case '2':  //打印学生成绩
						printstudent();
						break;
					case '3':  //保存学生信息
						savestudent();
						break;
					case '4': { //查找学生信息
						Node *p = findStudent();
						if (p != NULL)
							printf("学号：%d\t姓名：%s\t年龄：%d\t成绩：%d\n",
							       p->stu.stuNum, p->stu.name, p->stu.age,
							       p->stu.score);
						else
							printf("未查找到该学生信息.\n");

						system("pause");  //暂停
						system("cls");    //清屏
						break;
					}
					case '5':  // 修改学生信息
						modifystudent();
						break;
					case '6':  //删除学生信息
						deletestudent();
						break;
					case '7':  //退出系统
						break;
				}
			}

			return 0;
	}

	int i;
	for (i = 0; i < 29; i++)  //逐行打印
		welcome1();
	printf("\n\t\t正在打开系统请稍后...");
	Sleep(3000);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t3秒后自动跳转");
	Sleep(1000);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t2秒后自动跳转");
	Sleep(1000);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t1秒后自动跳转");
	Sleep(1000);
	system("cls");
}

//欢迎
void welcome() {
	printf("*************************************************\n");
	printf("*\t欢迎使用高校学生成绩管理系统\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t请选择功能\t\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t1.录入学生信息\t\t\t*\n");
	printf("*\t\t2.打印学生信息\t\t\t*\n");
	printf("*\t\t3.保存学生信息\t\t\t*\n");
	printf("*\t\t4.查询学生信息\t\t\t*\n");
	printf("*\t\t5.修改学生信息\t\t\t*\n");
	printf("*\t\t6.删除学生信息\t\t\t*\n");
	printf("*\t\t7.退出系统\t\t\t*\n");
	printf("*************************************************\n");
}

//录入学生信息
void inputstudent() {
	//创建一个新节点
	Node *pNewNode = (Node *)malloc(sizeof(Node));
	pNewNode->pNext = NULL;

	//头插法
	if (g_pHead == NULL) {
		g_pHead = pNewNode;
	} else {
		pNewNode->pNext = g_pHead;
		g_pHead = pNewNode;
	}

	printf("输入学生姓名:\n");
	scanf("%s", pNewNode->stu.name);  //从键盘格式化接收一个字符串，整数等等
	printf("输入学生年龄:\n");
	scanf("%d", &pNewNode->stu.age);  //&取地址运算符
	printf("输入学生学号:\n");
	scanf("%d", &pNewNode->stu.stuNum);
	printf("输入学生成绩:\n");
	scanf("%d", &pNewNode->stu.score);

	printf("学生信息录入成功。\n");
	system("pause");  //暂停
	system("cls");    //清屏
}

//打印学生信息
void printstudent() {
	system("cls");  //清屏
	printf(
	    "*****************************************************************"
	    "\n");
	printf("*\t\t欢迎使用高校学生成绩管理系统\t\t\t*\n");
	printf(
	    "*****************************************************************"
	    "\n");

	printf("*\t学号\t*\t姓名\t*\t年龄\t*\t成绩\t*\n");
	printf(
	    "*****************************************************************"
	    "\n");

	//遍历链表
	Node *p = g_pHead;
	while (p != NULL) {
		printf("*\t%d\t*\t%s\t*\t%d\t*\t%d\t*\n", p->stu.stuNum, p->stu.name,
		       p->stu.age, p->stu.score);

		p = p->pNext;
	}
	printf(
	    "*****************************************************************"
	    "\n");
	system("pause");  //暂停
	system("cls");    //清屏
}

//保存学生信息
void savestudent() {
	FILE *fp = fopen("C:\\zy.word", "w");
	if (fp == NULL) {
		printf("打开文件失败\n");
		return;
	}
	//遍历链表
	Node *p = g_pHead;
	while (p != NULL) {
		fwrite(&p->stu, 1, sizeof(student), fp);

		p = p->pNext;
	}

	fclose(fp);  //关闭文件
	printf("\n保存文件成功\n");
	system("pause");
	system("cls");
}

//查找学生信息
Node *findStudent() {
	int nStuNum;
	char szName[1000];
	printf("请输入要查找的学生的学号：\n");
	scanf("%d", &nStuNum);

	printf("请输入要查找的学生的姓名：\n");
	scanf("%s", szName);

	Node *p = g_pHead;
	while (p != NULL) {
		// strcmp字符串比较函数
		if (p->stu.stuNum == nStuNum || 0 == strcmp(p->stu.name, szName)) {
			return p;
		}
		p = p->pNext;
	}
	//没有找到
	return NULL;
}

//修改学生信息
void modifystudent() {
	int nStuNum;
	printf("请输入需要修改信息学生的学号\n");
	scanf("%d", &nStuNum);

	Node *p = g_pHead;
	while (p != NULL) {
		if (p->stu.stuNum == nStuNum) {
			printf("请输入该学生正确的姓名，年龄，成绩\n");
			scanf("%s,%d,%d", p->stu.name, &p->stu.age, &p->stu.score);
			printf("修改成功");
			break;
		}
		p = p->pNext;
	}
	if (p == NULL) {
		printf("没有查到该学生");
	}
	system("pause");
	system("cls");
}

//删除学生信息
void deletestudent() {
	int nStuNum;
	printf("请输入需要删除的学生的学号\n");
	scanf("%d", &nStuNum);
	Node *p1, *p2;
	if (g_pHead->stu.stuNum == nStuNum) { //判断是不是头结点
		p1 = g_pHead;
		g_pHead = g_pHead->pNext;
		free(p1);
		return;
	}

	Node *p = g_pHead;  //不是头结点
	while (p->pNext != NULL) {
		if (p->pNext->stu.stuNum == nStuNum) {
			p2 = p->pNext;
			p->pNext = p->pNext->pNext;
			free(p2);
			system("pause");
			system("cls");
			return;
		}

		p = p->pNext;

		if (p->pNext == NULL) {
			break;
		}
	}
	if (p->pNext == NULL) {
		printf("没有找到该学生\n");
	}
}
