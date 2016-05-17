**KM+二分匹配  来自队友的助攻
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
#define MAX 1000
int n, m;
int a[505], b[505], c[505];
int G[505][505], G2[505][505];
int lx[505], ly[505], l[505];
int slack[505];
bool sx[505], sy[505];
bool dfs(int x){
    sx[x] = 1;
    for(int i = 1; i <= m; ++i){
        if(!sy[i]){
            int t = lx[x] + ly[i] - G2[x][i];
            if(t == 0){
                sy[i] = 1;
                if(!l[i] || dfs(l[i])){
                    l[i] = x;
                    return 1;
                }
            }
            else if(slack[i] > t)
                slack[i] = t;
        }
    }
    return 0;
}
bool hunger(int pre, int u, int v, int id){
    if(u == v) return 1;
    for(int i = 1; i <= n; ++i){
        if(i == pre || !G[u][i]) continue ;
        if(hunger(u,i,v,id)){
            G2[G[u][i]][id] = c[G[u][i]] - c[id];
            return 1;
        }
    }
    return 0;
}
void KM(){
    memset(lx,-0x3f3f3f,sizeof lx);
    memset(ly,0,sizeof ly);
    memset(l,0,sizeof l);
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= m; ++j)
            if(G2[i][j] > lx[i])
                lx[i] = G2[i][j];

    for(int i = 1; i <= m; ++i){
        memset(slack,0x3f3f3f,sizeof slack);
        while(1){
            memset(sx,0,sizeof sx);
            memset(sy,0,sizeof sy);
            if(dfs(i)) break;
            int d = 0x3f3f3f3f;
            for(int j = 1; j <= m; ++j)
                if(!sy[j] && slack[j] < d)
                    d = slack[j];
            for(int j = 1; j <= m; ++j)
                if(sx[j])
                    lx[j] -= d;

            for(int j = 1; j <= m; ++j){
                if(sy[j])
                    ly[j] += d;
                else
                    slack[j] -= d;
            }
        }
    }
}
int main(){
#ifdef ak4trl
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= m; ++i){
        int u, v;
        scanf("%d%d%d",&u,&v,&c[i]);
        a[i] = u, b[i] = v;
    }

    for(int i = 1; i < n; ++i)
        G[a[i]][b[i]] = G[b[i]][a[i]] = i;

    memset(G2,0,sizeof G2);
    for(int i = n; i <= m; ++i)
        hunger(0,a[i],b[i],i);

    KM();

    for(int i = 1; i < n; ++i)
        cout << c[i] - lx[i] <<endl;
    for(int i = n; i <= m; ++i)
        cout << c[i] + ly[i] <<endl;

    return 0;
}
