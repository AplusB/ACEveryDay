#include <bits/stdc++.h>
using namespace std;
#define lson rt << 1
#define rson rt << 1 | 1
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 2005;
vector < int > p;
struct SegTree{
	int l, r, flag;
	int sum1, sum2, sum3;
}tree[maxn << 2];

void push_up(int rt){
	if(tree[rt].flag){
		tree[rt].sum1 = p[tree[rt].r] - p[tree[rt].l];
	}else if(tree[rt].l + 1 == tree[rt].r){
		tree[rt].sum1 = 0;
	}else{
		tree[rt].sum1 = tree[lson].sum1 + tree[rson].sum1;
	}
	if(tree[rt].flag > 1){
		tree[rt].sum2 = p[tree[rt].r] - p[tree[rt].l];
	}else if(tree[rt].l + 1 == tree[rt].r){
		tree[rt].sum2 = 0;
	}else if(tree[rt].flag == 1){
		tree[rt].sum2 = tree[lson].sum1 + tree[rson].sum1;
	}else{
		tree[rt].sum2 = tree[lson].sum2 + tree[rson].sum2;
	}
	if(tree[rt].flag > 2){
		tree[rt].sum3 = p[tree[rt].r] - p[tree[rt].l];
	}else if(tree[rt].l + 1 == tree[rt].r){
		tree[rt].sum3 = 0;
	}else if(tree[rt].flag == 2){
		tree[rt].sum3 = tree[lson].sum1 + tree[rson].sum1;
	}else if(tree[rt].flag == 1){
		tree[rt].sum3 = tree[lson].sum2 + tree[rson].sum2;
	}else{
		tree[rt].sum3 = tree[lson].sum3 + tree[rson].sum3;
	}
}

void build(int l, int r, int rt){
	tree[rt].l = l;
	tree[rt].r = r;
	tree[rt].flag = 0;
	tree[rt].sum1 = tree[rt].sum2 = tree[rt].sum3 = 0;
	if(l + 1 == r) return;
	int mid = (l + r) >> 1;
	build(l, mid, lson);
	build(mid, r, rson);
}

void update(int l, int r, int rt, int val){
	if(l <= tree[rt].l && tree[rt].r <= r){
		tree[rt].flag += val;
		push_up(rt);
		return ;
	}
	int mid = (tree[rt].l + tree[rt].r) >> 1;
	if(l < mid)
		update(l, r, lson, val);
	if(mid < r)
		update(l, r, rson, val);
	push_up(rt);
}

struct Seg{
	int l, r, h, d;
	Seg(){ }
	Seg(int _l, int _r, int _h, int _d): l(_l), r(_r),  h(_h), d(_d) { }
	bool operator<(const Seg& tmp) const{
		return h < tmp.h;
	}
}seg[maxn];

struct Cube{
	int x1, y1, z1, x2, y2, z2;
	void read(){
		scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
	}
}cube[maxn];
vector < int > Z;

LL Area(int z1, int z2, int n){
	p.clear();
	int tol = 0;
	for(int i = 1; i <= n; i++){
		if(cube[i].z1 <= z1 && z2 <= cube[i].z2){
			seg[tol++] = Seg(cube[i].x1, cube[i].x2, cube[i].y1, 1);
			seg[tol++] = Seg(cube[i].x1, cube[i].x2, cube[i].y2, -1);
			p.push_back(cube[i].x1);
			p.push_back(cube[i].x2);
		}
	}
	p.push_back(-INF);
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());
	sort(seg, seg + tol);
	build(1, (int)(p.size() - 1), 1);
	LL ans = 0;
	for(int i = 0; i < tol; i++){
		int l = lower_bound(p.begin(), p.end(), seg[i].l) - p.begin();
		int r = lower_bound(p.begin(), p.end(), seg[i].r) - p.begin();
		update(l, r, 1, seg[i].d);
		ans += (LL)tree[1].sum3 * (seg[i + 1].h - seg[i].h);
	}
	return ans;
}

int main(){
	int T, n;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++){
		scanf("%d", &n);
		Z.clear();
		for(int i = 1; i <= n; i++){
			cube[i].read();
			Z.push_back(cube[i].z1);
			Z.push_back(cube[i].z2);
		}
		sort(Z.begin(), Z.end());
		Z.erase(unique(Z.begin(), Z.end()), Z.end());
		LL ans = 0;
		for(int i = 1; i < Z.size(); i++){
			ans += Area(Z[i - 1], Z[i], n) * (Z[i] - Z[i - 1]);
		}
		printf("Case %d: %lld\n", cas, ans);
	}
	return 0;
}
