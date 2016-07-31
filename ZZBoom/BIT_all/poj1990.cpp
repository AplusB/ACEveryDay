//
/*
利用的就是树状数组的单点更新和区间求值，但是逆序嘛，也是可以求后面有多少比他大的，
枚举数组就可以依次将值塞进数组，然后瞎搞一下就好了。
逆序：
其中 i 为当前已经插入的数的个数，
getsum( aa[i] ）为比 aa[i] 小的数的个数,
i- sum( aa[i] ) 即比 aa[i] 大的个数， 即逆序的个数

*/

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

const int N=1e5+7;
struct asd{
    int v,pos;
};
asd q[N*5];
int ans[N*5];
int c[N*5];
int n;

bool cmp(asd x,asd y)
{
    return x.v<y.v;
}
int getsum(int i)
{
    int sum=0;
    while(i>=1)
    {
        sum+=c[i];
        i-=i&(-i);
    }
    return sum;
}

void update(int i,int t)
{
    while(i<=n)
    {
        c[i]+=t;
        i+=i&(-i);
    }
}

int main()
{
    while(~scanf("%d",&n)&&n)
    {
        memset(ans,0,sizeof(ans));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&q[i].v);
            q[i].pos=i;
        }
        sort(q+1,q+n+1,cmp);
        for(int i=1;i<=n;i++)
            ans[q[i].pos]=i;


        memset(c,0,sizeof(c));

        LL sum=0;
        for(int i=1;i<=n;i++)
        {
            update(ans[i],1);
            sum+=i-getsum(ans[i]);
        }
        printf("%lld\n",sum);
    }
    return 0;
}


