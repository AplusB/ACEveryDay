#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAX_N = 40005;
const int MAX_M = 205;
struct Edge
{
	int to, cost;
	Edge(){	}
	Edge(int t, int c):to(t), cost(c){}
};

int parent[MAX_N];
int T;
int n, m;
vector<Edge> G[MAX_N];
vector<int> query[MAX_N];
vector<int> num[MAX_N];
int vis[MAX_N];
int len[MAX_N];
int ans[MAX_M];

void init(){
	memset(vis, 0, sizeof(vis));
	memset(len, 0, sizeof(len));	
	for(int i=0; i<MAX_N; i++){
		parent[i] = i;
		G[i].clear();
		query[i].clear();
		num[i].clear();
	}
}
int find(int x){
	if(parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}
void unite(int x, int y){
	x = find(x);
	y = find(y);
	if(x == y) return ;
	parent[y] = x;
}
bool same(int x, int y){
	return find(x) == find(y);
}

void dfs(int r, int p, int l){
	//printf("%d\n", r);
	for(int i=0; i<G[r].size(); i++){
		if(G[r][i].to == p) continue;
		if(!vis[G[r][i].to]){
			dfs(G[r][i].to, r, l+G[r][i].cost);
			unite(r, G[r][i].to);
		}
	}
	vis[r] = 1;
	len[r] = l;
	
	for(int i=0; i<query[r].size(); i++){
		if(vis[query[r][i]]){
			int ca = find(query[r][i]);
			ans[num[r][i]] = len[r] - len[ca] + len[query[r][i]] - len[ca];
		}
	}
	return ;
}

void lca(int r){
	len[r] = 0;
	dfs(r, 0, len[r]);
}

int main()
{
	freopen("2586.txt", "r", stdin);
	scanf("%d", &T);
	while(T--){
		init();
		scanf("%d%d", &n, &m);
		for(int i=0; i<n-1; i++){
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			G[u].push_back(Edge(v, w));
			G[v].push_back(Edge(u, w));
			//printf("%d %d %d\n", u, v, w);
		}
		for(int i=0; i<m; i++){
			int u, v;
			scanf("%d%d", &u, &v);
			//printf("q: %d %d\n", u, v);
			query[u].push_back(v);
			query[v].push_back(u);
			num[u].push_back(i);//第i个查询登记在u下 
			num[v].push_back(i);
		}
//		for(int i=1; i<=n; i++){
//			for(int j=0; j<G[i].size(); j++){
//				printf("%d %d\n", i, G[i][j].cost);
//			}
//		}
		lca(1);
		for(int i=0; i<m; i++){
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}
