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
vector<int>g[N];
int n,m,ans[N],son[N],f[N],dw[N],up[N];

void dfs(int x,int fa)
{
    son[x]=1;
    f[x]=fa;
    int t1=0,t2=0;
    dw[x]=0;
    for(int i=0; i<g[x].size(); i++)
    {
        int y=g[x][i];
        if(y==fa) continue;
        dfs(y,x);
        son[x]+=son[y];
        dw[x]=max(dw[x],dw[y]);
    }
    if(son[x]<=m) dw[x]=max(son[x],dw[x]);
}

void dfs2(int x,int fa,int val)
{
    if(n-son[x]<=m) up[x]=max(n-son[x],val);
    else up[x]=max(0,val);
    int m1=0,m2=0;
    for(int i=0;i<g[x].size();i++)
    {
        int y=g[x][i];
        if(y==fa) continue;
        if(dw[y]>=m1)
        {
            m2=m1;
            m1=dw[y];
        }
        else if(dw[y]>m2)
        {
            m2=dw[y];
        }
    }
    for(int i=0;i<g[x].size();i++)
    {
        int y=g[x][i];
        if(y==fa) continue;
        if(dw[y]!=m1) dfs2(y,x,max(up[x],m1));
        else dfs2(y,x,max(up[x],m2));
    }
}
int main()
{
    scanf("%d",&n);
    m=n/2;
    int u,v;
    for(int i=1; i<=n+1; i++)
        g[i].clear();
    for(int i=1; i<n; i++)
    {
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    son[0]=0;
    dfs(1,-1);
    dfs2(1,-1,0);
    for(int i=1;i<=n;i++)
    {
        //printf("%d %d\n",up[i],dw[i]);
        ans[i]=1;
        for(int j=0;j<g[i].size();j++)
        {
            int y=g[i][j];
            if(y==f[i])
            {
                if(n-son[i]-up[i]>m)
                    ans[i]=0;
            }
            else
            {
                if(son[y]-dw[y]>m)
                    ans[i]=0;
            }
        }
    }
    for(int i=1; i<=n; i++)
        printf("%d ",ans[i]);
    return 0;
}
