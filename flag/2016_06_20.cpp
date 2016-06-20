#include <bits/stdc++.h>
using namespace std;
int vis[55], n, ans;
vector < pair < int, int > > G1[55], G2[55];

void dfs(int tot, int res, int TC, int CF){
    if(res >= ans) return;
    if(TC < 3 && n - tot < 3 - TC) return;
    if(CF < 3 && n - tot < 3 - CF) return;
    if(TC < 3 && CF < 3 && n - tot < 6 - TC - CF) return;
    if(tot == n){
        if(res < ans) ans = res;
        return;
    }
    int tmp = res;
    if(tot != n - 1){
        for(int i = 0; i < G1[tot + 1].size(); i++){
            if(!vis[G1[tot + 1][i].first])
                res += G1[tot + 1][i].second;
        }
        vis[tot + 1] = 1;
        dfs(tot + 1, res, TC + 1, CF);
    }
    if(tot != 0){
        res = tmp;
        for(int i = 0; i < G2[tot + 1].size(); i++){
            if(vis[G2[tot + 1][i].first])
                res += G2[tot + 1][i].second;
        }
        vis[tot + 1] = 0;
        dfs(tot + 1, res, TC, CF + 1);
    }
}

int main(){
    int m, a, b, c;
    while(scanf("%d%d", &n, &m) != EOF){
        for(int i = 0; i < 55; i++) G1[i].clear(), G2[i].clear();
        for(int i = 1; i <= m; i++){
            scanf("%d%d%d", &a, &b, &c);
            if(b < a)
                G1[a].push_back(make_pair(b, c));
            if(a < b)
                G2[b].push_back(make_pair(a, c));
        }
        ans = 1e9;
        dfs(0, 0, 0, 0);
        printf("%d\n", ans);
    }
    return 0;
}

