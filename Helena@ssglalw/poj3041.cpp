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

const int MAX_V = 1005;
const int INF = 0x7fffffff;
int n, k;

vector<int> G[MAX_V];
int match[MAX_V];
int V;
bool vis[MAX_V];

void addEdge(int u, int v){
	G[u].pb(v);
	G[v].pb(u);
}

bool dfs(int u){
	vis[u] = true;
	REP(G[u].size()){
		int v = G[u][i];
		int w = match[v];
		if(w == -1 || !vis[w] && dfs(w)){
			match[u] = v;//找到增广路
			match[v] = u;
			return true;
		}
	}
	return false;
}

int bipartite(){
	int res = 0;
	CLEAR(match, -1);
	REP(V){
		if(match[i] == -1){
			CLEAR(vis, 0);
			if(dfs(i)) res++;
		}
	}
	return res;
}

int main()
{
	FREAD("3041.txt");
	scanf("%d%d", &n, &k);
	V = n*2;//n行n列
	REP(k){
		int r, c;
		scanf("%d%d", &r, &c);//一颗行星的位置(r,c)构建一条r-c的边
		r--; c--;
		addEdge(r, n+c);//[0, n-1]行，[n, n*2-1]列
	}
	printf("%d\n", bipartite());
	return 0;
}
