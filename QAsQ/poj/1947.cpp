#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 200;
vector<int> edge[maxn];

int dp[maxn][maxn];

void dfs(int st,int fa){
    dp[st][1] = 0;
    for(vector<int>::iterator it = edge[st].begin();it!=edge[st].end();it++){
        int x = *it; 
        if(x == fa) continue;
        dfs(x,st);
        for(int v = maxn-1;v >= 1;v--){
            dp[st][v]++;
            for(int k=1;k<v;k++){
                dp[st][v] = min(dp[st][v-k] + dp[x][k],dp[st][v]);
            }
        }
    } 
}

int anser(int n,int p){
    int ret = dp[1][p];
    for(int i=2;i<=n;i++){
        ret = min(ret,dp[i][p]+1);
    }
    return ret;
}

int main(){
    int n,d;
    while(~scanf("%d %d",&n,&d)){
        memset(dp,0x3f,sizeof(dp));
        int l,r;
        for(int i=1;i<n;i++){
            scanf("%d %d",&l,&r);
            edge[l].push_back(r);
            edge[r].push_back(l);
        }
        dfs(1,0);
        printf("%d\n",anser(n,d));
    }
    return 0;
}

