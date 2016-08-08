#include<bits/stdc++.h>
using namespace std;

const int maxn = 2010;
const double bnd = 1e12;

double dp[maxn][maxn];
bool vis[maxn][maxn];

double dfs(int n,int t){
    if(vis[n][t]) return dp[n][t];
    if(n==0){
        vis[n][t] = true; 
        return 0;
    }
    if(t==0){
        return bnd;
    }
    dp[n][t] = bnd;
    vis[n][t] = true;
    for(int i=1;i<=n;i++){
        dp[n][t] = min(dp[n][t],(n-i+1.0)/(n+1) * dfs(n-i,t) 
                                + (i*1.0)/(n+1) * dfs(i-1,t-1)
                                + 1
                                );
    }
    return dp[n][t];
}

int main(){
    memset(vis,0,sizeof(vis));
    int n,m;
    while(~scanf("%d %d",&n,&m)){
        printf("%.6f\n",dfs(n,min(m,20)));
    }
    return 0;
}
