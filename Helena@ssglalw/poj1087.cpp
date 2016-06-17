#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <iostream>
#define REP(N) for(int i=0; i<(N); i++)
#define REPE(N) for(int i=1; i<=(N); i++)
#define CLEAR(A, X) memset(A, X, sizeof(A))
#define pb(a) push_back(a)
#define FREAD(FN) freopen((FN), "r", stdin)
#define SINT(X) scanf("%d", &(X))
using namespace std;

const int MAX_N = 1005;
const int INF = 0X7FFFFFFF;
int n, m, k;
map<string, int> receps;
int numR;
map<string, int> devices;
int s, t;

struct Edge
{
	int from, to;
	int cap, flow;	
};

struct Dinic
{
	int n, m;
	vector<Edge> edges;//edges
	vector<int> G[MAX_N];
	bool vis[MAX_N];
	int d[MAX_N];//分层
	int cur[MAX_N];

	Dinic(){}
	void addEdge(int from, int to, int cap){
		edges.pb(((Edge){from, to, cap, 0}));
		edges.pb(((Edge){to, from, 0, 0}));
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
		int flow = 0;
		while(bfs()){
			CLEAR(cur, 0);
			flow += dfs(s, INF);
		}
		return flow;
	}
};

int main()
{
	FREAD("1087.txt");
	SINT(n);
	Dinic dinic;
	numR = 0;
	REP(n){//receptacles
		string r;
		cin >> r;
		receps[r] = numR++;//[0, n-1] given recep
	}
	SINT(m);
	REP(m){//devices
		string d, r;
		cin >> d >> r;
		if(receps.find(r) == receps.end()) 
			receps[r] = numR++;
		devices[d] = receps[r];//[0, m - 1] devices
	}

	//[0, numR-1] receps
	//[numR, numR+m-1] devices
	//numR+m s
	//s+1 t
	
	SINT(k);//adapters
	REP(k){//in -> out
		string in, out;
		cin >> in >> out;
		//if(receps.find(in) == receps.end() || receps.find(out) == receps.end()) continue;//无关的插头不连边.不能这样，因为可能这一个adapter是中介!
		if(receps.find(in) == receps.end()) receps[in] = numR++;
		if(receps.find(out) == receps.end()) receps[out] = numR++;
		dinic.addEdge(receps[in], receps[out], INF);
	}

	s = numR + m;//此时numR才已确定
	t = s + 1;

	REP(n){//[0, n-1] actual receps
		dinic.addEdge(i, t, 1); //actual recep -> t
	}
	
	REP(m){//[numR, numR+m-1], devices
		dinic.addEdge(s, i + numR, 1);//s->devices
	}
	//cout << "numR=" << numR << endl;
	map<string, int>::iterator iter = devices.begin();
	for(int i = 0; iter != devices.end(); i++, iter++){
		int r = iter->second;
		dinic.addEdge(numR + i, r, 1);//device -> recep
	}

	printf("%d\n", m - dinic.maxFlow(s, t));
	return 0;
}
