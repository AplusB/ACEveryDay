#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <vector>

using namespace std;

char field[13][13];
bool vis[13][13];
int m,n;
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};

struct point{
  int x, y;
  int cnt;  
};

vector<point> v;

int bfs(point a, point b)
{
    memset(vis, false, sizeof(vis));
    queue<point> q;
    vis[a.x][a.y] = vis[b.x][b.y] = true;
    a.cnt = b.cnt = 0;
    q.push(a);
    q.push(b);
    int ans = 0x3f3f3f3f;
    while (!q.empty()) {
        point tmp = q.front();
        q.pop();
        ans = tmp.cnt;
        for (int i = 0; i < 4; ++i) {
            point tt;
            tt.x = tmp.x + dx[i];
            tt.y = tmp.y + dy[i];
            tt.cnt = tmp.cnt + 1;
            if (tt.x >= 0 && tt.x < m && tt.y >= 0 && tt.y < n && !vis[tt.x][tt.y] && field[tt.x][tt.y] == '#') {
                vis[tt.x][tt.y] = true;
                q.push(tt);
            }
        }       
    }
    return ans;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,iCase = 0;
    scanf("%d", &t);
    while (t--) {
        v.clear();
        scanf("%d%d", &m, &n);
        for (int i = 0; i < m; ++i) {
            getchar();
            for (int j = 0; j < n; ++j) {
                scanf("%c", &field[i][j]);
                if (field[i][j] == '#') {
                    v.push_back((point){i,j,0});
        //            cout << i << " " << j << endl;
                }
            }
        }
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < v.size(); ++i) {
            for (int j = i; j < v.size(); ++j) {
                int tmp = bfs(v[i], v[j]);
                bool flag = true;
                for (int ii = 0; ii < m; ++ii) {
                    for (int jj = 0; jj < n; ++jj) {
                        if (!vis[ii][jj] && field[ii][jj] == '#') {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag) break;
                }
                if (flag) ans = min(tmp, ans);
            }
        }
        printf("Case %d: ", ++iCase);
        if (ans == 0x3f3f3f3f) puts("-1");
        else printf("%d\n", ans);
    }
    
    return 0;
}