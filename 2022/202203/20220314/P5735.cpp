#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    double a1,b1,a2,b2,a3,b3;
    cin>>a1>>b1>>a2>>b2>>a3>>b3;
    printf("%.2f",sqrt((a1-a2)*(a1-a2)+(b1-b2)*(b1-b2))+sqrt((a3-a2)*(a3-a2)+(b3-b2)*(b3-b2))+sqrt((a3-a1)*(a3-a1)+(b3-b1)*(b3-b1)));
}