#include<stdio.h>  
#include<string.h>  
#include<queue>  
#include<algorithm>  
using namespace std;

const int maxn = 50 + 10;
const int maxp = 100 + 10;
int n, m;

int map[maxn][maxn]; //输入的图  
int w[maxp][maxp]; //路径  
int v[maxn][maxn]; // 标记是否访问  
int p[maxp]; // 父亲节点  

int dir[4][2] = { 0,1, 1,0, 0,-1, -1,0 }; // 四个方向  

struct Edge {
	int u, v;
	int w;
}edge[maxp*maxp];

struct Point {
	int x, y;
	int step;
};

void bfs(int x, int y) // 遍历第 map[x][y] 个点  
{
	Point point;
	point.x = x; point.y = y; point.step = 0; //自己到自己距离为 0  

	queue<Point> q;
	q.push(point); //起点入队  

	memset(v, 0, sizeof(v));
	v[x][y] = 1; //标记访问  
	int num = 1; //已经找的点数  

	while (!q.empty())
	{
		Point now = q.front(); //取队首  
		q.pop(); // 出队  
		Point next; //找下一个点  

		for (int i = 0; i < 4; i++) // 遍历四个方向找下一个点  
		{
			next.x = now.x + dir[i][0];
			next.y = now.y + dir[i][1];
			next.step = now.step + 1; // 步数+1  

									  //如果可以走, 并且没有被访问过  
			if (map[next.x][next.y] >= 0 && !v[next.x][next.y])
			{
				q.push(next); //入队  
				v[next.x][next.y] = 1; // 标记被访问  

				if (map[next.x][next.y] > 0) // 如果是要找的点  
				{//建图  
					edge[m].u = map[x][y];
					edge[m].v = map[next.x][next.y];
					edge[m++].w = next.step;
					num++;
					if (num == n) return; //所有的点都找完了  
				}
			}
		}
	}
	return;
}

bool cmp(Edge a, Edge b)
{
	return a.w < b.w;
}

int find(int x)
{
	return x == p[x] ? x : p[x] = find(p[x]);
}

int Kruskal()
{
	int ans = 0;
	for (int i = 1; i <= n; i++) p[i] = i;
	sort(edge, edge + m, cmp);

	for (int i = 0; i < m; i++)
	{
		int u = find(edge[i].u);
		int v = find(edge[i].v);

		if (u != v)
		{
			p[v] = u;
			ans += edge[i].w;
		}
	}

	return ans;
}

int main()
{
	int T;
	int row, col;
	char tmp[maxn];
	char c;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &col, &row);
		gets(tmp);

		n = m = 0;

		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				scanf("%c", &c);
				if (c == '#') map[i][j] = -1;
				else if (c == ' ') map[i][j] = 0;
				else map[i][j] = ++n;
			}
			getchar();
		}

		for (int i = 0; i <= row; i++)
		{
			for (int j = 0; j <= col; j++)
				if (map[i][j] > 0)
					bfs(i, j);
		}

		int ans = Kruskal();
		printf("%d\n", ans);
	}
	return 0;
}
