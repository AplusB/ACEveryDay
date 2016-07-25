#include<bits/stdc++.h>
using namespace std;

char opt[5];
int op(int x,int y){
    if(*opt == 'A') return x & y;
    if(*opt == 'X') return x ^ y;
    return x | y;
}
const int mod = 1e9+7;
const int maxn = 112345;
const int bit = 1<<8;
#define LL long long
const LL INF = 0x3f3f3f3f3f3f3f3fll;

vector<int> edge[maxn];
void init(int n){
    for(int i=0;i<=n;i++) edge[i].clear();
}

int w[maxn];
LL dp[maxn];
LL ds[bit][bit],space[maxn][bit];

void dfs(int st){
    int a = w[st] >> 8, b = w[st] & (bit - 1);
    dp[st] = 0;
    for(int x=0;x<bit;x++) dp[st] = max(dp[st],ds[x][b] + (op(a,x)<<8)); 
    for(int y=0;y<bit;y++){
        space[st][y] = ds[a][y];
        ds[a][y] = max(ds[a][y],dp[st] + op(b,y));
    }
    for(auto x : edge[st]) dfs(x); 
    for(int i=0;i<bit;i++) ds[a][i] = space[st][i];
}

int main(){
    int T;
    scanf("%d",&T);
    int n;
    while(T-- && ~scanf("%d %s",&n,opt)){
        for(int i=1;i<=n;i++) scanf("%d",&w[i]); 
        for(int i=0;i<bit;i++)
            for(int j=0;j<bit;j++)
                ds[i][j] = -INF;
        init(n);
        int x;
        for(int i=2;i<=n;i++){
            scanf("%d",&x);
            edge[x].push_back(i);
        }
        LL ans = 0;
        dfs(1);
        for(int i=1;i<=n;i++){
            (ans += (dp[i] + w[i]) * i)%=mod;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
