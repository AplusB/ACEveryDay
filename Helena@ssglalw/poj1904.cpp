#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <queue>
#define CLEAR(A, X) memset(A, X, sizeof(A))
#define REP(N) for(int i=0; i<(N); i++)
#define REPE(N) for(int i=1; i<=(N); i++)
#define FREAD(FN) freopen((FN), "r", stdin)
#define pb(a) push_back(a)
#define pf() pop_front()
using namespace std;
const int MAX_N = 4005;
const int MAX_M = 200005 + MAX_N;

int Scan(){
	int res=0, ch;
	if(isdigit(ch=getchar())) res = ch - '0';
	while(isdigit(ch=getchar())) res = res*10 + ch - '0';
	return res;
}
void Write(int a){
	if(a>9) Write(a/10);
	putchar(a%10 + '0');
}
struct Edge
{
	int v, next;
	Edge(){}
	Edge(int vv, int nn):v(vv), next(nn){}
}edges[MAX_M];

int head[MAX_N];
int numN, numE;
int numL, numR;
int ans[MAX_N];//共享

void addEdge(int u, int v){//有向边
	edges[numE] = Edge(v, head[u]);
	head[u] = numE++;
}

int low[MAX_N], dfn[MAX_N];
int clock, block;
int S[MAX_N], inStack[MAX_N], topS;
int belong[MAX_N];

void init(){
	CLEAR(low, 0);
	CLEAR(dfn, 0);
	CLEAR(belong, 0);
	CLEAR(inStack, 0);
	CLEAR(head, -1);
	clock = block = topS = 0;
}

void scc(int u, int p){
	low[u] = dfn[u] = ++clock;
	S[topS++] = u;
	inStack[u] = 1;
	for(int i=head[u]; i != -1; i = edges[i].next){
		int v = edges[i].v;
		if(!dfn[v]){
			scc(v, u);
			low[u] = min(low[u], low[v]);
		}else if(inStack[v]){//backward
			low[u] = min(low[u], dfn[v]);
		}	
	}
	if(low[u] == dfn[u]){//new scc
		block++;
		int t;
		do{
			t = S[--topS];
			belong[t] = block;
			inStack[t] = 0;	
		}while(t != u);
	}
}

int main()
{
	FREAD("1904.txt");
	init();
	scanf("%d", &numL);
	numR = numL;
	numN = numL + numR;
	REPE(numL){
		int k;
		k = Scan();
		while(k--){
			int v;
			v = Scan();//a->b，正向边
			addEdge(i, v+numL);//princess:[numL+1, numL+numR]
		}
	}
	REPE(numL){
		int v;
		v = Scan();
		addEdge(v+numL, i);//b->a,反向边
	}
	// REPE(numN){
	// 	for(int j=head[i]; j!= -1; j=edges[j].next)
	// 		printf("%d ", edges[j].v);
	// 	printf("\n");
	// }
	REPE(numN){
		if(!dfn[i]) scc(i, 0);
	}
	REPE(numL){
		int n = 0;
		for(int j=head[i]; j!=-1; j = edges[j].next){
			int v = edges[j].v;
			if(belong[i] == belong[v]) 
				ans[n++] = v-numL;
		}
		sort(ans, ans + n);
		Write(n);
		putchar(' ');
		for(int j=0; j<n; j++){
			Write(ans[j]);
			putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}
