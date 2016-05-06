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

//kirai²»ÊÇÉ³²è£¬²»»áÍü¼ÇÐÞ¸Ämaxn
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
typedef long long ll;
typedef struct Node {
	int t, v;
}Node;
const int maxn = 100010;
int n, m;
int sum[maxn<<2];

void pushUP(int rt) {
    //modify
    sum[rt] = max(sum[rt<<1], sum[rt<<1|1]);
}

void build(int l, int r, int rt) {
    if(l == r) {
    	sum[rt] = -1;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushUP(rt);
}

void update(int p, int add, int l, int r, int rt) {
    if(l == r) {
        sum[rt] = max(sum[rt], add);
        return;
    }
    int m = (l + r) >> 1;
    if(p <= m) {
        update(p, add, lson);
    }
    else {
        update(p, add, rson);
    }
    pushUP(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) {
        return sum[rt];
    }
    int m = (l + r) >> 1;
    int ret = 0;
    if(L <= m) {
        //modify
        ret = max(ret, query(L, R, lson));
    }
    if(R > m) {
        //modify
        ret = max(ret, query(L, R, rson));
    }
    return ret;
}

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d%d", &n, &m)) {
		int t, v;
		build(1, n, 1);
		for(int i = 0; i < n; i++) {
			scanf("%d%d", &t, &v);
			update(t, v, 1, n, 1);
		}
		int a, b;
		while(m--) {
			scanf("%d%d", &a, &b);
			int ans = query(a, b, 1, n, 1);
			if(ans <= 0) printf("None\n");
			else printf("%d\n", ans);
		}
	}
	return 0;
}
