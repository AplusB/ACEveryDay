#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f;
int m,n;
char field[203][203];
bool vis[203][203];
int dis[203][203][2];
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};

struct point{
    int x,y;
    int cnt;  
};

void bfs(point D, int flag) 
{
    memset(vis, false, sizeof(vis));
    queue<point> q;
    q.push(D);
    vis[D.x][D.y] = true;
    
    //cout << "D  " << D.x << "  " << D.y << endl;   
    
    while(!q.empty()) {
        point tmp = q.front();
        q.pop();
        //cout << tmp.x << "  " << tmp.y << "  " << tmp.cnt << endl;
        
        if (field[tmp.x][tmp.y] == '@') {
            dis[tmp.x][tmp.y][flag] = tmp.cnt;
        }
        
        for (int i = 0; i < 4; ++i) {
            point tt = (point){tmp.x + dx[i], tmp.y + dy[i], 0};
            if (!vis[tt.x][tt.y] && tt.x >= 0 && tt.y >= 0 && tt.x < m && tt.y < n && field[tt.x][tt.y] != '#') {
                vis[tt.x][tt.y] = true;
                tt.cnt = tmp.cnt + 1;
                q.push(tt);
            }
        }
    }
    return;    
}

int main()
{
    while (scanf("%d%d", &m, &n) != EOF) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dis[i][j][0] = dis[i][j][1] = INF;
            }
        }
        point Y,M;
        getchar();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%c", &field[i][j]);
                if (field[i][j] == 'Y') Y = (point){i,j,0};
                if (field[i][j] == 'M') M = (point){i,j,0}; 
            }
            getchar();
        }
        int ans = INF;
        bfs(Y,0);
        bfs(M,1);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (field[i][j] == '@') {
                    ans = min(ans, dis[i][j][0] + dis[i][j][1]);
                }
            }
        }        
        
        printf("%d\n", ans * 11);
        
    }
    
    return 0;
}