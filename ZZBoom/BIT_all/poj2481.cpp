//用C++交，过。。。
//#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const double eps=1e-5;
const double pi=acos(-1.0);
const int mod=1e8+7;
const int INF=0x3f3f3f3f;

const int N=1e5+10;

int c[N];
int cnt[N];
struct asd{
    int s,e;
    int pos;
};
asd q[N];
int n;
bool cmp(asd x,asd y)
{
    if(x.e==y.e)
        return x.s<y.s;
    return x.e>y.e;
}
int lowbit(int i)
{
    return i&(-i);
}
int SUM(int i)
{
    int s=0;
    while(i>0)
    {
        s+=c[i];
        i-=lowbit(i);
    }
    return s;
}
void add(int i,int t)
{
    while(i<=n)
    {
        c[i]+=t;
        i+=lowbit(i);
    }
}

int main()
{
    while(scanf("%d",&n)&&n)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&q[i].s,&q[i].e);
            q[i].pos=i;
        }
        sort(q+1,q+n+1,cmp);

        memset(cnt,0,sizeof(cnt));
        memset(c,0,sizeof(c));
        cnt[q[1].pos]=0;
        add(q[1].s+1,1);
        for(int i=2;i<=n;i++)
        {
            if(q[i].s==q[i-1].s&&q[i].e==q[i-1].e)
                cnt[q[i].pos]=cnt[q[i-1].pos];
            else
                cnt[q[i].pos]=SUM(q[i].s+1);
            add(q[i].s+1,1);
        }
        for(int i=1;i<=n;i++)
        {
            if(i!=1)
                printf(" ");
            printf("%d",cnt[i]);
        }
        puts("");
    }
    return 0;
}
