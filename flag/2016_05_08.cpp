#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
#define lson rt << 1
#define rson rt << 1 | 1
const int maxn = 1e5 + 5;
LL a[maxn];

struct SegTree1{
	struct SegTree{
		int l, r;
		int sign, flag;
		LL x;
		void gao(LL y){
		    flag = 1;
			x = y - x;
			sign = -sign;
		}
	}tree[maxn << 2];

	void push_down(int rt){
		if(tree[rt].flag){
			tree[lson].gao(tree[rt].x);
			tree[rson].gao(tree[rt].x);
			tree[rt].flag = 0;
			tree[rt].x = 0;
		}
	}

	void build(int l, int r, int rt){
		tree[rt].l = l;
		tree[rt].r = r;
		tree[rt].flag = 0;
		tree[rt].x = 0;
		tree[rt].sign = 1;
		if(l == r) return;
		int mid = (l + r) >> 1;
		build(l, mid, lson);
		build(mid + 1, r, rson);
	}

	void update(int l, int r, int rt, LL x){
		if(l <= tree[rt].l && tree[rt].r <= r){
			tree[rt].gao(x);
			return;
		}
		push_down(rt);
		int mid = (tree[rt].l + tree[rt].r) >> 1;
		if(l <= mid)
			update(l, r, lson, x);
		if(mid < r)
			update(l, r, rson, x);
	}

	LL query(int p, int rt){
		if(p == tree[rt].l && tree[rt].r == p){
			return tree[rt].x + tree[rt].sign * a[p];
		}
		push_down(rt);
		int mid = (tree[rt].l + tree[rt].r) >> 1;
		if(p <= mid)
			return query(p, lson);
		else
			return query(p, rson);
	}

}gao1;


struct SegTree2{
	struct SegTree{
		int l, r;
		LL gcd;
	}tree[maxn << 2];

	void push_up(int rt){
		tree[rt].gcd = __gcd(tree[lson].gcd, tree[rson].gcd);
	}

	void build(int l, int r, int rt){
		tree[rt].l = l;
		tree[rt].r = r;
		if(l == r){
			tree[rt].gcd = abs(a[r] - a[r - 1]);
			return;
		}
		int mid = (l + r) >> 1;
		build(l, mid, lson);
		build(mid + 1, r, rson);
		push_up(rt);
	}

	void update(int p, int rt, LL val){
		if(p == tree[rt].l && tree[rt].r == p){
			tree[rt].gcd = val;
			return;
		}
		int mid = (tree[rt].l + tree[rt].r) >> 1;
		if(p <= mid)
			update(p, lson, val);
		else
			update(p, rson, val);
        push_up(rt);
	}

	LL query(int l, int r, int rt){
		if(l <= tree[rt].l && tree[rt].r <= r){
			return tree[rt].gcd;
		}
		int mid = (tree[rt].l + tree[rt].r) >> 1;
		LL res = -1;
		if(l <= mid)
			res = query(l, r, lson);
		if(mid < r){
			LL tmp = query(l, r, rson);
			if(res == -1)
				res = tmp;
			else
				res = __gcd(res, tmp);
		}
		return res;
	}

}gao2;

int main(){
	int n, m, type, l, r, x;
	while(scanf("%d%d", &n, &m) != EOF){
		for(int i = 1; i <= n; i++){
			scanf("%lld", &a[i]);
		}
		gao1.build(1, n, 1);
		gao2.build(2, n, 1);
		for(int i = 1; i <= m; i++){
			scanf("%d", &type);
			if(type == 1){
				scanf("%d%d%d", &l, &r, &x);
				gao1.update(l, r, 1, x);
				if(l != 1){
					gao2.update(l, 1, abs(gao1.query(l, 1) - gao1.query(l - 1, 1)));
				}
				if(r != n){
					gao2.update(r + 1, 1, abs(gao1.query(r + 1, 1) - gao1.query(r, 1)));
				}
			}else{
				scanf("%d%d", &l, &r);
				if(l == r)
					printf("%lld\n", gao1.query(l, 1));
				else
					printf("%lld\n", __gcd(gao1.query(l, 1), gao2.query(l + 1, r, 1)));
			}
		}
	}
	return 0;
}
