#include<iostream>
double a[4][6]={{1.1,1.2,1.4,1.5,1.3,1.0},{2.2,2.2,2.4,2.5,3.3,2.0},{1.1,1.2,1.4,1.5,1.3,1.0},{3.1,3.2,3.4,3.5,3.3,3.0}};
int main()
{
    for(int i=0;i<4;i++)
    {
    for(int j=0;j<6;j++)
    printf("%.1f ",a[i][j]);
    printf("\n");
    }
    double b=1,c=1,d=1,e=1,f=1,g=1,h=1,B=1,C=1,D=1,E=1.0,F=1;
    for(int i=0;i<4;i++){
        b*=a[i][0];
        c*=a[i][1];
        d*=a[i][2];
        e*=a[i][3];
        f*=a[i][4];
        g*=a[i][5];
}
    printf("1:%f 2:%f 3:%f 4:%f 5:%f 6:%f\n",b,c,d,e,f,g);
    for(int i=0;i<6;i++)
    {
        B*=a[0][i];
        C*=a[1][i];
        D*=a[2][i];
        E*=a[3][i];
    }
    F*=B*C*D*E;
    printf("1:%f 2:%f 3:%f 4:%f\n",B,C,D,E);
    printf("%f",F);
}