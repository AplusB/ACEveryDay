#include <stack>
#include <cstdio>
#include <list>
#include <cassert>
#include <set>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <functional>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <cmath>
#define LL long long
#define ULL unsigned long long
#define SZ(x) (int)x.size()
#define Lowbit(x) ((x) & (-x))
#define MP(a, b) make_pair(a, b)
#define MS(p, num) memset(p, num, sizeof(p))
#define PB push_back
#define X first
#define Y second
#define ROP freopen("input.txt", "r", stdin);
#define MID(a, b) (a + ((b - a) >> 1))
#define LC rt << 1, l, mid
#define RC rt << 1|1, mid + 1, r
#define LRT rt << 1
#define RRT rt << 1|1
#define FOR(i, a, b) for (int i=(a); (i) < (b); (i)++)
#define FOOR(i, a, b) for (int i = (a); (i)<=(b); (i)++)
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int MAXN = 300+10;
const int MOD = 1e9 + 7;
const int dir[][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
//const int seed = 131;
int cases = 0;
typedef std::pair<int, int> pii;

struct Point {
    int val, cnt;
};

std::vector<int> G[MAXN*MAXN];
int vis[MAXN][MAXN], mp[MAXN][MAXN];
int dp[MAXN][MAXN];
int m, n;

void bfs(int p) {
    MS(vis, INF);
    std::queue<Point> Q;
    for (int u : G[p]) {
        int row = u/m + 1, col = u % m + 1;
        Q.push((Point) {u, dp[row][col]});
    }
    while (!Q.empty()) {
        Point cur = Q.front(); Q.pop();
        int x = cur.val / m + 1, y = cur.val % m + 1;
        for (int i = 0; i < 4; ++i) {
            int xx = x + dir[i][0], yy = y + dir[i][1];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && vis[xx][yy] > cur.cnt + 1) {
                vis[xx][yy] = cur.cnt + 1;
                Q.push((Point) {(xx-1)*m + yy - 1, cur.cnt + 1});
            }
        }
    }
    for (int u : G[p + 1]) {
        int x = u/m + 1, y = u%m + 1;
        dp[x][y] = vis[x][y];
    }
}

int main() {
  //  ROP;
    int p;
    scanf("%d%d%d", &n, &m, &p);
    if (p == 1) {
        puts("0");
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &mp[i][j]);
            G[mp[i][j]].push_back((i-1)*m + j - 1);
        }
    }
    MS(dp, INF);
    for (int cell : G[1]) {
        int row = cell/m + 1, column = cell % m + 1;
        dp[row][column] = row + column - 2;
    }


    int ans = INF;
    for (int i = 2; i <= p; ++i) {
        if (SZ(G[i - 1])*SZ(G[i]) > n*m) bfs(i - 1);
        else {
            for (int u : G[i - 1]) {
                int fromRow = u / m + 1, fromCol = u % m + 1;
                for (int v : G[i]) {
                    int toRow = v / m + 1, toCol = v % m + 1;
                    dp[toRow][toCol] = std::min(dp[toRow][toCol], dp[fromRow][fromCol] + abs(fromRow - toRow) + abs(fromCol - toCol));
                    if (p == i) ans = std::min(ans, dp[toRow][toCol]);
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
