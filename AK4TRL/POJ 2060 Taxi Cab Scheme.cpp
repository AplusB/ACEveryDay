#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>;
const int N = 510;
struct point{
	int time;
	int a, b, c, d;
}p[N];
struct Edge{
	int s, e, next;
}edge[N*N];
int n, e_num, head[N], vis[N], match[N];
void AddEdge(int a, int b){
	edge[e_num].s = a; edge[e_num].e = b; edge[e_num].next = head[a]; head[a] = e_num++;
}
int cals(int i, int j){
	return abs(p[i].c - p[j].a) + abs(p[i].d - p[j].b);
}
int dfs(int a){
	for (int k = head[a]; k != -1; k = edge[k].next){
		int i = edge[k].e;
		if (!vis[i]){
			vis[i] = 1;
			if (match[i] == -1 || dfs(match[i])){
				match[i] = a;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t, i, j, h, m;
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (i = 1; i <= n; i++){
			scanf("%d:%d%d%d%d%d", &h, &m, &p[i].a, &p[i].b, &p[i].c, &p[i].d);
			p[i].time = h * 60 + m;
		}
		e_num = 0;
		memset(head, -1, sizeof(head));
		for (i = 1; i <= n; i++){
			for (j = i + 1; j <= n; j++){
				if (p[i].time + cals(i, i) + cals(i, j) < p[j].time)
					AddEdge(i, j);
			}
		}
		int cnt = 0;
		memset(match, -1, sizeof(match));
		for (i = 1; i <= n; i++){
			memset(vis, 0, sizeof(vis));
			if (dfs(i))
				cnt++;
		}
		printf("%d\n", n - cnt);
	}

	return 0;
}
