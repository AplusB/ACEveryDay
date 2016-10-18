#include<bits/stdc++.h>
using namespace std;
const int maxn = 412345;
const int INF = 0x3f3f3f3f;

int l[maxn],r[maxn];

vector<pair<int,int> > edge[maxn];
stack<int> S;

int dfn[maxn],low[maxn],_cnt;
int bel[maxn];

void init(){
    while(S.empty()==false)
        S.pop();
    memset(dfn,-1,sizeof(dfn));
    memset(low,-1,sizeof(low));
    memset(bel,-1,sizeof(bel));
    _cnt = 1;
}

void dfs(int st,int fa){
    S.push(st);
    dfn[st] = low[st] = _cnt++;
    for(auto it :edge[st]){
        int x = it.first;
        if(x == fa) continue;
        int id = it.second;
        if(dfn[x] == -1){
            dfs(x,st);
            low[st] = min(low[st],low[x]);
            if(l[id] != st) swap(l[id],r[id]);
        }
        else if(bel[x] == -1){
            low[st] = min(low[st],dfn[x]);
            if(l[id] != x) swap(l[id],r[id]);
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

int hug[maxn],ind[maxn];
vector<pair<int,int> > nedge[maxn];
bool use[maxn];

void dfans(int st,int fa){
    for(auto it : nedge[st]){
        int x = it.first;
        int id = it.second;
        if(x == fa) continue;
        dfans(x,st);
        if(x != bel[l[id]]) swap(l[id],r[id]);
    }
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    init();
    for(int i=0;i<m;i++){
        scanf("%d %d",&l[i],&r[i]);
        edge[l[i]].push_back(make_pair(r[i],i));
        edge[r[i]].push_back(make_pair(l[i],i));
    }
    for(int i=1;i<=n;i++){
        if(bel[i] == -1){
            dfs(i,-1);
        }
    }
    memset(hug,0,sizeof(hug));
    memset(ind,0,sizeof(ind));
    memset(use,0,sizeof(use));
    for(int i=1;i<=n;i++) hug[bel[i]]++;
    for(int i=0;i<m;i++){
        int bl = bel[l[i]],br = bel[r[i]];
        if(bl != br){
            ind[bl]++,ind[br]++;
            nedge[bl].push_back(make_pair(br,i));
            nedge[br].push_back(make_pair(bl,i));
        }
    }
    int st = max_element(hug,hug+n)-hug;
    printf("%d\n",hug[st]);
    dfans(st,-1);
    for(int i=0;i<m;i++){
        printf("%d %d\n",l[i],r[i]);
    }
    return 0;
}

