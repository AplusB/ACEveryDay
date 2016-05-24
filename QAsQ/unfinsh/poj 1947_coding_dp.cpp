#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 200;

vector<int>edge[maxn];
void init(int n){
    for(int i=0;i<=n;i++){
        edge[i].clear();
    }
}

void Link(int st,int ed){
    edge[st].push_back(ed);
    edge[ed].push_back(st);
}

int dp[maxn][maxn];
int ans[maxn];
void dfs(int st,int fa){



}

int main(){
    int n,k;
    while(scanf("%d %d",&n,&k)){
        init(n);
        int u,v;
        for(int i=1;i<n;i++){
            scanf("%d %d",&u,&v);
            Link(u,v);
        }
        for(int i=1;i<=n;i++){
            ans[i] = n;
        }
        memset(dp,0x3f,sizeof(dp));
        dfs(1,0);
        printf("%d\n",ans[1]);
    }
    return 0;
}

