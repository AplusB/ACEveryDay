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
const ll mod=998244353;
const int N=1e5+10;
int n,u,d,a[N],b[N],c[N];
ll cnt;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll ans;
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%d",&b[i]);
        for(int i=0; i<n; i++)
            scanf("%d",&c[i]);
        memset(a,0xff,sizeof(a));
        ans=1;
        a[0]=b[0];
        for(int i=1; i<n; i++)
        {
            if(b[i]==b[i-1]) continue;
            else if(b[i]>b[i-1])
            {
                ans=0;
                break;
            }
            else a[i]=b[i];
        }
        if(a[0]!=c[0]) ans=0;
        else
        {
            for(int i=1; i<n; i++)
            {
                if(c[i]==c[i-1]) continue;
                else if(c[i]<c[i-1])
                {
                    ans=0;
                    break;
                }
                else
                {
                    if(a[i]!=-1&&a[i]!=c[i]) {ans=0;break;}
                    else if(a[i]==-1) {a[i]=c[i];}
                }
            }
        }
        if(ans==0) puts("0");
        else
        {
            u=c[0];
            d=b[0];
            cnt=u-d+1;
            for(int i=0;i<n;i++)
            {
                if(u!=c[i])
                {
                    cnt+=c[i]-u;
                    u=c[i];
                }
                if(d!=b[i])
                {
                    cnt+=d-b[i];
                    d=b[i];
                }
                if(a[i]==-1)
                {
                    ans=(ans*cnt)%mod;
                }
                cnt--;
                if(cnt<0) {ans=0;break;}
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
