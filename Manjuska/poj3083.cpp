#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
using namespace std;
const int maxn = 100 + 10;
int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };
int dl[][2] = { {0,-1},{-1,0},{0,1},{1,0} };
int dr[][2] = { {0,-1},{-1,0},{0,-1},{1,0} };
int sx, sy, ex, ey, n, m;
char G[maxn][maxn];
struct Pos
{
	int x, y, s;
};
int dfs(int x,int y,int d,int step,int dir[][2])
{
	for(int i=0;i<4;i++)
	{
		int j = ((d - 1 + 4) % 4 + i) % 4;
		int nx = x + dir[j][0];
		int ny = y + dir[j][1];
		if (nx == ex && ny == ey) return step + 1;
		if (nx < 0 || ny < 0 || nx > n || ny > m) continue;
		if (G[nx][ny] == '#') continue;

		return dfs(nx, ny, j, step + 1, dir);
	}
}
int BFS(int sx, int sy) {
	bool vis[maxn][maxn];
	memset(vis, false, sizeof(vis));
	Pos temp = { sx,sy,1 };
	queue<Pos> Q;
	Q.push(temp);
	
	vis[sx][sy] = true;

	while (!Q.empty()) {
		Pos p = Q.front(); Q.pop();

		if (p.x == ex && p.y == ey) return p.s;

		Pos np;
		for (int d = 0; d<4; d++) {
			np.x = p.x + dx[d];
			np.y = p.y + dy[d];
			np.s = p.s + 1;

			if (np.x < 0 || np.x > n || np.y < 0 || np.y > m) continue;
			if (vis[np.x][np.y]) continue;

			if (G[np.x][np.y] != '#') {
				vis[np.x][np.y] = true;
				Q.push(np);
			}
		}
	}

	return -1;
}
int main() {
	int T, d1, d2;
	scanf("%d", &T);

	while (T--) {
		scanf("%d%d", &m, &n);

		for (int i = 0; i<n; i++) {
			scanf("%s", G[i]);
			for (int j = 0; j<m; j++) {
				if (G[i][j] == 'S') { sx = i; sy = j; }
				else if (G[i][j] == 'E') { ex = i; ey = j; }
			}
		}

		if (sx == 0) { d1 = 3; d2 = 3; }
		else if (sx == n - 1) { d1 = 1; d2 = 1; }
		else if (sy == 0) { d1 = 2; d2 = 0; }
		else if (sy == m - 1) { d1 = 0; d2 = 2; }

		printf("%d ", dfs(sx, sy, d1, 1, dl));
		printf("%d ", dfs(sx, sy, d2, 1, dr));
		printf("%d\n", BFS(sx, sy));

	}

	return 0;
}
