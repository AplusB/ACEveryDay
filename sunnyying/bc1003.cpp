#include <cstdio>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <math.h>
#include <stdlib.h>
#define INF 0x7fffffff
#define endl '\n'
#define ll long long
#define eps 1e-8
#define N 5000100
using namespace std;
int a[101000];
ll f(ll x)
{
    if(x<0) return -x;
    return x;
}
int prime[110000],primesize=0;
bool isprime[110000];
void getlist(int listsize)
{
    memset(isprime,1,sizeof(isprime));
    isprime[1]=false;
    for(int i=2;i<=listsize;i++)
    {
        if(isprime[i]) prime[++primesize]=i;
        for(int j=1;j<=primesize&&i*prime[j]<=listsize;j++)
        {
            isprime[i*prime[j]]=false;
            if(i%prime[j]==0)break;
        }
    }
}
int judge(ll x)
{
    for(int i=1;i<=primesize;i++)
    {
        int flag=0;
        while(x%prime[i]==0)
        {
            x/=prime[i];
            flag++;
            if(flag>1) return 0;
        }
    }
    return 1;
}
int main()
{
    getlist(50000);
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        ll x;
        scanf("%I64d",&x);
        ll xx=sqrt(x),ans=-1;
        for(int i=0;i<1000;i++)
        {
            ll xxx=xx-i;
            if(ans!=-1) break;
            if(judge(xxx)&&xxx>1)
            {
                if(ans==-1) ans=f(xxx*xxx-x);
                else ans=min(ans,f(xxx*xxx-x));
            }
        }
        for(int i=0;i<1000;i++)
        {
            ll xxx=xx+i;
            if(ans!=-1&&f(xxx*xxx-x)>ans) break;
            if(judge(xxx)&&xxx>1)6
            {
                if(ans==-1) ans=f(xxx*xxx-x);
                else ans=min(ans,f(xxx*xxx-x));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
