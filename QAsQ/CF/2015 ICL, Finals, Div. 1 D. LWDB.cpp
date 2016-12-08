#include<bits/stdc++.h>
using namespace std;

const int maxn = 112345;

#define LL long long 
vector<pair<int,LL>> edge[maxn];

namespace Lca{
    const int max_log = 18;
    int deep[maxn],fa[maxn][max_log];
    LL rdis[maxn];
    void dfs(int st,int Fa,LL rd,int Deep=1){
        for(int i=1;i<max_log;i++)
            fa[st][i] = -1;
        fa[st][0] = Fa,deep[st] = Deep;
        rdis[st] = rd;
        for(auto x : edge[st]){
            if(x.first == Fa) continue;
            dfs(x.first,st,rd + x.second,Deep+1);
        }
    }
    void init(int n){
        memset(fa,-1,sizeof(fa));
        dfs(1,-1,0);
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
        if (x == y) return x;
        for (int i = max_log-1;i >= 0;i--){
            if (fa[x][i] != fa[y][i]){
                x = fa[x][i];
                y = fa[y][i];
            }
        }
        return fa[x][0];
    }
    LL dist(int x,int y){
        return rdis[x] + rdis[y] - 2 * rdis[lca(x,y)];
    }
}

bool vis[maxn];
int siz[maxn],msiz[maxn];

int calroot(int st,int fa,int all){
    int ret = -1;
    siz[st] = 1,msiz[st] = 0;
    for(auto it : edge[st]){
        int x = it.first;
        if(x != fa && !vis[x]){
            int trot = calroot(x,st,all);
            if(ret==-1 || msiz[ret]>msiz[trot])
                ret = trot;
            siz[st] += siz[x];
            msiz[st] = max(msiz[st],siz[x]);
        }
    }
    msiz[st] = max(msiz[st],all - siz[st]);
    if(ret==-1 || msiz[ret] > msiz[st])
        ret = st;
    return ret;
}

int fa[maxn]; 

void dfs(int st,int Fa){
    vis[st] = true,fa[st] = Fa;
    int ans = 0;
    for(auto it : edge[st]){
        int x = it.first;
        if(vis[x]) continue;
        dfs(calroot(x,st,siz[x]),st);
    }
}

vector<pair<LL,pair<int,int>>> info[maxn];

int main(){
    int n;
    scanf("%d",&n);
    int l,r,x;
    for(int i = 1 ; i < n ; i ++){
        scanf("%d %d %d",&l,&r,&x);
        edge[l].push_back(make_pair(r,x));
        edge[r].push_back(make_pair(l,x));
    }
    Lca::init(n);
    memset(vis,0,sizeof(vis));
    dfs(calroot(calroot(1,-1,n),-1,n),-1);
    int m;
    scanf("%d",&m);
    int ord,c;
    LL d;
    for(int tim = 1 ; tim <= m ; tim ++){
        scanf("%d %d",&ord,&x);
        int tx = x;
        if(ord == 1){
            scanf("%I64d %d",&d,&c);
            while(x != -1){
                LL di = d - Lca::dist(x,tx);
                if(di < 0){
                    x = fa[x];
                    continue;
                }
                while(info[x].empty()==false && info[x].rbegin()->first <= di) 
                    info[x].pop_back();
                info[x].push_back(make_pair(di,make_pair(tim,c)));
                x = fa[x];
            }
        }
        else{
            auto ans = make_pair(0,0);
            while(x != -1){
                d = Lca::dist(x,tx);
                for(auto it = info[x].begin(); it != info[x].end() && it->first >= d; it++)
                    ans = max(ans,it->second);
                x = fa[x];
            }
            printf("%d\n",ans.second);
        }
    }
    return 0;
}

