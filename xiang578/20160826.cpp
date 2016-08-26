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
const int N=1e6+10;
int a[N];
string s;
ll get(ll x)
{
    ll l=1,r=1e6,m,ret=-1;
    while(l<=r)
    {
        m=(l+r)/2;
        ll t=m*(m-1)/2;
        //printf("%lld %lld %lld\n",l,r,t);
        if(t>x)
        {
            r=m-1;
        }
        else if(t<x)
        {
            l=m+1;
        }
        else
        {
            return m;
            break;
        }
    }
    return -1;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll a0,a1,a2,a3,t0,t1;
    scanf("%lld%lld%lld%lld",&a0,&a1,&a2,&a3);
    if(a0+a1+a2+a3==0) printf("0\n");
    else
    {
        if(a0==0)
        {
            if(!a1&&!a2) t0=0;
            else t0=1;
        }
        else
        {
            t0=get(a0);
        }
        if(a3==0)
        {
            if(!a2&&!a1) t1=0;
            else t1=1;
        }
        else
        {
            t1=get(a3);
        }
        //printf("%lld %lld\n",t0,t1);
        if(t0==-1||t1==-1||t0*t1!=a1+a2)
        {
            puts("Impossible");
            return 0;
        }
        int b=(int)a1,n=(int)a1,t,m=(int)t1;
        int c1=(int)t1;
        int c0=(int)t0;
         memset(a,0,sizeof(a));
        for(int i=c0;i>=1;i--)
        {
            if(b<i) continue;
            t=b/i;b%=i;
            a[i]=t;
            n-=t*i;
            m-=t;
            //printf("%d %d %d\n",i,a[i],n);
            if(n==0) break;
        }
        a[0]=m;
        //printf("%d\n",a[0]);
        if(t0!=0)
        {
            for(int i=0; i<c0; i++)
            {
                //printf("%d %d\n",i,a[i]);
                for(int j=0; j<a[i]; j++)
                    printf("1");
                printf("0");
            }
            for(int j=0;j<a[c0];j++)
                printf("1");
        }
        else
        {
            for(int i=0;i<c1;i++)
                printf("1");
        }
        printf("\n");

    }
    return 0;
}
