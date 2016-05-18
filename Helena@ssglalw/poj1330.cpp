#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAX_N = 10005;

int parent[MAX_N];

void init(){
	for(int i=0; i<MAX_N; i++){
		parent[i] = i;
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

vector<int> G[MAX_N];
int u, v;
int T;
int n;
int vis[MAX_N];
int indeg[MAX_N];

void dfs(int r){
	//printf("%d\n", r);
	for(int i=0; i<G[r].size(); i++){
		if(!vis[G[r][i]]){
			dfs(G[r][i]);
			unite(r, G[r][i]);//孩子合并到父节点 
		}
	}
	vis[r] = 1; // 后序遍历 
	if(r == u && vis[v]){
		printf("%d\n", find(v));
		return ;
	}else if(r == v && vis[u]){
		printf("%d\n", find(u));
		return ;
	}
}

void lca(){
	memset(vis, 0, sizeof(vis));
	init();
	int r = 0;
	for(int i=1; i<=n; i++){
		if(indeg[i]==0){
			//printf("root : %d\n", i); //入度为0的是树根 
			dfs(i);
		}
	} 	
}

int main()
{
	freopen("1330.txt", "r", stdin);
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		memset(indeg, 0, sizeof(indeg));
		for(int i=0; i<MAX_N; i++) G[i].clear();
		for(int i=0; i<n-1; i++){
			scanf("%d%d", &u, &v);
			G[u].push_back(v);//有向图 
			indeg[v]++;
		}
		scanf("%d%d", &u, &v);
		lca();
	}
	return 0;
}
