#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
char s1[500];
char s2[500];
int len[502][502];
int main()
{
    while(cin>>s1>>s2){
        int len1=strlen(s1);
        int len2=strlen(s2);
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                //cout<<s1[i]<<' '<<s2[j];
                if(s1[i-1]==s2[j-1])len[i][j]=len[i-1][j-1]+1;
                else len[i][j]=max(len[i-1][j],len[i][j-1]);
                //cout<<len[i][j]<<' ';
            }
            //cout<<endl;
        }
        cout<<len[len1][len2]<<endl;
    }
}