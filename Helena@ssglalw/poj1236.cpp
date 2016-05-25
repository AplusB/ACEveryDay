#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
const int MAX_N = 105;

int n;
vector<int> G[MAX_N];
stack<int> S;
int clock;
int scc;
int dfn[MAX_N], low[MAX_N];
int inStack[MAX_N];
int belong[MAX_N];
int indeg[MAX_N];//scc的
int outdeg[MAX_N];

void init(){
	scc = 0;
	clock = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(inStack, 0, sizeof(inStack));
	memset(indeg, 0, sizeof(indeg));
	memset(outdeg, 0, sizeof(outdeg));
}

void tarjan(int u){
	dfn[u] = low[u] = ++clock;
	S.push(u);
	inStack[u] = 1;
	for(int i=0; i<G[u].size(); i++){
		int v = G[u][i];
		if(!dfn[v]){
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}else if(inStack[v]){
			low[u] = min(low[u], dfn[v]);
		}
	}
	if(dfn[u] == low[u]){
		int v;
		do{
			v = S.top();
			S.pop();
			inStack[v] = 0;
			belong[v] = scc;
			//printf("%d ", v);
		}while(v != u);
		scc++;
	}
}


int main()
{
	freopen("1236.txt", "r", stdin);
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		int u;
		while(scanf("%d", &u) && u){
			G[i].push_back(u);
			//outdeg[i]++;
			//indeg[u]++;
		}
	}
	init();
	for(int i=1; i<=n; i++){//遍历所有点
		if(!dfn[i]){//未被发现的点
			tarjan(i);
		}
	}
	int a = 0;
	int b = 0;

	for(int i=1; i<=n; i++){//缩点
        for(int j=0; j<G[i].size(); j++){
            int u = G[i][j];
            if(belong[i] != belong[u]){
                outdeg[belong[i]]++;
                indeg[belong[u]]++;
            }
        }
	}

	for(int i=0; i<scc; i++){
        if(indeg[i] == 0) a++;
        if(outdeg[i] == 0) b++;
	}

	b = max(a, b);
	if(scc == 1) b = 0;
	printf("%d\n%d\n", a, b);
	return 0;
}
