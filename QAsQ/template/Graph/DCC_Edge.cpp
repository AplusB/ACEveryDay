stack<int> S;
vector<int> edge[maxn],Dcc[maxn];
int dfn[maxn],low[maxn];
int _cnt,Dcclen;

void init(){
    memset(low,-1,sizeof(low));
    memset(dfn,-1,sizeof(dfn));
    _cnt = 1;
    while(S.empty()==false) S.pop();
    for(int i=0;i<maxn;i++) Dcc[i].clear();
}

void tarjan(int st,int fa){
    low[st] = dfn[st] = _cnt++;
    S.push(st);
    for(auto x : edge[st]){
        if(x == fa) continue;
        if(dfn[x] == -1){
            dfs(x);
            low[st] = min(low[st],low[x]);
        }
        else if(bel[x] == -1){
            low[st] = min(low[st],dfn[x]);
        }
    }
    if(low[st] == dfn[st]){
        while(S.top()!=st){
            bel[S.top()] = st;
            S.pop();
        }
        bel[st] = st;
        S.pop();
    }
}

int getDcc(int n){
    init();
    Dcclen = 1;
    for(int i=1;i<=n;i++)
        if(dfn[i]==-1)
            tarjan(i,0);
    return Dcclen-1;
}
