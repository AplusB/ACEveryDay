
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
#define FREAD(fn) freopen((fn), "r", stdin)
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
const int MAX_N = (1<<20);//注意要把最大值扩展到2的幂次
const int INFP = 0x7fffffff;
const int INFN = -0x7fffffff;

int n, m;//m为大于n的最小的2的幂
int a[MAX_N], b[MAX_N];
int ta[MAX_N][32], tb[MAX_N][32];//spare table, t[i][j],i为起点，2^j为区间长度

void build_max(){
	for(int i=n; i<m; i++) a[i] = INFN;//负无穷填充
	REP(m) ta[i][0] = a[i];
	for(int j=1; j<__builtin_ctz(m); j++){//m即区间长度的上限
		for(int i=0; i+(1<<j) <= m; i++){
			ta[i][j] = max(ta[i][j-1], ta[i+(1<<(j-1))][j-1]);
		}
	}
}

void build_min(){
	for(int i=n; i<m; i++) b[i] = INFP;//正无穷填充
	REP(m) tb[i][0] = b[i];
	for(int j=1; j<__builtin_ctz(m); j++){//m即区间长度的上限
		for(int i=0; i+(1<<j) <= m; i++){
			tb[i][j] = min(tb[i][j-1], tb[i+(1<<(j-1))][j-1]);
		}
	}
}

//闭区间
int qmax(int l, int r){
	int k = log(r-l+1)/log(2.0);
	return max(ta[l][k], ta[r-(1<<k)+1][k]);
}

int qmin(int l, int r){
	int k = log(r-l+1)/log(2.0);
	return min(tb[l][k], tb[r-(1<<k)+1][k]);
}

//左闭右开，l为起始点
int lowerbound(int l){
	int lo = l, hi = n;//初始左右界桩
	int ans = n;//失败返回右界桩
	while(lo < hi){
		int mi = (lo+hi)/2;
		int qa = qmax(l, mi);
		int qb = qmin(l, mi);
		if(qa > qb) hi = mi;
		else if(qa < qb) lo = mi+1;
		else{
			ans = min(ans, mi);//命中而左移和未命中而左移是不同的！
			hi = mi;
		}

	}
	return ans;
}
int upperbound(int l){
	int lo = l, hi = n;
	int ans = -1;
	while(lo < hi){
		int mi = (lo+hi)/2;
		int qa = qmax(l, mi);
		int qb = qmin(l, mi);
		if(qa > qb) hi = mi;
		else if(qa < qb) lo = mi+1;
		else{
			ans = max(ans, mi);
			lo = mi+1;
		}
	}
	return ans;
}

int main(){
	//FREAD("689d.txt");
	RINT(n);
	m = 1;
	while(m < n) m <<= 1;//扩展为2的幂
	REP(n) RINT(a[i]);
	REP(n) RINT(b[i]);
	build_max();
	build_min();
	__int64 ans = 0;
	int rmin = 0, rmax = 0;
	REP(n){//for each left end = i, enumerate rmin, rmax
		rmin = lowerbound(i);
		rmax = upperbound(i);
		if(rmin <= rmax)
            ans += rmax - rmin + 1;
		//printf("left = %d, rmin = %d, rmax = %d\n", i, rmin, rmax);
	}
	cout << ans;
	return 0;
}
