 #include <bits/stdc++.h>
using namespace std;
#define lson rt << 1
#define rson rt << 1 | 1
typedef long long LL;
const int maxn = 100005;
struct SegTree{
	int l, r, flag;
}tree[maxn << 2];

void build(int l, int r, int rt){
	tree[rt].l = l;
	tree[rt].r = r;
	tree[rt].flag = 0;
	if(l == r) return;
	int mid = (l + r) >> 1;
	build(l, mid, lson);
	build(mid + 1, r, rson);
}

void update(int l, int r, int rt, int val){
	if(l <= tree[rt].l && tree[rt].r <= r){
		if(val > 0)
			tree[rt].flag = val;
		else if(-val == tree[rt].flag)
			tree[rt].flag = 0;
		return;
	}
	int mid = (tree[rt].l + tree[rt].r) >> 1;
	if(l <= mid) update(l, r, lson, val);
	if(mid < r) update(l, r, rson, val);
}

int query(int p, int rt){
	if(tree[rt].flag) return tree[rt].flag;
	if(tree[rt].l == p && p == tree[rt].r){
		return tree[rt].flag;
	}
	int mid = (tree[rt].l + tree[rt].r) >> 1;
	if(p <= mid)
		return query(p, lson);
	else
		return query(p, rson);
}

struct Seg{
	LL l, r, h;
	int c;
	Seg(){}
	Seg(LL _l, LL _r, LL _h, int _c): l(_l), r(_r), h(_h), c(_c) {}
	bool operator<(const Seg& tmp) const{
		if(h != tmp.h)
			return h < tmp.h;
		return c > tmp.c;
	}
}seg[maxn];
int tol;
vector < LL > pos;

struct Point{
	int x, y;
	void read(){
		scanf("%d%d", &x, &y);
	}
}p[maxn], p0;

LL dis(Point p1, Point p2){
	return (LL)(p1.x - p2.x) * (p1.x - p2.x) + (LL)(p1.y - p2.y) * (p1.y - p2.y);
}

int fa[maxn], cnt[maxn];

void init(int n){
	for(int i = 0; i <= n; i++){
		fa[i] = i;
		cnt[i] = 1;
	}
}

int fnd(int x){
	return fa[x] == x ? fa[x] : fa[x] = fnd(fa[x]);
}

void mrg(int x, int y){
	x = fnd(x);
	y = fnd(y);
	if(x != y){
		fa[x] = y;
		cnt[y] += cnt[x];
	}
}

int main(){
	int n, R, L, x0, y0;
	while(scanf("%d%d%d", &n, &R, &L) != EOF){\
		pos.clear();
		tol = 0;
		for(int i = 1; i <= n; i++){
			p[i].read();
			seg[tol++] = Seg(4LL * p[i].x - L, 4LL * p[i].x + L, 4LL * p[i].y - L, i);
			seg[tol++] = Seg(4LL * p[i].x - L, 4LL * p[i].x + L, 4LL * p[i].y + L, -i);
			pos.push_back(4LL * p[i].x - L);
			pos.push_back(4LL * p[i].x + L);
		}
		sort(pos.begin(), pos.end());
		pos.erase(unique(pos.begin(), pos.end()), pos.end());
		sort(seg, seg + tol);
		build(1, (int)pos.size(), 1);
		init(n);
		for(int i = 0; i < tol; i++){
			int l = lower_bound(pos.begin(), pos.end(), seg[i].l) - pos.begin() + 1;
			int r = lower_bound(pos.begin(), pos.end(), seg[i].r) - pos.begin() + 1;
			if(seg[i].c > 0){
				int t = query(l, 1);
				if(t) mrg(t, seg[i].c);
				t = query(r, 1);
				if(t) mrg(t, seg[i].c);
			}
			update(l, r, 1, seg[i].c);
		}
		p0.read();
		for(int i = 1; i <= n; i++){
			if(dis(p[i], p0) <= (LL)R * R){
				mrg(i, 0);
			}
		}
		printf("%d\n", cnt[0] - 1);
	}
	return 0;
}
