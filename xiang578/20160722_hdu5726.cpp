/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.com
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=100000+10;
ll a[N],d[N][50];
map<ll,ll>ans;
int n;

void rmq_init()
{
    for(int i=0;i<n;i++) d[i][0]=a[i];
    for(int j=1;(1<<j)<=n;j++)
        for(int i=0;i+(1<<j)-1<n;i++)
            {
                d[i][j]=__gcd(d[i][j-1],d[i+(1<<(j-1))][j-1]);
                //printf("%d %d\n",i,j);
                //printf("%lld\n",d[i][j]);
            }
    //printf("1111");
}

long long rmq(int l,int r)
{
    int k=0;
    while((1<<k+1)<=(r-l+1)) k++;
    return __gcd(d[l][k],d[r-(1<<k)+1][k]);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,__,m,l,r;
    scanf("%d",&__);
    for(_=1;_<=__;_++)
    {
        ans.clear();
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%lld",&a[i]);
        rmq_init();
        for(int i=0;i<n;i++)
        {
            int cur=i;
            ll g=a[cur];
            while(cur<n)
            {
                g=__gcd(a[cur],g);
                l=cur;
                r=n-1;
                while(l<r)
                {
                    //printf("%d %d\n",l,r);
                    m=(l+r+1)/2;
                    ll gg=rmq(i,m);
                    if(gg==g)
                    {
                        l=m;
                    }
                    else
                    {
                        r=m-1;
                    }
                }
                ans[g]+=(l-cur+1);
                cur=l+1;
            }
        }
        printf("Case #%d:\n",_);
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&l,&r);
            l--;
            r--;
            ll tmp=rmq(l,r);
            printf("%lld %lld\n",tmp,ans[tmp]);
        }
    }
    return 0;
}
