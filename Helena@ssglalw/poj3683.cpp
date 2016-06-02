#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define CLEAR(A, X) memset(A, X, sizeof(A))
#define REP(N) for(int i=0; i<(N); i++)
#define REPE(N) for(int i=1; i<=(N); i++)
#define FREAD(FN) freopen((FN), "r", stdin)
#define pb(a) push_back(a)

using namespace std;

const int MAX_N = 2005;
const int MAX_M = 4000005;

int n, m;

struct Time
{
	int hour, mini;
	int value;
	void get_value(){
		value = hour*60 + mini;
	}
}s[MAX_N], t[MAX_N];
int D[MAX_N];

vector<int> G[MAX_N];
vector<int> rG[MAX_N];
vector<int> post;//后序遍历的顺序
int vis[MAX_N];
int belong[MAX_N];

void addEdge(int u, int v){
	G[u].pb(v);
	rG[v].pb(u);
}
void dfs(int u){
	vis[u] = 1;
	for(int i=0; i<G[u].size(); i++){
		int v = G[u][i];
		if(!vis[v])	dfs(v);
	}
	post.pb(u);
}

void rdfs(int u, int comp){
	vis[u] = 1;
	belong[u] = comp;
	for(int i=0; i<rG[u].size(); i++){
		int v = rG[u][i];
		if(!vis[v]) rdfs(v, comp);
	}
}

void scc(){
	CLEAR(vis, 0);
	post.clear();
	for(int i=1; i <= n*2; i++){//注意节点数！
		if(!vis[i]) dfs(i);
	}

	CLEAR(vis, 0);
	int block = 1;
	for(int i=post.size()-1; i >= 0; i--){
		if(!vis[post[i]]) rdfs(post[i], block++);
	}
}

int main()
{
	FREAD("3683.txt");
	scanf("%d", &n);
	REPE(n){
		scanf("%d:%d", &s[i].hour, &s[i].mini);
		s[i].get_value();
		scanf("%d:%d", &t[i].hour, &t[i].mini);
		t[i].get_value();
		scanf("%d", &D[i]);
	}
	
	REPE(n){
		for(int j=1; j<i; j++){//最早结束时间>最晚开始时间
			if(min(s[i].value + D[i], s[j].value + D[j]) > max(s[i].value, s[j].value)){
				addEdge(i, j+n);
				addEdge(j, i+n);
			}
			if(min(s[i].value+D[i], t[j].value) > max(s[i].value, t[j].value - D[j])){
				addEdge(i, j);
				addEdge(j+n, i+n);
			}
			if(min(t[i].value, s[j].value+D[j]) > max(t[i].value - D[i], s[j].value)){
				addEdge(i+n, j+n);
				addEdge(j, i);
			}
			if(min(t[i].value, t[j].value) > max(t[i].value - D[i], t[j].value - D[j])){
				addEdge(i+n, j);
				addEdge(j+n, i);
			}
		}
	}
	scc();
	REPE(n){
		if(belong[i] == belong[i+n]){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	REPE(n){
		if(belong[i] > belong[i+n]){
			printf("%02d:%02d %02d:%02d\n", s[i].value/60, s[i].value%60, (s[i].value + D[i])/60, (s[i].value + D[i])%60);
		}else{
			printf("%02d:%02d %02d:%02d\n", (t[i].value - D[i])/60, (t[i].value - D[i])%60, t[i].value/60, t[i].value%60);
		}
	}
	return 0;
}
