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
const int N=1e5+10;
int a[N],b[N],c[N],d[N];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,n;
    ll ans;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",a+i);
        ans=0;
        for(int i=1;i<n;i++)
        {
            b[i]=abs(a[i]-a[i+1]);
        }
        a[0]=b[0]=b[n]=c[0]=d[0]=0;
        c[1]=0;
        for(int i=2;i<=n;i++)
        {
            c[i]=max(b[i-2],c[i-1]);
        }
        d[n]=0;
        for(int i=n-1;i>=1;i--)
        {
            d[i]=max(d[i+1],b[i+1]);
        }
        for(int i=1;i<=n;i++)
        {
            if(i==1)
            {
                ans+=d[1];
            }
            else if(i==n)
            {
                ans+=c[n];
            }
            else
            {
                int t=max(c[i],d[i]);
                ans+=max(t,abs(a[i+1]-a[i-1]));
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
