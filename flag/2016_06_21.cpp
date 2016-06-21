#include <bits/stdc++.h>
using namespace std;
const int maxn = 305;
int dp[maxn][maxn];
int vis[maxn][maxn], dis[maxn][maxn], mp[maxn][maxn], n, m, p;
vector < pair < int, int > > po[maxn * maxn];
int dir[4][2] = {
    1, 0, 0, 1, -1, 0, 0, -1
};

bool InMap(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

void bfs(int col){
    queue < int > que;
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < po[col].size(); i++){
        int x = po[col][i].first;
        int y = po[col][i].second;
        que.push(x);
        que.push(y);
        dis[x][y] = dp[x][y];
        vis[x][y] = 1;
    }
    while(!que.empty()){
        int px = que.front(); que.pop();
        int py = que.front(); que.pop();
        vis[px][py] = 0;
        for(int i = 0; i < 4; i++){
            int x = px + dir[i][0];
            int y = py + dir[i][1];
            if(InMap(x, y) && dis[x][y] > dis[px][py] + 1){
                dis[x][y] = dis[px][py] + 1;
                if(!vis[x][y]){
                    vis[x][y] = 1;
                    que.push(x);
                    que.push(y);
                }
            }
        }
    }
}

int main(){
    scanf("%d%d%d", &n, &m, &p);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &mp[i][j]);
            po[mp[i][j]].push_back(make_pair(i, j));
        }
    }
    for(int i = 0; i < po[1].size(); i++){
        int x = po[1][i].first;
        int y = po[1][i].second;
        dp[x][y] = x + y - 2;
    }
    for(int i = 1; i < p; i++){
        if(po[i].size() * po[i + 1].size() >= n * m){
            bfs(i);
            for(int j = 0; j < po[i + 1].size(); j++){
                int x = po[i + 1][j].first;
                int y = po[i + 1][j].second;
                dp[x][y] = dis[x][y];
            }
        }else{
            for(int j = 0; j < po[i + 1].size(); j++){
                int x1 = po[i + 1][j].first;
                int y1 = po[i + 1][j].second;
                dp[x1][y1] = 1e9;
                for(int k = 0; k < po[i].size(); k++){
                    int x2 = po[i][k].first;
                    int y2 = po[i][k].second;
                    dp[x1][y1] = min(dp[x1][y1], dp[x2][y2] + abs(x1 - x2) + abs(y1 - y2));
                }
            }
        }
    }
    int ans;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(mp[i][j] == p)
                ans = dp[i][j];
    printf("%d\n", ans);
    return 0;
}

