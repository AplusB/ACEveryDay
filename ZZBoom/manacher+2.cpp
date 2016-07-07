//hdoj3068


#include<cstdio>
#include<math.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;

const int N=110000;

char ss[N*2];
char s[N];
int p[N*2];
int mx,id;
int num;

int Manacher(int len)
{
    int i;
    mx=0;
    id=0;
    memset(p,0,sizeof(p));
    for(i=0;i<num;i++)
    {
        if(mx>i)
        {
            p[i]=min(mx-i,p[2*id-i]);
        }
        else
        {
            p[i]=1;
        }
        while(ss[i-p[i]]==ss[i+p[i]])
        {
            p[i]++;
        }
        if(i+p[i]>mx)
        {
            mx=i+p[i];
            id=i;
        }
    }
    int Tmax=0;
    for(int i=0;i<num;i++)
    {
        Tmax=max(p[i]-1,Tmax);
    }
    return Tmax;
}

void init(int len)
{
    num=0;
    ss[num++]='$';
    ss[num++]='#';
    int i,j;
    j=0;
    for(i=0;i<len;i++)
    {
        ss[num++]=s[i];
        ss[num++]='#';
    }
    ss[num]='\0';
}

int main()
{
    while(~scanf("%s",s))
    {
        int len;
        len=strlen(s);
        init(len);
        int ans;
        ans=Manacher(len);
        printf("%d\n",ans);
    }
    return 0;
}
