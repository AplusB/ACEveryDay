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

const int maxn = 100010;
int n, m;
int x[maxn], y[maxn];
int hx[maxn], hxcnt;
int hy[maxn], hycnt;
int sx[maxn], sy[maxn];
map<int, multiset<int> > xx;
map<int, multiset<int> > yy;
multiset<int>::iterator it;

inline bool scan_d(int &num) {
    char in;bool IsN=false;
    in=getchar();
    if(in==EOF) return false;
    while(in!='-'&&(in<'0'||in>'9')) in=getchar();
    if(in=='-'){ IsN=true;num=0;}
    else num=in-'0';
    while(in=getchar(),in>='0'&&in<='9'){
            num*=10,num+=in-'0';
    }
    if(IsN) num=-num;
    return true;
}

int getid(int* h, int hcnt, int x) {
	return lower_bound(h, h+hcnt, x) - h;
}

int main() {
	// FRead();
	int c, d;
	while(~scanf("%d%d", &n, &m) && n + m) {
		Cls(sx); Cls(sy); xx.clear(), yy.clear();
		Rep(i, n) {
			scan_d(x[i]); scan_d(y[i]);
			hx[i] = x[i]; hy[i] = y[i];
			xx[x[i]].insert(y[i]);
			yy[y[i]].insert(x[i]);
		}
		sort(hx, hx+n); sort(hy, hy+n);
		hxcnt = unique(hx, hx+n) - hx;
		hycnt = unique(hy, hy+n) - hy;
		Rep(i, n) {
			sx[getid(hx, hxcnt, x[i])]++;
			sy[getid(hy, hycnt, y[i])]++;
		}
		Rep(i, m) {
			scan_d(c); scan_d(d);
			if(c == 0) {
				printf("%d\n", xx[d].size());
				for(it = xx[d].begin(); it != xx[d].end(); it++) {
					yy[*it].erase(d);
				}
				xx[d].clear();
				sx[getid(hx, hxcnt, d)] = 0;
			}
			else {
				printf("%d\n", yy[d].size());
				for(it = yy[d].begin(); it != yy[d].end(); it++) {
					xx[*it].erase(d);
				}
				sy[getid(hy, hycnt, d)] = 0;
				yy[d].clear();
			}
		}
		printf("\n");

	}
	return 0;
}
