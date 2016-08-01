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

const int N=15005;
const int M=32005;

int le[N];
int c[M];
int n;

void add(int i,int t)
{
    while(i<=M)
    {
        c[i]+=t;
        i+=i&(-i);
    }
}
int Sum(int i)
{
    int ans=0;
    while(i>0)      //如果是0的话，进过位运算只能是0，0-0还是0，所以要避免
    {
        ans+=c[i];
        i-=i&(-i);
    }
    return ans;
}

int main()
{
    scanf("%d",&n);
    memset(c,0,sizeof(c));
    memset(le,0,sizeof(le));
    int x,y;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        le[Sum(x+1)]++;     //让标志点全部往右移一个，而更新的所以也要改，防止0，会陷入死循环
        add(x+1,1);
    }
    for(int i=0;i<n;i++)
    printf("%d\n",le[i]);
    return 0;
}


