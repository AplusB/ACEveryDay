#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N = 5005;

int n, m;
int low[MAX_N], dfn[MAX_N];
int clock;
struct Edge
{
	int v, next;
}edges[MAX_N*2];//边数组 
int M[MAX_N][MAX_N];//邻接矩阵
int numEdge;
int preEdge[MAX_N];//同起点的上一条编的id 
int cnt[MAX_N];
int leaf;

void addEdge(int u, int v){
	edges[numEdge].v = v;
	edges[numEdge].next = preEdge[u];
	preEdge[u] = numEdge++;
}

void dfs(int u, int p){
	low[u] = dfn[u] = ++clock;
	for(int i=preEdge[u]; i != -1; i = edges[i].next){
		int v = edges[i].v;
		if(!dfn[v]){//tree
			dfs(v, u);
			low[u] = min(low[u], low[v]);
		}else if(v != p){//backward
			low[u] = min(low[u], dfn[v]);
		}
	}
}
void cal_leaf(){
	leaf = 0;
	for(int i=1; i<=n; i++){
		for(int j = preEdge[i]; j != -1; j = edges[j].next){
			int v = edges[j].v;
			if(low[v] != low[i]){//v不能连回i 
				cnt[low[i]]++;//v为low[i]分量连接的一个叶 
			}
		}
	}
	for(int i=1; i<=n; i++){
		if(cnt[i] == 1){
			leaf++;
			//printf("%d\n", i);
		}
			
	}
}

int main()
{
	freopen("3177.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	numEdge = 0;
	memset(preEdge, -1, sizeof(preEdge));
	for(int i=0; i<m; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		if(M[u][v]) continue;
		addEdge(u, v);
		addEdge(v, u);
		M[u][v] = M[v][u] = 1;
	}
	clock = 0;
	dfs(1, 0);
	cal_leaf();
	printf("%d\n", (leaf+1)/2);
//	for(int i=1; i<=n; i++){
//		printf("low %d = %d\n", i, low[i]);
//		//printf("cnt %d = %d\n", low[i], cnt[low[i]]);
//	}
	return 0;
}
