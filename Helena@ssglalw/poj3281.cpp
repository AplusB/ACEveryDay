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

const int MAX_N = 405;
const int INF = 10000005;
struct Edge
{
	int from, to;
	int cap, flow;	
};

struct Dinic
{
	int n, m;//nodes, edges
	int s, t;//source, sink
	vector<Edge> edges;//edges
	vector<int> G[MAX_N];
	bool vis[MAX_N];
	int d[MAX_N];//分层
	int cur[MAX_N];

	Dinic(){}
	Dinic(int nn):n(nn){
		m = 0;
		REP(n) G[i].clear();
		edges.clear();
	}
	void addEdge(int from, int to, int cap){
		edges.push_back((Edge){from, to, cap, 0});
		edges.push_back((Edge){to, from, 0, 0});
		m = edges.size();
		G[from].pb(m - 2);
		G[to].pb(m - 1);
	}

	bool bfs(){
		CLEAR(vis, 0);
		queue<int> que;
		que.push(s);
		d[s] = 0;
		vis[s] = 1;
		while(!que.empty()){
			int v = que.front(); que.pop();
			for(int i=0; i < G[v].size(); i++){
				Edge& e = edges[G[v][i]];
				if(!vis[e.to] && e.cap > e.flow){
					vis[e.to] = 1;
					d[e.to] = d[v] + 1;
					que.push(e.to);
				}
			}
		}
		return vis[t];
	}

	int dfs(int v, int a){//最小残量a
		if(v == t || a == 0) return a;//抵达汇点或残量为0
		int flow = 0, f;
		for(int& i = cur[v]; i < G[v].size(); i++){
			Edge& e = edges[G[v][i]];
			if(d[v] + 1 == d[e.to] && (f = dfs(e.to, min(a, e.cap - e.flow))) > 0){
				e.flow += f;
				edges[G[v][i]^1].flow -= f;
				flow += f;
				a -= f;
				if(a == 0) break;
			}
		}
		return flow;//得到一条增广路
	}

	int maxFlow(int s, int t){
		this->s = s; this->t = t;
		int flow = 0;
		while(bfs()){
			CLEAR(cur, 0);
			flow += dfs(s, INF);
		}
		return flow;
	}
};

int n, f, d;

int main()
{
	FREAD("3281.txt");
	while(~scanf("%d%d%d", &n, &f, &d)){
		//编号
		//[0, n-1]食物一侧的牛, [n, n*2-1]饮料一侧的牛
		//[n*2, n*2+f-1]食物, [n*2+f,n*2+f+d-1]饮料
		//n*2+f+d 源点， n*2+f+d+1汇点
		int off_r = n;
		int off_f = n*2, off_d = n*2+f;
		int s = n*2 + f + d;
		int t = s + 1;
		Dinic dinic(n*2+f+d+2);
		REP(f) dinic.addEdge(s, i+off_f, 1); //s -> food
		REP(d) dinic.addEdge(i+off_d, t, 1); //drink -> t
		REP(n){
			int fi, di;
			int ff, dd;
			scanf("%d%d", &fi, &di);
			for(int j=0; j<fi; j++){
				scanf("%d", &ff);
				ff--;//从0开始编号
				dinic.addEdge(ff+off_f, i, 1);//food -> left cow
			}
			for(int j=0; j<di; j++){
				scanf("%d", &dd);
				dd--;
				dinic.addEdge(i+off_r, dd+off_d, 1);//right cow -> drink
			}
			dinic.addEdge(i, i+off_r, 1);//left cow -> right cow
		}
		printf("%d\n", dinic.maxFlow(s, t));
	}
}
