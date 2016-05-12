#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>

using namespace std;

#define fr first
#define sc second
#define pb(a) push_back(a)
#define Rint(a) scanf("%d", &a)
#define Rll(a) scanf("%I64d", &a)
#define Rs(a) scanf("%s", a)
#define FRead() freopen("in", "r", stdin)
#define FWrite() freopen("out", "w", stdout)
#define Rep(i, n) for(int i = 0; i < (n); i++)
#define For(i, a, n) for(int i = (a); i < (n); i++)
#define Cls(a) memset((a), 0, sizeof(a))
#define Full(a) memset((a), 0x7f7f, sizeof(a))

const int maxn = 1000010;
int n, m;
int cnt, root[maxn], a[maxn], x, y, k;
typedef struct Node {
	int l, r, sum;
}Node;
vector<int> v;
Node hjt[maxn*40];

int getid(int x) {
	return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

void update(int l, int r, int& x, int y, int pos) {
	hjt[++cnt] = hjt[y], hjt[cnt].sum++, x = cnt;
	if(l == r) return;
	int mid = (l + r) >> 1;
	if(mid >= pos) update(l, mid, hjt[x].l, hjt[y].l, pos);
	else update(mid+1, r, hjt[x].r, hjt[y].r, pos);
}

int query(int l, int r, int x, int y, int k) {
	if(l == r) return l;
	int mid = (l + r) >> 1;
	int sum = hjt[hjt[y].l].sum - hjt[hjt[x].l].sum;
	if(sum >= k) return query(l, mid, hjt[x].l, hjt[y].l, k);
	else return query(mid+1, r, hjt[x].r, hjt[y].r, k-sum);
}

int main() {
	// FRead();
	Rint(n); Rint(m);
	For(i, 1, n+1) {
		Rint(a[i]);
		v.pb(a[i]);
	}
	sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end());
	For(i, 1, n+1) update(1, n, root[i], root[i-1], getid(a[i]));
	For(i, 1, m+1) {
		Rint(x), Rint(y), Rint(k);
		printf("%d\n", v[query(1, n, root[x-1], root[y], k)-1]);
	}
	return 0;
}
