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

const int MAX_N = 1005;
const int MAX_M = 2000005;
const int INF = 10005;
int n, m;

struct Edge
{
	int v, next;
	int w;
	bool isBrg;
	bool isDup;
}edges[MAX_M];
int numE;
int head[MAX_N];
int low[MAX_N], dfn[MAX_N], clock;
int inStack[MAX_N], S[MAX_N], topS;
int block, belong[MAX_N];
int numBrg;
int cnt;//连通块个数

void init(){
	numE = 0;
	clock = block = topS = 0;
	numBrg = 0;
	CLEAR(low, 0);
	CLEAR(dfn, 0);
	CLEAR(head, -1);
	CLEAR(belong, 0);
	CLEAR(inStack, 0);
}


void addEdge(int u, int v, int w, bool isDup){
	edges[numE].v = v;
	edges[numE].w = w;
	edges[numE].isDup = isDup;
	edges[numE].next = head[u];
	head[u] = numE++;

	//反向边
	edges[numE].v = u;
	edges[numE].w = w;
	edges[numE].isDup = isDup;
	edges[numE].next = head[v];
	head[v] = numE++;
}

void bcc(int u, int p, int isDup){
	low[u] = dfn[u] = ++clock;
	S[topS++] = u;
	inStack[u] = 1;
	for(int i=head[u]; i != -1; i = edges[i].next){
		int v = edges[i].v;
		if(v == p && (!isDup)) continue;
		if(!dfn[v]){
			bcc(v, u, edges[i].isDup);
			low[u] = min(low[u], low[v]);
			if(low[v] > dfn[u]){//bridge
				numBrg++;
				edges[i].isBrg = 1;
				edges[i^1].isBrg = 1;
			}
		}else if(inStack[v]){//backward
			low[u] = min(low[u], dfn[v]);
		}
	}
	if(low[u] == dfn[u]){//new bcc
		block++;
		int t;
		do{
			t = S[--topS];
			inStack[t] = 0;
			belong[t] = block;
		}while(t != u);
	}
}

struct Node
{
	int u, v, w;
	Node(){}
	Node(int uu, int vv, int ww):u(uu), v(vv), w(ww){}
}nodes[MAX_M];
bool cmp(Node a, Node b){
	if(a.u == b.u){
		if(a.v == b.v) return a.w < b.w;
		return a.v < b.v;
	}
	return a.u < b.u;
}
bool same(Node a, Node b){
	return a.u == b.u && a.v == b.v;
}

int main()
{
	FREAD("4738.txt");
	while(~scanf("%d%d", &n, &m) && !(n==0 && m==0)){
		init();
		REP(m){
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			if(u > v) swap(u, v);//保持顺序
			nodes[i] = Node(u, v, w);
		}
		sort(nodes, nodes+m, cmp);
		int cur = 0, i = 1;
		int flagDup = 0;
		while(cur < m){
			while(i < m && same(nodes[cur], nodes[i])){
				flagDup = 1;
				i++;
			}//重边一定不是桥，
			if(flagDup) addEdge(nodes[cur].u, nodes[cur].v, nodes[cur].w, true);
			else addEdge(nodes[cur].u, nodes[cur].v, nodes[cur].w, false);
			flagDup = 0;
			cur = i++;
		}
		cnt = 0;
		REPE(n){
			if(!dfn[i]){
				bcc(i, 0, 0);
				cnt++;
			}
		}
		int ans = INF;
		if(cnt > 1) ans = 0;//非连通
		else if(cnt==1 && !numBrg) ans = -1;//边双连通
		else{//有桥
			REPE(n){
				for(int j=head[i]; j != -1; j = edges[j].next){
					int v = edges[j].v;
					if(belong[i] != belong[v])
						ans = min(ans, edges[j].w);
				}
			}
			if(ans == 0) ans = 1;//至少派一人
		}
		printf("%d\n", ans);
	}
	return 0;
}
