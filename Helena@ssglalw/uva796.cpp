#include <cstdio>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N = 15005;

struct Edge
{
	int u, v;
	Edge(){}
	Edge(int uu, int vv):u(uu), v(vv){if(u > v) swap(u, v);}//
	//Edge(int u, int v):u(u), v(v){if(u > v) swap(u, v);}
	bool operator < (const Edge& e)const{
		if(u == e.u) return v < e.v;
		return u < e.u;
	}
};

int n;
set<int> G[MAX_N];
vector<Edge> tree;
int dtime[MAX_N];
int hca[MAX_N];

void init(){
	for(int i=0; i<n; i++) G[i].clear();
	tree.clear();
	memset(dtime, 0, sizeof(dtime));
	memset(hca, 0, sizeof(hca));
}

void dfs(int r, int p, int d){
	dtime[r] = hca[r] = d;
	for(set<int>::iterator iter = G[r].begin(); iter != G[r].end(); iter++){
		int u = *iter;
		if(!dtime[u]){//dis->undis, r->u, tree
			//printf("tree %d %d\n", r, u);
			dfs(u, r, d+1);
			if(dtime[r] < hca[u]){//u has no backward
				tree.push_back(Edge(r, u));
			}else{//u has backward
				hca[r] = min(hca[r], hca[u]);
			}
		}else if(u != p){//dis->dis, r->u, backward
			//printf("backward %d %d\n", r, u);
			hca[r] = min(hca[r], dtime[u]);
		}
	}
}

int main()
{
	freopen("796.txt", "r", stdin);
	while(~scanf("%d", &n)){
		if(n == 0) {
            printf("0 critical links\n\n");
            continue;
        }
        init();
		for(int i=0; i<n; i++){
			int u, m, v;
			scanf("%d", &u);
			scanf(" (%d) ", &m);
			for(int i=0; i<m; i++){
				scanf("%d", &v);
					G[u].insert(v);
					G[v].insert(u);
			}
		}
//		for(int i=0; i<n; i++){
//			for(int j=0; j<G[i].size(); j++){
//				printf("%d ", G[i][j]);
//			}
//			printf("--%d\n", i);
//		}
		for(int i=0; i<n; i++){
			if(!dtime[i]){
				dfs(i, i, 1);//从0开始不正确，因为dtime为0表示未访问
			}
		}
		printf("%d critical links\n", tree.size());

		sort(tree.begin(), tree.end());
		for(int i=0; i<tree.size(); i++){
			printf("%d - %d\n", tree[i].u, tree[i].v);
		}
//		for(int i=0; i<n; i++){
//			printf("%d %d\n", i, hca[i]);
//		}
		printf("\n");
	}
	return 0;
}
