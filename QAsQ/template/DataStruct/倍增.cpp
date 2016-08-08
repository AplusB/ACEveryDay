//Need check
const int maxn = 212345,maxm = 212345,max_log = 18;
const int ROOT = 1;

//vector<pair<int,LL> >edge[maxn];

int deep[maxn],fa[maxn][max_log];
Info info[maxn][max_log];

void dfs(int st,int Fa,int Deep=1){
    for(int i=1;i<max_log;i++)
        fa[st][i] = -1,info[st][i] = Info();
    fa[st][0] = Fa,deep[st] = Deep;
    for(auto x : edge[st]){
        if(x.first == Fa) continue;
        dfs(x.first,st,Deep+1);
        info[x.first][0] = Info(x.second);
    }
}

void init(int n){
    memset(fa,-1,sizeof(fa));
    dfs(ROOT,-1);
    for (int j = 1;j < max_log;j++){
        for (int i = 1;i <= n;i++){
            if (fa[i][j-1] != -1){
                fa[i][j] = fa[fa[i][j-1]][j-1];
                info[i][j] = info[i][j-1] + info[fa[i][j-1]][j-1];
            }
        }
    }
}

pair<int,Info> lca(int x,int y){
    Info ix,iy;
    if (deep[x] < deep[y]) swap(x,y);
    for (int i = max_log-1;i >= 0;i--){
        if (deep[fa[x][i]] >= deep[y]){
            ix = ix + info[x][i];
            x = fa[x][i];
        }
    }
    if (x == y) return make_pair(x,ix);
    for (int i = max_log-1;i >= 0;i--){
        if (fa[x][i] != fa[y][i]){
            ix = ix + info[x][i]; x = fa[x][i];
            iy = iy + info[y][i]; y = fa[y][i];
        }
    }
    return make_pair(fa[x][0], ix/*.rev()*/+info[x][0] + info[y][0] + iy);
}
