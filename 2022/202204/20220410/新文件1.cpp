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
//��¼
//ע��

typedef struct user1 {
	char account[20];   //�˻�
	char password[20];  // ����
	int flag;           //���ѧ�����ǹ���Ա  ѧ��Ϊ1 ����ԱΪ0
} user1;
user1 user[max1];

void admenu() {
	return;
}

void studentmenu() {
	return;
}

void land() { //��½�˻�  �Զ�ʶ�����Աѧ���˻�
	char s1[20], s2[20];
	int i;
	int flag = 1;
	while (flag) {
		system("cls");
		printf("�������û�����");
		scanf("%s", s1);
		printf("���������룺");
		scanf("%s", s2);
		for (i = 0; i < cntuser; i++) {
			if (strcmp(s1, user[i].account) == 0) {
				if (strcmp(s2, user[i].password) != 0)
					printf("�û�����������������µ�½��\n");
				else {
					now = i;
					printf("\t\t��½�ɹ���");
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
			printf("�û�����������������µ�½��\n");
		system("pause");
	}
}

void registerstudent() { //ע�� ѧ���û�
	int i;
	FILE *fp;
	fp = fopen("user.txt", "ab");
	char sr[20], sr1[20], sr2[20];
	while (1) {
		system("cls");
		printf("�������û�����(ѧ��)");
		scanf("%s", sr);
		for (i = 0; i < cntuser; i++) {
			if (strcmp(sr, user[i].account) == 0)
				break;
		}
		if (i < cntuser) {
			printf("���û����Ѵ��ڣ����������룡\n");
			system("pause");
			continue;
		}
		printf("���������룺");
		scanf("%s", sr1);
		printf("��������һ�����룺");
		scanf("%s", sr2);

		if (strcmp(sr1, sr2) == 0) {
			strcpy(user[cntuser].account, sr);
			strcpy(user[cntuser].password, sr1);
			user[cntuser].flag = 1;
			fwrite(&user[cntuser], sizeof(user1), 1, fp);
			printf("ע��ɹ��� �ļ���Ϣ�ѱ��棡");
			system("pause");
			fclose(fp);
			cntuser++;
			break;
		} else
			printf("�����������벻һ�£�������ע��!\n");
	}
}

//����һ��ѧ��
typedef struct _student {
	char name[1000];  //ѧ������
	int age;          //����
	int stuNum;       //ѧ��
	int score;        //�ɼ�
} student;

//�ڵ�
typedef struct _Node {
	student stu;          //ѧ��
	struct _Node *pNext;  //ָ����һ���ڵ��ָ��
} Node;
Node *g_pHead = NULL;  //ͷ���

void land();  //��¼

void welcome();  //��ӭ
void welcome1() { //��ӭ
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
void inputstudent();  //¼��ѧ���ɼ�

void printstudent();  //��ӡѧ����Ϣ

void savestudent();  //����ѧ����Ϣ

Node *findStudent();  //����ѧ����Ϣ

void modifystudent();  //�޸�ѧ����Ϣ

void deletestudent();  //ɾ��ѧ����Ϣ

int main() {
	printf("�Ƿ���ע��?\n�ǿ�1�����2\n");
	char ch = getch();
	switch (ch) {
		case '1':
			land();
			break;
		case '2':
			registerstudent();
			break;
			welcome1();
			system("pause");  //��ͣ
			system("cls");    //����
			while (1) {
				welcome();  //���û�ӭ

				char ch = getch();  //�Ӽ������������� getchҪ��conio.h
				switch (ch) {
					case '1':  //¼��ѧ���ɼ�
						inputstudent();
						break;
					case '2':  //��ӡѧ���ɼ�
						printstudent();
						break;
					case '3':  //����ѧ����Ϣ
						savestudent();
						break;
					case '4': { //����ѧ����Ϣ
						Node *p = findStudent();
						if (p != NULL)
							printf("ѧ�ţ�%d\t������%s\t���䣺%d\t�ɼ���%d\n",
							       p->stu.stuNum, p->stu.name, p->stu.age,
							       p->stu.score);
						else
							printf("δ���ҵ���ѧ����Ϣ.\n");

						system("pause");  //��ͣ
						system("cls");    //����
						break;
					}
					case '5':  // �޸�ѧ����Ϣ
						modifystudent();
						break;
					case '6':  //ɾ��ѧ����Ϣ
						deletestudent();
						break;
					case '7':  //�˳�ϵͳ
						break;
				}
			}

			return 0;
	}

	int i;
	for (i = 0; i < 29; i++)  //���д�ӡ
		welcome1();
	printf("\n\t\t���ڴ�ϵͳ���Ժ�...");
	Sleep(3000);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t3����Զ���ת");
	Sleep(1000);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t2����Զ���ת");
	Sleep(1000);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t1����Զ���ת");
	Sleep(1000);
	system("cls");
}

//��ӭ
void welcome() {
	printf("*************************************************\n");
	printf("*\t��ӭʹ�ø�Уѧ���ɼ�����ϵͳ\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t��ѡ����\t\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t1.¼��ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t2.��ӡѧ����Ϣ\t\t\t*\n");
	printf("*\t\t3.����ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t4.��ѯѧ����Ϣ\t\t\t*\n");
	printf("*\t\t5.�޸�ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t6.ɾ��ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t7.�˳�ϵͳ\t\t\t*\n");
	printf("*************************************************\n");
}

//¼��ѧ����Ϣ
void inputstudent() {
	//����һ���½ڵ�
	Node *pNewNode = (Node *)malloc(sizeof(Node));
	pNewNode->pNext = NULL;

	//ͷ�巨
	if (g_pHead == NULL) {
		g_pHead = pNewNode;
	} else {
		pNewNode->pNext = g_pHead;
		g_pHead = pNewNode;
	}

	printf("����ѧ������:\n");
	scanf("%s", pNewNode->stu.name);  //�Ӽ��̸�ʽ������һ���ַ����������ȵ�
	printf("����ѧ������:\n");
	scanf("%d", &pNewNode->stu.age);  //&ȡ��ַ�����
	printf("����ѧ��ѧ��:\n");
	scanf("%d", &pNewNode->stu.stuNum);
	printf("����ѧ���ɼ�:\n");
	scanf("%d", &pNewNode->stu.score);

	printf("ѧ����Ϣ¼��ɹ���\n");
	system("pause");  //��ͣ
	system("cls");    //����
}

//��ӡѧ����Ϣ
void printstudent() {
	system("cls");  //����
	printf(
	    "*****************************************************************"
	    "\n");
	printf("*\t\t��ӭʹ�ø�Уѧ���ɼ�����ϵͳ\t\t\t*\n");
	printf(
	    "*****************************************************************"
	    "\n");

	printf("*\tѧ��\t*\t����\t*\t����\t*\t�ɼ�\t*\n");
	printf(
	    "*****************************************************************"
	    "\n");

	//��������
	Node *p = g_pHead;
	while (p != NULL) {
		printf("*\t%d\t*\t%s\t*\t%d\t*\t%d\t*\n", p->stu.stuNum, p->stu.name,
		       p->stu.age, p->stu.score);

		p = p->pNext;
	}
	printf(
	    "*****************************************************************"
	    "\n");
	system("pause");  //��ͣ
	system("cls");    //����
}

//����ѧ����Ϣ
void savestudent() {
	FILE *fp = fopen("C:\\zy.word", "w");
	if (fp == NULL) {
		printf("���ļ�ʧ��\n");
		return;
	}
	//��������
	Node *p = g_pHead;
	while (p != NULL) {
		fwrite(&p->stu, 1, sizeof(student), fp);

		p = p->pNext;
	}

	fclose(fp);  //�ر��ļ�
	printf("\n�����ļ��ɹ�\n");
	system("pause");
	system("cls");
}

//����ѧ����Ϣ
Node *findStudent() {
	int nStuNum;
	char szName[1000];
	printf("������Ҫ���ҵ�ѧ����ѧ�ţ�\n");
	scanf("%d", &nStuNum);

	printf("������Ҫ���ҵ�ѧ����������\n");
	scanf("%s", szName);

	Node *p = g_pHead;
	while (p != NULL) {
		// strcmp�ַ����ȽϺ���
		if (p->stu.stuNum == nStuNum || 0 == strcmp(p->stu.name, szName)) {
			return p;
		}
		p = p->pNext;
	}
	//û���ҵ�
	return NULL;
}

//�޸�ѧ����Ϣ
void modifystudent() {
	int nStuNum;
	printf("��������Ҫ�޸���Ϣѧ����ѧ��\n");
	scanf("%d", &nStuNum);

	Node *p = g_pHead;
	while (p != NULL) {
		if (p->stu.stuNum == nStuNum) {
			printf("�������ѧ����ȷ�����������䣬�ɼ�\n");
			scanf("%s,%d,%d", p->stu.name, &p->stu.age, &p->stu.score);
			printf("�޸ĳɹ�");
			break;
		}
		p = p->pNext;
	}
	if (p == NULL) {
		printf("û�в鵽��ѧ��");
	}
	system("pause");
	system("cls");
}

//ɾ��ѧ����Ϣ
void deletestudent() {
	int nStuNum;
	printf("��������Ҫɾ����ѧ����ѧ��\n");
	scanf("%d", &nStuNum);
	Node *p1, *p2;
	if (g_pHead->stu.stuNum == nStuNum) { //�ж��ǲ���ͷ���
		p1 = g_pHead;
		g_pHead = g_pHead->pNext;
		free(p1);
		return;
	}

	Node *p = g_pHead;  //����ͷ���
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
		printf("û���ҵ���ѧ��\n");
	}
}
