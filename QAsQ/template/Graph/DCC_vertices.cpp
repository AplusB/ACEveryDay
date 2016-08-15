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
            tarjan(x,st);
            low[st] = min(low[st],low[x]);
            if(low[x] >= dfn[st]){
                int top;
                do{
                    top = S.top();
                    S.pop();
                    Dcc[Dcclen].push_back(top);
                }while(top != x);
                Dcc[Dcclen].push_back(st);
                Dcclen++;
            }
        }
        else{
            low[st] = min(low[st],dfn[x]);
        }
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
