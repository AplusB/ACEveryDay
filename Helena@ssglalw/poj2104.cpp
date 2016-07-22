#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <assert.h>
#define FREAD() freopen("input.txt", "r", stdin)
#define RINT(vn) scanf("%d", &(vn))
#define PINT(vb) printf("%d", vb)
#define RSTR(vn) scanf("%s", (vn))
#define PSTR(vn) printf("%s", (vn))
#define CLEAR(A, X) memset(A, X, sizeof(A))
#define REP(N) for(int i=0; i<(N); i++)
#define REPE(N) for(int i=1; i<=(N); i++)
#define pb(X) push_back(X)
#define pn() printf("\n")
using namespace std;

const int MAX_N = 100005;
const int MAX_M = (1<<18);//树的节点数, 2*MAX_N+1取2的幂

int n, m;
int a[MAX_N];
vector<int> node[MAX_M];
int ql, qr, qk;//查询内容，作为全局变量
int x;//中位数


void build(int k, int lo, int hi){//[lo, hi) to node[k]
	if(hi - lo == 1)
		node[k].pb(a[lo]);
	else{
		int lc = k*2+1, rc = k*2+2;
		int mi = (lo+hi)/2;
		build(lc, lo, mi);
		build(rc, mi, hi);
		node[k].resize(hi - lo);//扩容，不resize会RE
		merge(node[lc].begin(), node[lc].end(),
			node[rc].begin(), node[rc].end(), node[k].begin());//有序向量归并
	}
}

int query(int k, int lo, int hi){//[ql, qr]的
	if(ql >= hi || qr <= lo) return 0;//无交集
	if(ql <= lo && qr >= hi) return upper_bound(node[k].begin(), node[k].end(), x) - node[k].begin();//当前区间完全包含在目标区间内，先求全局位置，再减去区间起址，得区间内位置
	int mi = (lo+hi)/2;
	int nl = query(k*2+1, lo, mi);
	int nr = query(k*2+2, mi, hi);
	return nl + nr;
}

int main()
{
	FREAD();
	RINT(n); RINT(m);
	REP(n) RINT(a[i]);
	build(0, 0, n);//建树
	sort(a, a+n);//是为了便于找到每个区间的中位数？
	// REP(2*n+1){
	// 	for(int j=0; j<node[i].size(); j++){
	// 		printf("%d ", node[i][j]);
	// 	}
	// 	pn();
	// }
	while(m--){
		RINT(ql); RINT(qr); RINT(qk);
		ql--;
		int lo = -1, hi = n-1;
		while(hi - lo > 1){//二分位置
			int mi = (lo + hi) / 2;
			x = a[mi];
			int c = query(0, 0, n);//找到中位数的位置，与k比较
			// PINT(c);
			// pn();
			if(c < qk) lo = mi;
			else hi = mi;
		}
		PINT(a[hi]);
		pn();
	}
	return 0;
}
