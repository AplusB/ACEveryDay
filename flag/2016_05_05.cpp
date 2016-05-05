#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#define mkp make_pair
#define R first
#define L second.first
#define id second.second
#define val first
#define p second
using namespace std;
const int maxn = 1e4 + 5;
const int maxm = 1e5 + 5;
vector < pair < int, pair < int, int > > > q;
vector < pair < int, int > > x[2];
set < int > vis;
map < int, int > pre;
int a[maxn], ans[maxm];

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

struct BIT{
	int sum[maxn], n;

	void init(int n){
		this->n = n;
		memset(sum, 0, sizeof sum);
	}

	inline int lowbit(int x){
		return x & (-x);
	}

	void update(int x, int val){
		for(int i = x; i <= n; i += lowbit(i)){
			sum[i] += val;
		}
	}

	int query(int l, int r){
		int res = 0;
		for(int i = r; i; i -= lowbit(i)){
			res += sum[i];
		}
		for(int i = l - 1; i; i -= lowbit(i)){
			res -= sum[i];
		}
		return res;
	}
}gao;

int main(){
	int T, n, m, l, r;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);
		q.clear();
		x[0].clear();
		x[1].clear();
		pre.clear();
		vis.clear();
		gao.init(n);
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
		}
		for(int i = 1; i <= m; i++){
			scanf("%d%d", &l, &r);
			q.push_back(mkp(r, mkp(l, i)));
		}
		sort(q.begin(), q.end());
		int i = 1, t1 = 0, t2 = 1;
		for(int t = 0; t < q.size(); t++){
			for(; i <= n && i <= q[t].R; i++){
				t1 ^= 1, t2 ^= 1;
				x[t2].clear();
				vis.clear();
				vis.insert(a[i]);
				for(int j = x[t1].size() - 1; j >= 0; j--){
					int tmp = gcd(x[t1][j].val, a[i]);
					if(vis.find(tmp) == vis.end()){
						x[t2].push_back(mkp(tmp, x[t1][j].p));
						vis.insert(tmp);
					}
				}
				x[t2].push_back(mkp(a[i], i));
				for(int j = 0; j < x[t2].size(); j++){
					if(!pre.count(x[t2][j].val)){
						gao.update(x[t2][j].p, 1);
						pre[x[t2][j].val] = x[t2][j].p;
					}else if(pre[x[t2][j].val] < x[t2][j].p){
						gao.update(pre[x[t2][j].val], -1);
						gao.update(x[t2][j].p, 1);
						pre[x[t2][j].val] = x[t2][j].p;
					}
				}
			}
			ans[q[t].id] = gao.query(q[t].L, q[t].R);
		}
		for(int i = 1; i <= m; i++){
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}
