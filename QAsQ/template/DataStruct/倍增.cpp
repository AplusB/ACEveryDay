//Need check
const int maxn = 212345,max_log = 18;
const int ROOT = 1;

//vector<pair<int,LL> >edge[maxn];

int deep[maxn],fa[maxn][max_log];

void dfs(int st,int Fa,int Deep=1){
    for(int i=1;i<max_log;i++)
        fa[st][i] = -1;
    fa[st][0] = Fa,deep[st] = Deep;
    for(auto x : edge[st]){
        if(x.first == Fa) continue;
        dfs(x.first,st,Deep+1);
    }
}

void init(int n){
    memset(fa,-1,sizeof(fa));
    dfs(ROOT,-1);
    for (int j = 1;j < max_log;j++){
        for (int i = 1;i <= n;i++){
            if (fa[i][j-1] != -1){
                fa[i][j] = fa[fa[i][j-1]][j-1];
            }
        }
    }
}

int lca(int x,int y){
    if (deep[x] < deep[y]) swap(x,y);
    for (int i = max_log-1;i >= 0;i--){
        if (deep[fa[x][i]] >= deep[y])
            x = fa[x][i];
    }
    if (x == y) x;
    for (int i = max_log-1;i >= 0;i--){
        if (fa[x][i] != fa[y][i]){
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}
