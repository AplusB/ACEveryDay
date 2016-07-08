#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <assert.h>
#define FREAD(fn) freopen((fn), "r", stdin)
#define RINT(vn) scanf("%d", &(vn))
#define PINT(vb) printf("%d", vb)
#define RSTR(vn) scanf("%s", (vn))
#define PSTR(vn) printf("%s", (vn))
#define CLEAR(A, X) memset(A, X, sizeof(A))
#define REP(N) for(i=0; i<(N); i++)
#define REPE(N) for(i=1; i<=(N); i++)
#define pb(X) push_back(X)
#define pn() printf("\n")
using namespace std;
const int MAX_N = 200005;
int i, j;

struct Edge
{
	int v;//cost 都为1
	int next;
}e[MAX_N*10];
int head[MAX_N];
int numE;

int n;
int a[MAX_N];
int d[MAX_N];
bool vis[MAX_N];

void addEdge(int u, int v){
	if(v <= 0 || v > n) return ;
	e[numE].v = v;
	e[numE].next = head[u];
	head[u] = numE;
	numE++;
}

void bfs(){
	CLEAR(vis, 0);
	d[1] = 0;
	queue<int> que;
	que.push(1);
	vis[1] = 1;
	while(!que.empty()){
		int u = que.front(); que.pop();
		for(i = head[u]; i != -1; i = e[i].next){
			int v = e[i].v;
			if(vis[v]) continue;
			d[v] = d[u] + 1;
			vis[v] = 1;
			//printf("d[%d] = %d\n", v, d[v]);
			que.push(v);
		}
	}
}

int main()
{
	RINT(n);
	CLEAR(head, -1);
	numE = 0;
	REPE(n){
		RINT(a[i]);
		addEdge(i, i+1);
		addEdge(i, i-1);
		addEdge(i, a[i]);
	}
	bfs();
	REPE(n){
		PINT(d[i]);
		printf(" ");
	}
	return 0;
}
