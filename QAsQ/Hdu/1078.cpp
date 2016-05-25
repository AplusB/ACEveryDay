#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<stack>
using namespace std;
const int INF = 0x3f3f3f3f3f;

const int maxn = 120;

int dp[maxn][maxn],val[maxn][maxn];
bool vis[maxn][maxn];
int n,k;

bool in(int x){
    return 1<=x && x<=n;
}

int dfs(int x,int y){
    if(vis[x][y])
        return dp[x][y];
    int ret = -INF;
    for(int i=1;i<=k;i++){
        if(in(x+i) && val[x+i][y]<val[x][y]) ret = max(ret,dfs(x+i,y));
        if(in(x-i) && val[x-i][y]<val[x][y]) ret = max(ret,dfs(x-i,y));
        if(in(y+i) && val[x][y+i]<val[x][y]) ret = max(ret,dfs(x,y+i));
        if(in(y-i) && val[x][y-i]<val[x][y]) ret = max(ret,dfs(x,y-i));
    }
    dp[x][y] = ret;
    if(ret != -INF) dp[x][y] += val[x][y];
    vis[x][y] = true;
    return dp[x][y];
}



int main(){
    while(~scanf("%d %d",&n,&k) && (n+1)&&(k+1)){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&val[i][j]);
                dp[i][j] = -INF;
            }
        }
        memset(vis,0,sizeof(vis));
        vis[1][1] = true;
        int ans = val[1][1];
        dp[1][1] = val[1][1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ans = max(ans,dfs(i,j));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
