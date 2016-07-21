//poj1088 滑雪（水）

//#include <bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const double eps=1e-6;
const double pi=acos(-1.0);
const int mod=998244353;
const int INF=0x3f3f3f3f;

const int N=1e2+10;

int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int dp[N][N];
int a[N][N];
int n,m;

int dfs(int x,int y)
{
    if(dp[x][y])
        return dp[x][y];
    int ans=1;
    for(int i=0;i<4;i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx<0||yy<0||xx>=n||yy>=m)
            continue;
        if(a[xx][yy]<a[x][y]){
            ans=max(ans,dfs(xx,yy)+1);
        }
    }
    return dp[x][y]=ans;
}


int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    memset(dp,0,sizeof(dp));
    int ans=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dp[i][j]=dfs(i,j);
            ans=max(dp[i][j],ans);
        }
    }
    printf("%d",ans);
    return 0;
}


