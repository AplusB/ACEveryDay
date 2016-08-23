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
#include<bitset>
//#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=1024;
const int M=1e5+10;
bitset<N>B[N];
bitset<N>C;
vector<int>e[M];
int n,m,q;
int a[M],b[M],op[M],ans[M];

void dfs(int x)
{
    if(x==0)
    {
        for(int i=0;i<e[x].size();i++)
        {
            dfs(e[x][i]);
        }
    }
    else if(op[x]==1)
    {
        int f=0;
        if(B[a[x]][b[x]]==0)
        {
            f=1;
            B[a[x]][b[x]]=1;
            ans[x]++;
            //printf("  %d\n",ans[x]);
        }
        for(int i=0;i<e[x].size();i++)
        {
            ans[e[x][i]]=ans[x];
            dfs(e[x][i]);
        }
        if(f==1)
        {
            B[a[x]][b[x]]=0;
        }
    }
    else if(op[x]==2)
    {
        int f=0;
        if(B[a[x]][b[x]]==1)
        {
            f=1;
            B[a[x]][b[x]]=0;
            ans[x]--;
        }
        for(int i=0;i<e[x].size();i++)
        {
            ans[e[x][i]]=ans[x];
            dfs(e[x][i]);
        }
        if(f==1)
        {
            B[a[x]][b[x]]=1;
        }
    }
    else if(op[x]==3)
    {
        ans[x]-=B[a[x]].count();
        B[a[x]]^=C;
        ans[x]+=B[a[x]].count();
        //printf("    %d %d\n",x,ans[x]);
        for(int i=0;i<e[x].size();i++)
        {
            ans[e[x][i]]=ans[x];
            dfs(e[x][i]);
        }
        //ans[x]-=B[a[x]].count();
        B[a[x]]^=C;
        //ans[x]+=B[a[x]].count();
    }
    else if(op[x]==4)
    {
        for(int i=0;i<e[x].size();i++)
        {
            ans[e[x][i]]=ans[x];
            dfs(e[x][i]);
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=m;i++)
        C[i]=1;
    e[0].clear();
    for(int i=1;i<=q;i++)
    {
        e[i].clear();
        scanf("%d",&op[i]);
        if(op[i]==1||op[i]==2)
            scanf("%d%d",&a[i],&b[i]);
        else
            scanf("%d",&a[i]);
        if(op[i]!=4)
            e[i-1].push_back(i);
        else
            e[a[i]].push_back(i);
    }
    memset(ans,0,sizeof(ans));
    dfs(0);
    for(int i=1;i<=q;i++)
    {
        printf("%d\n",ans[i]);
    }
    return 0;
}
