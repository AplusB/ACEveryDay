#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int,int> pii;
int m, n;
char mp[55][55];
int belong[55][55];
int totalRegion;
char idx[2555];
bool vis[55][55];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int sx, int sy)
{
    queue<pii> q;
    vis[sx][sy] = true;
    q.push(make_pair(sx, sy));
    belong[sx][sy] = totalRegion;
    while(!q.empty()) {
        pii fr = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int tx = fr.first + dx[i];
            int ty = fr.second + dy[i];
            if(tx < 0 || tx >= m + 2 || ty < 0 || ty >= n + 2) {
                continue;
            }
            if(vis[tx][ty] || mp[tx][ty] != mp[sx][sy]) {
                continue;
            }
            belong[tx][ty] = totalRegion;
            vis[tx][ty] = true;
            q.push(make_pair(tx, ty));
        }
    }
    idx[totalRegion] = mp[sx][sy];
    totalRegion++;
}

int circle;
int fa[2555];
bool mark[2555];
int find(int x) 
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void go()
{
    memset(vis, false, sizeof(vis));
    queue<pii> q;
    q.push(make_pair(0, 0));
    vis[0][0] = true;
    memset(mark, false, sizeof(mark));
    while(!q.empty()) {
        pii fr = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int tx = fr.first + dx[i];
            int ty = fr.second + dy[i];
            if(tx < 0 || tx >= m + 2 || ty < 0 || ty >= n + 2) {
                continue;
            }
            if(vis[tx][ty] || belong[tx][ty] == circle) {
                continue;
            }
            vis[tx][ty] = true;
            mark[belong[tx][ty]] = true;
            q.push(make_pair(tx, ty));
        }
    }

    int y = find(circle);
    for(int i = 0; i < totalRegion; i++) {
        if(!mark[i]) {
            int x = find(i);
            if(x != y) {
                fa[x] = y;
            }
        }
    }
}

int main()
{
    int T, ca = 1;
    scanf("%d", &T);
    while(T--)  {
        printf("Case %d:\n", ca++);
        scanf("%d%d", &m, &n);
        char str[55];
        for(int i = 0; i < m + 2; i++) {
            for(int j = 0; j < n + 2; j++) {
                mp[i][j] = '.';
            }
        }
        for(int i = 0; i < m; i++) {
            scanf("%s", str);
            for(int j = 0; j < n; j++) {
                mp[i + 1][j + 1] = str[j];
            }
        }

        memset(belong, -1, sizeof(belong));
        memset(vis, false, sizeof(vis));
        totalRegion = 0;
        for(int i = 0; i < m+2; i++) {
            for(int j = 0; j < n+2; j++) {
                if(belong[i][j] == -1) {
                    bfs(i, j);
                }
            }
        }

       // printf("tot=%d\n", totalRegion);
        for(int i = 0; i < totalRegion; i++) {
            fa[i] = i;
        }

        for(int i = 0; i < totalRegion; i++) {
            if(idx[i] == '.') {
                continue;
            }
            circle = i;
            go();
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                int t = find(belong[i][j]);
                printf("%c", idx[t]);
            }
            puts("");
        }

    }
    return 0;
}
