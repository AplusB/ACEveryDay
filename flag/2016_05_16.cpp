#include <bits/stdc++.h>
using namespace std;
#define lson rt << 1
#define rson rt << 1 | 1
typedef long long LL;
const int maxn = 21000;
struct SegTree{
	int l, r;
	int flag[5], sum[8];
}tree[maxn << 2];
vector < int > p;

void push_up(int rt){
	int st = (tree[rt].flag[1] > 0 ? 1 : 0) | (tree[rt].flag[2] > 0 ? 2 : 0) | (tree[rt].flag[4] > 0 ? 4 : 0);
	if(st){
		memset(tree[rt].sum, 0, sizeof tree[rt].sum);
		tree[rt].sum[st] = p[tree[rt].r] - p[tree[rt].l];
		for(int i = 1; i < 8; i++){
			if(st != (st | i)){
				int tmp = tree[lson].sum[i] + tree[rson].sum[i];
				tree[rt].sum[st | i] += tmp;
				tree[rt].sum[st] -= tmp;
			}
		}
	}else if(tree[rt].l + 1 == tree[rt].r){
		memset(tree[rt].sum, 0, sizeof tree[rt].sum);
	}else{
		for(int i = 1; i < 8; i++){
			tree[rt].sum[i] = tree[lson].sum[i] + tree[rson].sum[i];
		}
	}
}

void build(int l, int r, int rt){
	tree[rt].l = l;
	tree[rt].r = r;
	memset(tree[rt].flag, 0, sizeof tree[rt].flag);
	memset(tree[rt].sum, 0, sizeof tree[rt].sum);
	if(l + 1 == r) return ;
	int mid = (l + r) >> 1;
	build(l, mid, lson);
	build(mid, r, rson);
}

void update(int l, int r, int rt, int c){
	if(l <= tree[rt].l && tree[rt].r <= r){
		tree[rt].flag[abs(c)] += (c > 0 ? 1 : -1);
		push_up(rt);
		return;
	}
	int mid = (tree[rt].l + tree[rt].r) >> 1;
	if(l < mid) update(l, r, lson, c);
	if(mid < r) update(l, r, rson, c);
	push_up(rt);
}

struct Seg{
	int l, r, h, c;
	Seg(){}
	Seg(int _l, int _r, int _h, int _c): l(_l), r(_r), h(_h), c(_c) {}
	bool operator<(const Seg& tmp) const{
		return h < tmp.h;
	}
}seg[maxn];
int tol;
int state[300], id[8];
LL ans[8];

int main(){
	state['R'] = 1; state['G'] = 2; state['B'] = 4;
	id[1] = 1; id[2] = 2; id[3] = 4; id[4] = 3; id[5] = 5; id[6] = 6; id[7] = 7;
	int T, n, x1, y1, x2, y2;
	char c[3];
	scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++){
		scanf("%d", &n);
		if(!n){
			printf("Case %d:\n", cas);
			for(int i = 1; i <= 7; i++) puts("0");
			continue;
		}
		p.clear();
		tol = 0;
		for(int i = 1; i <= n; i++){
			scanf("%s%d%d%d%d", c, &x1, &y1, &x2, &y2);
			seg[tol++] = Seg(x1, x2, y1, state[c[0]]);
			seg[tol++] = Seg(x1, x2, y2, -state[c[0]]);
			p.push_back(x1);
			p.push_back(x2);
		}
		p.push_back(-1);
		sort(p.begin(), p.end());
		p.erase(unique(p.begin(), p.end()), p.end());
		sort(seg, seg + tol);
		build(1, (int)p.size() - 1, 1);
		memset(ans, 0, sizeof ans);
		for(int i = 0; i < tol; i++){
			int l = lower_bound(p.begin(), p.end(), seg[i].l) - p.begin();
			int r = lower_bound(p.begin(), p.end(), seg[i].r) - p.begin();
			update(l, r, 1, seg[i].c);
			for(int j = 1; j < 8; j++){
				ans[j] += (LL)tree[1].sum[j] * (seg[i + 1].h - seg[i].h);
			}
		}
		printf("Case %d:\n", cas);
		for(int i = 1; i <= 7; i++){
			printf("%lld\n", ans[id[i]]);
		}
	}
	return 0;
}
