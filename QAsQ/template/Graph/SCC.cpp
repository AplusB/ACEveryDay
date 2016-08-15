//Directed
vector<int> edge[maxn];
stack<int> S;

int dfn[maxn],low[maxn],_cnt;
int bel[maxn];

void init(int n){
    for(int i=0;i<n;i++){
        edge[i].clear();
    }
    while(S.empty()==false)
        S.pop();
    memset(dfn,-1,sizeof(dfn));
    memset(low,-1,sizeof(low));
    memset(bel,-1,sizeof(bel));
    _cnt = 1;
}

void dfs(int st){
    S.push(st);
    dfn[st] = low[st] = _cnt++;
    for(auto &x :edge[st]){
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

