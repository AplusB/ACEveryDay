#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 100010
typedef __int64 LL;
#define mod 10000007
/*
给你1-n的序列，然后有k次机会的操作，每一次你可以选择两个数交换。
求一个最大的逆序数。

思路：
感觉就是最后一个和第一个交换，然后往中间逼近,到最终的序列，用树状数组求一下逆序数。
*/

const int N=1e5+10;

struct asd{
    int v,pos;
};
asd q[N*4];
int c[N*4];
int n;

int Sum(int x)
{
    LL ans=0;
    while(x>0)
    {
        ans+=c[x];
        x-=x&(-x);
    }
    return ans;
}

void update(int x,int t)
{
    while(x<=n+5)
    {
        c[x]+=t;
        x+=x&(-x);
    }
}
int a[N+10];

int main()
{
    int k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        a[i]=i;
    for(int i=1;i+i<=n&&i<=k;i++)
        swap(a[i],a[n-i+1]);

    LL ans=0;
    for(int i=1;i<=n;i++)
    {
        update(a[i],1);
        ans+=i-Sum(a[i]);
    }
    printf("%I64d\n",ans);
    return 0;
}
