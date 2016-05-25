# hdu 1078  FatMouse and Cheese 

给出一个$n \times n$的矩阵，找出从左上角开始的点的值严格递增路径并且路径上的任何一对相邻点满足横坐标相等并且纵标差的绝对值小于k(或者纵坐标相等并且横坐标的差的绝对值小于k)，并且要求点的值的和最大

----

对于矩阵的每一个点对，如果$x$能走到$y$，就在$x$到$y$之间连一个边的话，我们最后可以获得的是一个$DAG$。

然后就是很经典的题目了

----

这题不用建图，直接用记忆化搜索就好，至于为什么记忆化搜索不会死循环，参见上一条

```cpp
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

```

