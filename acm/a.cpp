#include<bits/stdc++.h>
using namespace std;
char* convert(int time)
{
    char a[20];
    itoa(time,a,10);
    cout<<a<<endl;
    return a;
}

int main()
{
    struct tm *lt;
    time_t t;
    time(&t);    
    printf("%lu\n",time(&t));
    lt = localtime(&t); 
    //printf("%d/%d/%d %d:%d:%d\n", lt->tm_year + 1900, lt->tm_mon + 1, lt->tm_mday, lt->tm_hour,
     //      lt->tm_min, lt->tm_sec);
    //printf("%s/%s/%s %s:%s\n",convert(lt->tm_year + 1900),convert(lt->tm_mon + 1),convert(lt->tm_mday),convert(lt->tm_hour),convert(lt->tm_min));
    char* hour;
    //int hour=lt->tm_hour;
    struct tm sttm; 
    //memset(&sttm,0,sizeof(sttm));
    char* year;
    char a[20];
    char c[30];
    char b[20];
    int hours=lt->tm_hour;
    int mon=lt->tm_mon;
    int years=lt->tm_year;
    int days=lt->tm_mday;
    int min=lt->tm_min;
    int sec=lt->tm_sec;
    sttm.tm_year=2022-1900; // 注意，要减1900
    sttm.tm_mon=1-1;        // 注意，要减1
    sttm.tm_mday=6;
    sttm.tm_hour=1;
    sttm.tm_min=0;
    sttm.tm_sec=0;
    sttm.tm_isdst = 0;
    long long times=mktime(&sttm);
    //char* timess="1021931203";
    //itoa(times,timess,10);
   // long long timesss=atoi(timess);
    //if(mktime(&sttm)==time(&t))
    printf("%lu\n",mktime(&sttm));
    //printf("%d\n",times);
   // printf("%d\n",timesss);

    //convert(lt->tm_hour);
    itoa(lt->tm_hour,a,10);
    cout<<a<<endl;

    itoa(lt->tm_mday,b,10);
    cout<<b<<endl;
    //cout<<mday<<endl;
    //itoa(lt->tm_year + 1900,a,10);
    //cout<<year<<endl;
}

