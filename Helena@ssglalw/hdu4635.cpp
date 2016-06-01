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

const int MAX_N = 100005;
const int MAX_M = 100005;
int n, m;

struct Edge
{
	int v, next;
}edges[MAX_M];
int numE;
int head[MAX_N];
int clock;
int block;
int low[MAX_N], dfn[MAX_N];
int S[MAX_N], inStack[MAX_N], topS;
int belong[MAX_N];
int numP[MAX_N];//每个scc中的顶点数
vector<int> G[MAX_N];
int out[MAX_N], in[MAX_N];//缩点后的出入度


void addEdge(int u, int v){
	edges[numE].v = v;
	edges[numE].next = head[u];
	head[u] = numE++;
}

void init(){
	numE = 0;
	clock = block = 0;
	topS = 0;
	CLEAR(head, -1);
	CLEAR(low, 0);
	CLEAR(dfn, 0);
	CLEAR(inStack, 0);
	CLEAR(out, 0);
	CLEAR(in, 0);
	CLEAR(numP, 0);
}


void scc(int u){
	low[u] = dfn[u] = ++clock;
	inStack[u] = 1;
	S[topS++] = u;
	for(int i=head[u]; i != -1; i = edges[i].next){
		int v = edges[i].v;
		if(!dfn[v]){//tree
			scc(v);
			low[u] = min(low[u], low[v]);
		}else if(inStack[v]){//backward
			low[u] = min(low[u], dfn[v]);
		}
	}
	if(low[u] == dfn[u]){//new scc
		block++;
		int t;
		do{
			//printf("%d\n", u);
			t = S[--topS];
			belong[t] = block;
			inStack[t] = 0;
			numP[block]++;
		}while(t != u);//u出栈
	}
}

void rebuild(){
	REPE(block) G[i].clear();
	REPE(n){
		for(int j=head[i]; j != -1; j = edges[j].next){
			int v = edges[j].v;
			if(belong[i] != belong[v]){//bridge
				G[belong[i]].pb(belong[v]);
				out[belong[i]]++;
				in[belong[v]]++;
			}
		}
	}
}

int main()
{
	FREAD("4635.txt");
	int T;
	scanf("%d", &T);
	for(int ca = 1; ca <= T; ca++){
		scanf("%d%d", &n, &m);
		init();
		REP(m){
			int u, v;
			scanf("%d%d", &u, &v);
			addEdge(u, v);
		}
		
		REPE(n){
			if(!dfn[i]) scc(i);
		}
		
		int ans = 0;
		if(block == 1) ans = -1;
		else{
			rebuild();
			//int ans = 0;
			REPE(block){
				//printf("in %d out %d\n", in[i], out[i]);
				if(in[i] == 0 || out[i] == 0){
					ans = max(ans, n*(n-1) - m - numP[i]*(n-numP[i]));
				}
			}
			//printf("now %d\n", ans);
		}
		printf("Case %d: %d\n", ca, ans);
	}
	return 0;
}
