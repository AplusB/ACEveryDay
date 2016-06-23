#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

const int MAXN=100010;
int c[MAXN];
int n;

int lowbit(int x)
{
    return x&(-x);
}
void add(int i,int val)
{
    while(i<=n)
    {
        c[i]+=val;
        i+=lowbit(i);
    }
}
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=c[i];
        i-=lowbit(i);
    }
    return s;
}
int main()
{
    int a,b;
    while(scanf("%d",&n),n)
    {
        memset(c,0,sizeof(c));
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            add(a,1);
            add(b+1,-1);
        }
        for(int i=1;i<n;i++)
          printf("%d ",sum(i));
        printf("%d\n",sum(n));
    }
    return 0;
}
