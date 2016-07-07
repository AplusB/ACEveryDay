#include<iostream>
#include<cstdio>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define N 210

int s1[110];
int s2[110];
int flag[110];
char a1[110];
char a2[110];

int sushu(int n)
{
    int m=sqrt(n);
    int ff=0;
    for(int i=2;i<=m;i++)
    {
        if(n%i==0)
        {
            ff=1;
            break;
        }
    }
    if(ff)
        return 0;
    return 1;
}

void init()
{
    int ff=0;
    for(int i=2;i<=100000;i++)
    {
        if(sushu(i))
        {
            flag[ff++]=i;
            if(ff>102)
                break;
        }
    }
}
void debug()
{
    for(int i=0;i<=100;i++)
        printf("%d\n",flag[i]);
}

int main()
{
    init();
  //  debug();
    while(1)
    {
        int x;
        int xx;
        int len1,len2;
        len1=len2=0;
        memset(s1,0,sizeof(s1));
        memset(s2,0,sizeof(s2));
        while(scanf("%d",&x))
        {
            xx=getchar();
            s1[len1++]=x;
            if(xx==' ')
                break;
        }
        while(scanf("%d",&x))
        {
            xx=getchar();
            s2[len2++]=x;
            if(xx=='\n')
                break;
        }
        int qq=0;
        memset(a1,0,sizeof(a1));
        memset(a2,0,sizeof(a2));
        for(int i=len1-1;i>=0;i--)
        {
            a1[qq++]=s1[i];
        }
        len1=qq;
        qq=0;
        for(int i=len2-1;i>=0;i--)
        {
            a2[qq++]=s2[i];
        }
        len2=qq;
        if(len1==1&&len2==1&&a1[0]==0&&a2[0]==0)
            break;
        int ans[110];
        memset(ans,0,sizeof(ans));
        int gg;
        int num=0;
        int flat=0;
        for(int i=0;i<max(len1,len2);i++)
        {
            gg=a1[i]+a2[i]+(flat==1);
           // printf("gg=%d\n",gg);
            if(gg>=flag[i])
            {
                flat=1;
            }
            else
                flat=0;
            ans[num++]=gg%flag[i];
        }
        if(flat)
        {
            ans[num++]=1;
        }
        printf("%d",ans[num-1]);
        for(int i=num-2;i>=0;i--)
        {
            printf(",%d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}



