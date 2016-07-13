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
#define REP(N) for(int i=0; i<(N); i++)
#define REPE(N) for(int i=1; i<=(N); i++)
#define pb(X) push_back(X)
#define pn() printf("\n")
using namespace std;
const int MAX_N = 1005; //=MAX_M

int m, n;
int head[MAX_N];
struct Edge
{
	int v, next;
}e[MAX_N*2];
int numE;
void addEdge(int u, int v){
	e[numE].v = v;
	e[numE].next = head[u];
	head[u] = numE++;
}
bool vis[MAX_N];

void dfs(int u){
	vis[u] = 1;
	for(int i=head[u]; i!=-1; i=e[i].next){
		int v = e[i].v;
		if(!vis[v]) dfs(v);
	}
}

int main()
{
	CLEAR(head, -1);
	RINT(n); RINT(m);
	int ans = 1;
	numE = 0;
	REP(m){
		int u, v;
		RINT(u); RINT(v);
		u--; v--;
		addEdge(u, v);
		addEdge(v, u);
	}
	if(m > n-1) ans = 0;//存在圈
	else{
		CLEAR(vis, 0);
		dfs(0);
		REPE(n-1){
			if(!vis[i]){//不连通
				ans = 0;
				break;
			}
		}
	}
	printf("%s\n", ans ? "yes" : "no");
	return 0;
}
