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
#define N 2100+10
#define INF 0x3f3f3f3f
#define endl '\n'
#define mod 1000000007
#define ll long long
#define eps 1e-15
using namespace std;
int n;
ll c[N];
struct node
{
   ll x,y;
}a[N],b[N];
bool cmp(node a,node b)
{
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}
ll gcd(ll x,ll y)
{
    if(y==0) return x;
    return gcd(y,x%y);
}
int main()
{
    int t;
    c[1]=2;c[0]=1;
    for(int i=2;i<=1100;i++) c[i]=(c[i-1]*2)%mod;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%lld%lld",&a[i].x,&a[i].y);
        sort(a,a+n,cmp);
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            ll sum=0;int m=0;
            for(int j=i+1;j<n;j++)
            {
                if(a[i].x==a[j].x&&a[i].y==a[j].y) sum++;
                else
                {
                    b[m].x=a[j].x-a[i].x,b[m].y=a[j].y-a[i].y;
                    ll x=gcd(abs(b[m].x),abs(b[m].y));
                    if(x) b[m].x/=x,b[m].y/=x;
                    m++;
                }
            }
            sort(b,b+m,cmp);
            ll res=1;
            ans=(ans+c[sum]-1)%mod;
            if(m==0) continue;
            for(int j=1;j<m;j++)
            {
                if(b[j].x==b[j-1].x&&b[j].y==b[j-1].y) res++;
                else ans=(ans+c[sum]*(c[res]-1))%mod,res=1;
            }
            ans=(ans+c[sum]*(c[res]-1))%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}
