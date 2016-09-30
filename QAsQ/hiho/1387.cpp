#include<bits/stdc++.h>
using namespace std;

const int maxn = 112345, ROOT = 1;

vector<int> edge[maxn];

int fa[maxn],son[maxn],siz[maxn];
int deep[maxn],top[maxn],tid[maxn];
int _cnt;

void dffs(int st,int Fa,int Deep){
    siz[st] = 1,deep[st] = Deep;
    fa[st] = Fa,son[st] = -1;
    for(auto &x:edge[st]){
        if(x != Fa){
            dffs(x,st,Deep+1);
            siz[st] += siz[x];
            if(son[st] == -1 || siz[son[st]] < siz[x])
                son[st] = x;
        }
    }
}

void dfss(int st,int Top){
    top[st] = Top,tid[st] = _cnt++;
    if(son[st] != -1)
        dfss(son[st],Top);
    for(auto &x:edge[st]){
        if(son[st] != x && fa[st] != x){
            dfss(x,x);
        }
    }
}

void splite(){
    _cnt = 1;
    dffs(ROOT,-1,1);
    dfss(ROOT,ROOT);
}

int Lca(int x,int y){
    int tx = top[x],ty = top[y];
    while(tx != ty){
        if(deep[tx] < deep[ty])
            swap(tx,ty),swap(x,y);
        x = fa[tx],tx = top[x];
    }
    if(deep[x] < deep[y])
        swap(x,y);
    return y;
}
int dis(int x,int y){
    int lca = Lca(x,y);
    return deep[x] + deep[y] - 2 * deep[lca] + 1;
}

char name[maxn][8];
map<string,pair<int,int> >M;

void dfs(int st,int fa){
    if(M.find(name[st]) == M.end())
        M[name[st]] = make_pair(st,st); 
    else{
        auto & var = M[name[st]];
        int va = var.first,vb = var.second;
        if(dis(va,st) < dis(vb,st))
            swap(va,vb);
        if(dis(va,vb) < dis(va,st))
            var = make_pair(va,st);
    }
    for(auto x : edge[st]){
        if(x == fa) continue;
        dfs(x,st);
    }
}

int query(string x,string y){
    if(M.find(x) == M.end()) return -1;
    if(M.find(y) == M.end()) return -1;
    auto a = M[x], b = M[y];
    return max(max(dis(a.first,b.first),dis(a.first,b.second)),
               max(dis(a.second,b.first),dis(a.second,b.second)));
}
char inp[2][10];

int main(){
    int n,m;
    while(~scanf("%d %d",&n,&m)){
        for(int i=1;i<=n;i++){
            scanf("%s",name[i]);
            edge[i].clear();
        }
        int x,y;
        for(int i=1;i<n;i++){
            scanf("%d %d",&x,&y);
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        splite();
        M.clear();
        dfs(1,0);
        while(m--){
            scanf("%s %s",inp[0],inp[1]);
            printf("%d\n",query(inp[0],inp[1]));
        }
    }
    return 0;
}





