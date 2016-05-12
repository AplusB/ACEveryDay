#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Edge 
{
	int u, v, w;
	void in() {
		scanf("%d%d%d",&u, &v, &w);
	}
	bool operator < (const Edge& cmp) const {
		return w < cmp.w;
	}
}edge[16000];
int fa[500];

int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main()
{
	int T, ca = 1;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i = 0; i < m; i++) {
			edge[i].in();
		}
		int t;
		scanf("%d", &t);
		sort(edge, edge + m);
		for(int i = 0; i < n; i++) {
			fa[i] = i;
		}
		int ret[500];
		memset(ret, -1, sizeof(ret));
		ret[t] = 0;
		for(int i = 0; i < m; i++) {
			int x = find(edge[i].u);
			int y = find(edge[i].v);
			if(x != y) {
				fa[x] = y;
			}
			for(int j = 0; j < n; j++) if(ret[j]==-1) {
				if(find(j) == find(t)) {
					ret[j] = edge[i].w;
				}
			}
		}
		printf("Case %d:\n", ca++);
		for(int i = 0; i < n; i++) {
			if(ret[i] == -1) {
				puts("Impossible");
			} else {
				printf("%d\n", ret[i]);
			}
		}
	}
	return 0;
}