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
const int N=2048;
const int M=1e6+10;
int u[M],d[M];
struct node
{
    int a,b;
} p[M];

int cmp(node n1,node n2)
{
    return n1.a<n2.a;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,l,r,m,k,t;
    cin>>n;
    memset(u,0,sizeof(u));
    for(int i=0; i<n; i++)
    {
        cin>>p[i].a>>p[i].b;
        u[p[i].a]=1;
    }
    sort(p,p+n,cmp);
    int ans=n;
    d[0]=0;
    for(int i=1; i<n; i++)
    {
        ans=min(ans,d[i-1]+n-i);
        k=max(0,p[i].a-p[i].b);
        if(k<=p[0].a)
        {
            d[i]=i;
        }
        else if(k>p[i-1].a)
        {
            d[i]=d[i-1];
        }
        else
        {
            l=0;
            r=i;
            t=i;
            while(l<=r)
            {
                m=(l+r)/2;
                if(p[m].a<k)
                {
                    l=m+1;
                    t=m;
                }
                else
                {
                    r=m-1;
                }
            }
            d[i]=d[t]+(i-t-1);
            //printf("   %d %d\n",i,t);
        }
        //printf("  %d\n",d[i]);
    }
    ans=min(ans,d[n-1]);
    cout<<ans;
    return 0;
}
