#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
#include <cmath>
#define RINT(V) scanf("%d", &(V))
#define FREAD() freopen("in.txt", "r", stdin)
#define REP(N) for(int i=0; i<(N); i++)
#define REPE(N) for(int i=1; i<=(N); i++)
#define PINT(N) printf("%d", (N))
#define PSTR(S) printf("%s", S)
#define RSTR(S) scanf("%s", S)
#define pn() printf("\n")
#define pb(V) push_back(V)
#define CLEAR(A, V) memset((A), (V), sizeof(A))
using namespace std;
typedef long long ll;
const int MAX_N = 505;
const int INF = 0x3fffffff;

int n, m, s, d;
int a[MAX_N];

int V;
int G[MAX_N][MAX_N];//邻接矩阵，无边是INF, 自己到自己是0
int dis[MAX_N];//单源最短路数组
int vis[MAX_N];
int path[MAX_N], pathNum[MAX_N];
int sum[MAX_N];

int shortest(){
	int minn = INF;
	int rt = -1;
	for(int v=0; v<n; v++){
		if(v == s) continue;
		if(!vis[v] && dis[v] < minn){
			minn = dis[v];
			rt = v;
		}
	}
	return rt;
}

void dijkstra(){
	for(int v=0; v<n; v++){
		if(G[s][v] != INF && v != s){
			dis[v] = G[s][v];//一步直达
			path[v] = s;
			pathNum[v] = 1;
			sum[v] = a[s] + a[v];
		}
	}
	path[s] = -1;
	pathNum[s] = 1;
	vis[s] = 1;
	sum[s] = a[s];
	dis[s] = 0;
	while(1){
		// printf("dis+++++++++++++++++\n");
		// for(int v=0; v<n; v++){//
		// 	printf("%d ", vis[v]);
		// }
		// pn();
		int u = shortest();//select the next vertex
		if(u == -1) break;//no vertex left
		//cout << "choose " << u << endl;
		vis[u] = 1;
		for(int v=0; v<n; v++){//update priority
			//printf("try %d to %d of %d\ndis = %d\n", u, v, G[u][v], dis[u]);
			if(vis[v]) continue;//只考虑Tk以外，即最短路尚未确定的点
			if(dis[v] > dis[u] + G[u][v]){
				pathNum[v] = pathNum[u];
				dis[v] = dis[u] + G[u][v];
				path[v] = u;//记录前驱
				sum[v] = sum[u] + a[v];//更新顶点上的权值和
			}else if(dis[v] == dis[u] + G[u][v]){//这部分是关键，同值不同解
				//cout << "same " << u << endl;
				pathNum[v] += pathNum[u];//|Tv| += |Tu| 这一步是关键
				if(sum[v] < sum[u] + a[v]){
					sum[v] = sum[u] + a[v];
					path[v] = u;
				}
			}
			//cout << "path[" << v << "] = " << path[v] << endl;
		}
	}
}

void init(){
	for(int u=0; u<n; u++){
		for(int v=0; v<n; v++){
			G[u][v] = INF;
		}
		G[u][u] = 0;
		dis[u] = INF;
	}
	CLEAR(path, -1);
	CLEAR(pathNum, 0);
	CLEAR(sum, 0);
	CLEAR(vis, 0);
}

int main()
{
	FREAD();
	scanf("%d%d%d%d", &n, &m, &s, &d);
	init();
	REP(n) RINT(a[i]);
	REP(m){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		G[u][v] = min(G[u][v], w);//其实没有重边
		G[v][u] = G[u][v];//邻接矩阵
	}

	// for(int i=0; i<n; i++){
	// 	for(int j=0; j<n; j++){
	// 		printf("%d ", G[i][j]);
	// 	}
	// 	pn();
	// }

	dijkstra();//s为源, d为目的地
	printf("%d %d\n", pathNum[d], sum[d]);

	//输出路径
	stack<int> sta;
	int cur = d;
	sta.push(cur);
	while(cur != s){
		cur = path[cur];
		sta.push(cur);
	}
	while(sta.size() > 1){
		printf("%d ", sta.top());
		sta.pop();
	}
	printf("%d", sta.top());
	return 0;
}
