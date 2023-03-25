#include <stdio.h>
char get_choice(void);
char get_first(void);
int get_int(void);
void count(void);
int main(){
	int choice;
	void count (void);
	while ((choice =get_choice())!='q')
	{
		switch(choice)
		{
		   case 'a' : printf("Buy low ,shell high \n");
			break;
			case 'b' : putchar('\a');
			break;
			case 'c' : count();
			break;
			default : printf("Buy adbcxz \n");
			break;
		}
	}
	printf("Bye .\n" );
	return 0;

}


void count (void)
{
	int n ,i;
	printf("Count how far ? Enter an integer : \n");
	n=get_int();
	for(i=1; i<=n;i++)
	{
		printf("%d\n",i);
	}
	while (getchar() !='\n')
		continue;
}
char get_choice(void)
{
	char ch;
	printf("Enter the letter of your choice :\n");
	printf(" a. advice        b. bell\n");
	printf("c. count          d.quit\n");
	ch=get_first();
	while((ch<'a'||ch>'c') && ch!='q')
	{
		printf("please respond with a,b,c,or q\n");
		ch=get_first();
	}
	return ch;
}

//获取输入字符串
char get_first(void)
{
	char ch;
	ch=getchar();
	while(getchar() !='\n')
	continue;
	return ch;
}
int get_int(void)
{
	int input;
	char ch;
	while(scanf("%d",&input) !=1)
	{
		while((ch= getchar()) !='\n')
			putchar(ch);
		printf(" is not an integer .\n please enter an ");
		printf("integer value ,such as 25, -178, or 3:");
	}
	return input;
}
