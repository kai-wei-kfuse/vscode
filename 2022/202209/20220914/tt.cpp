#include<stdio.h>
int main()
{
	int x;
	scanf("%d",&x);
	if(x%2==0&x>4&x<=12){
		printf("1 ");
	}else{
		printf("0 ");	
	}if(x%2!=0&x<=4&x>12){
		printf("0 ");
	}else{
		printf("1 ");
	}if(x%2==0^(x>4&x<=12)){
		printf("1 ");
	}else{
		printf("0 ");
	}if(x%2!=0&x<=4&x>12){
		printf("1 ");
	}else{
		printf("0 ");
    }
    return 0;

}
