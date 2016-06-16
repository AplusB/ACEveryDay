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

const int MAX_N = 205;
const int MAX_M = 40005;
const int MAX_V = MAX_N*2;
const int INF = 0x7fffffff;
int n, m, k;
int V;
int a[MAX_N], b[MAX_N], w[MAX_N];
vector<int> x;

struct Edge
{
	int v;
	int cap, cost;//容量，费用
	int rev;//反向边的编号
	Edge(){}
	Edge(int vv, int ca, int co, int re):
	v(vv), cap(ca), cost(co), rev(re){}
};

vector<Edge> G[MAX_V];
int dis[MAX_V];//最短路
int prevv[MAX_V], preve[MAX_V];

void addEdge(int u, int v, int cap, int cost){
	G[u].pb(Edge(v, cap, cost, G[v].size()));
	G[v].pb(Edge(u, 0, -cost, G[u].size()-1));
}

int minCostFlow(int s, int t, int f){
	int res = 0;
	while(f > 0){
		REP(V) dis[i] = INF;
		dis[s] = 0;
		bool flag = 1;
		while(flag){//Bellman-Ford
			flag = 0;
			for(int u=0; u < V; u++){
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

void init()
{
	REP(V) G[i].clear();
	x.clear();
	CLEAR(preve, 0); CLEAR(prevv, 0);
}

int main()
{
	FREAD("3680.txt");
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &k);
		init();
		REP(n)
			scanf("%d%d%d", &a[i], &b[i], &w[i]);
		REP(n){
			x.pb(a[i]);
			x.pb(b[i]);
		}
		sort(x.begin(), x.end());
		x.erase(unique(x.begin(), x.end()), x.end());//去重：unique把重复元素移动到后面并返回开始位置

		m = x.size();
		int s = m;
		int t = s + 1;
		V = t + 1;
		addEdge(s, 0, k, 0);
		addEdge(m-1, t, k, 0);
		for(int i=0; i+1<m; i++) 
			addEdge(i, i+1, INF, 0);//i->i+1 初始满流
		int res = 0;
		REP(n){//区间端点,用按坐标排序后的秩编号
			int u = find(x.begin(), x.end(), a[i]) - x.begin();
			int v = find(x.begin(), x.end(), b[i]) - x.begin();
			addEdge(v, u, 1, w[i]);//a->b -w(?)
			addEdge(s, v, 1, 0);
			addEdge(u, t, 1, 0);
			res -= w[i];//负权边初始满流
		}
		res += minCostFlow(s, t, k+n);
		
		printf("%d\n", -res);
	}
}
