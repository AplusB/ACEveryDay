#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#define CLEAR(A, X) memset(A, X, sizeof(A))
#define REP(N) for(int i=0; i<(N); i++)
#define REPE(N) for(int i=1; i<=(N); i++)
#define FREAD(FN) freopen((FN), "r", stdin)
#define pb(a) push_back(a)
#define pf() pop_front()
using namespace std;

const int MAX_N = 1005;
const int INF = 0x7fffffff;
int n, m;

struct Edge
{
	int v;
	int cap, cost;//容量，费用
	int rev;//反向边的编号
	Edge(){}
	Edge(int vv, int ca, int co, int re):
	v(vv), cap(ca), cost(co), rev(re){}
};

vector<Edge> G[MAX_N];
int dis[MAX_N];//最短路
int prevv[MAX_N], preve[MAX_N];

void addEdge(int u, int v, int cap, int cost){
	G[u].pb(Edge(v, cap, cost, G[v].size()));
	G[v].pb(Edge(u, 0, -cost, G[u].size()-1));
}

int minCostFlow(int s, int t, int f){
	int res = 0;
	while(f > 0){
		REP(n) dis[i] = INF;
		dis[s] = 0;
		bool flag = 1;
		while(flag){//Bellman-Ford
			flag = 0;
			for(int u=0; u < n; u++){
				if(dis[u] == INF) continue;
				REP(G[u].size()){
					Edge& e = G[u][i];
					if(e.cap > 0 && dis[e.v] > dis[u] + e.cost){
						dis[e.v] = dis[u] + e.cost;
						prevv[e.v] = u;//记录路径
						preve[e.v] = i;
						flag = 1;
					}
				}
			}
		}
		if(dis[t] == INF) return -1;//不能到达汇点
		int d = f;
		for(int v = t; v != s; v = prevv[v]){//取最短路径上容量最小的为残量
			d = min(d, G[prevv[v]][preve[v]].cap);
		}
		f -= d;
		//printf("f = %d \n", f);
		res += d*dis[t];//增加的费用=路径长*残量
		for(int v = t; v != s; v = prevv[v]){
			Edge& e = G[prevv[v]][preve[v]];
			e.cap -= d;
			G[v][e.rev].cap += d;
		}
	}
	return res;
}

int main()
{
	FREAD("2135.txt");
	while(~scanf("%d%d", &n, &m)){
		REP(n) G[i].clear();
		CLEAR(preve, 0); CLEAR(prevv, 0);
		int s = 0, t = n-1;
		REP(m){
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			u--; v--;
			addEdge(u, v, 1, c);
			addEdge(v, u, 1, c);
		}
		printf("%d\n", minCostFlow(s, t, 2));
	}
}
