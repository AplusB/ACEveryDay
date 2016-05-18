#include <cstdio>
#include <cstring>
#include <functional>
#include <algorithm>
#include <vector>

const int N = 50010;
std::vector<std::pair<int, int> > edge[N];

struct Tree *pool;
struct Tree
{
    Tree *lc, *rc;
    int sum;
    Tree *NewTree(Tree *l=NULL, Tree *r=NULL, int cnt=0) {
        pool->lc = l;
        pool->rc = r;
        pool->sum = cnt;
        return pool++;
    }
    Tree *Insert(int l, int r, int num) {

        if(l == r) {
            return NewTree(lc, rc, sum + 1);
        }
        int mid = l + r >> 1;
        if(num <= mid) {
            return NewTree(lc->Insert(l, mid, num), rc, sum + 1);
        } else {
            return NewTree(lc, rc->Insert( mid+1, r, num), sum + 1);
        }
    }
}memPool[N * 20], *root[N];

int Ask(Tree *u, Tree *v, Tree *lca, int l, int r, int k)
{
	if(l == r) {
		 return l;
	}
	int mid = l + r >> 1;
	if(u->lc->sum + v->lc->sum - 2 * lca->lc->sum >= k) {
		return Ask(u->lc, v->lc, lca->lc, l, mid, k);
	} else {
		return Ask(u->rc, v->rc, lca->rc, mid + 1, r, k - u->lc->sum - v->lc->sum + 2 * lca->lc->sum);
	}
}

int f[20][N], dep[N];
void dfs(int u, int fa = -1)
{
    for(std::vector<std::pair<int,int> > ::iterator it = edge[u].begin(); it != edge[u].end(); ++it) if(it->first != fa){
    	int v = it->first;
    	f[0][v] = u;
        root[v] = root[u]->Insert(0, 100000, it->second);
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

int Lca(int a, int b)
{
	if(dep[a] > dep[b]) {
		a ^= b, b ^= a, a ^= b;
	}
	int delta = dep[b] - dep[a];
	for(int i = 0; i < 20; i++) if(delta & (1 << i)) {
		b = f[i][b];
	}
	if(a == b) return a;
	for(int i = 19; i >= 0; i--) {
		if(f[i][a] != f[i][b]) {
			a = f[i][a]; b = f[i][b];
		}
	}
	return f[0][a];
}
int main()
{
    int n, q;
    while(scanf("%d%d", &n, &q) == 2) {
        for(int i = 1; i <= n; i++) {
            edge[i].clear();
        }
        int u, v, w;
        for(int i = 1; i < n; i++) {
            scanf("%d%d%d", &u, &v, &w);
            edge[u].push_back(std::make_pair(v, w));
            edge[v].push_back(std::make_pair(u, w));
        }
        dep[1] = 0;
        pool = memPool; 
        root[1] = root[1]->NewTree(pool, pool, 0);
        dfs(1);
        for(int i = 1; i < 20; i++) {
        	for(int j = 1; j <= n; j++) {
        		f[i][j] = f[i - 1][f[i - 1][j]];
        	}
        }
        for(int i = 0; i < q; i++) {
            scanf("%d%d", &u, &v);
            int lca = Lca(u, v);
            int len = dep[u] + dep[v] - 2 * dep[lca];
        	int ret = Ask(root[u], root[v], root[lca], 0, 100000, (len+1)/2 ) ;
            if(len & 1) {
            	printf("%d\n", ret);
            } else {
            	int ret2 = Ask(root[u], root[v], root[lca], 0, 100000, len / 2 + 1);
            	printf("%d\n", std::min(ret, ret2));
            }
        }
    }
    return 0;
}
