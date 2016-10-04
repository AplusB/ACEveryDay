const int maxn = 212345;
//need init dfn deep lca first
int dfn[maxn],deep[maxn];
int Lca(int x,int y){ return ?; }

vector<int> vedge[maxn];
int cid[maxn],sid[maxn]; //assert sid is -1 init
int vnt;

int tcid(int v){
    if(sid[v] != -1) return sid[v];
    sid[v] = vnt, cid[vnt] = v;
    return vnt++;
}
void Link(int st,int ed){
    if(ed == -1 || st == ed) return;
    st = tcid(st),ed = tcid(ed);
    vedge[st].push_back(ed);
    vedge[ed].push_back(st);
}
stack<int> S;
vector<int> inp;
void bvtree(){
    sort(inp.begin(),inp.end(),[](int x,int y){return dfn[x] < dfn[y];});

    vnt = 0;
    int last = -1;
    while(S.empty()==false) S.pop();
    for(auto x : inp){
        if(S.empty()){
            Link(x,last) ,last = -1 ,S.push(x) ;
            continue;
        }
        int lca = Lca(S.top(),x);
        while(!S.empty() && deep[S.top()] >= deep[lca])
            Link(S.top(),last), last = S.top(), S.pop();

        if(    S.empty() || deep[S.top()] <  deep[lca])
            Link(lca    ,last), last = -1  ,S.push(lca);
        if(lca != x) S.push(x) ;
    }
    while(!S.empty())
        Link(S.top(),last), last = S.top(), S.pop();

    // do something
    for(int i=0;i<vnt;i++)
        vedge[i].clear(), sid[cid[i]] = -1, cid[i] = -1;
}
