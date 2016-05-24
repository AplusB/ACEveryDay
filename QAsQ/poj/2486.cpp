#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn = 110;
const int maxk = 250;
vector<int> edge[maxn];
void init(int n){
    for(int i=0;i<=n;i++){
        edge[i].clear();
    }
}
void Link(int st,int ed){
    edge[st].push_back(ed);
    edge[ed].push_back(st);
}

int k;
int val[maxn];
int dp[maxn][2][maxk]; // 0 back 1 notback

void dfs(int st,int fa){
//    printf("stfa %d %d\n",st,fa);;
    int valer[2][maxk];
    memset(valer,0,sizeof(valer));
    dp[st][0][0] = dp[st][1][0] = val[st];
    for(vector<int>::iterator it = edge[st].begin();it!=edge[st].end();it++){
        int x = *it;
        if(x == fa) continue;
        dfs(x,st);
        for(int i=0;i<=k;i++){
            for(int j=0;j<=i-1;j++){
                valer[1][i] = max(valer[1][i],dp[st][0][j]+dp[x][1][i-1-j]);
                if(j==i-1) continue;
                valer[0][i] = max(valer[0][i],dp[st][0][j]+dp[x][0][i-2-j]);
                valer[1][i] = max(valer[1][i],dp[st][1][j]+dp[x][0][i-2-j]);
            }
        }
        for(int i=0;i<=k;i++){
            dp[st][0][i] = max(dp[st][0][i],valer[0][i]);
            dp[st][1][i] = max(dp[st][1][i],valer[1][i]);
        }
    }
//    printf("---- %d ----\n",st);
//    for(int i=0;i<10;i++){
//        printf(i<9?"%d ":"%d\n",dp[st][0][i]);
//    }
//    for(int i=0;i<10;i++){
//        printf(i<9?"%d ":"%d\n",dp[st][1][i]);
//    }
}


int main(){
    int n;
    while(~scanf("%d %d",&n,&k)){
        init(n);
        int u,v;
        for(int i=1;i<=n;i++){
            scanf("%d",&val[i]);
        }
        for(int i=1;i<n;i++){
            scanf("%d %d",&u,&v);
            Link(u,v);
        }
        memset(dp,0,sizeof(dp));
        dfs(1,0);
        int ans = *max_element(dp[1][1],dp[1][1]+k+1);
        printf("%d\n",ans);
    }
    return 0;
}
