/*
━━━━━┒ギリギリ♂ eye！
┓┏┓┏┓┃キリキリ♂ mind！
┛┗┛┗┛┃＼○／
┓┏┓┏┓┃ /
┛┗┛┗┛┃ノ)
┓┏┓┏┓┃
┛┗┛┗┛┃
┓┏┓┏┓┃
┛┗┛┗┛┃
┓┏┓┏┓┃
┛┗┛┗┛┃
┓┏┓┏┓┃
┃┃┃┃┃┃
┻┻┻┻┻┻
*/
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
#define cl clear
#define BUG puts("here!!!")
#define W(a) while(a--)
#define pb(a) push_back(a)
#define Rint(a) scanf("%d", &a)
#define Rll(a) scanf("%lld", &a)
#define Rs(a) scanf("%s", a)
#define Cin(a) cin >> a
#define FRead() freopen("in", "r", stdin)
#define FWrite() freopen("out", "w", stdout)
#define Rep(i, len) for(int i = 0; i < (len); i++)
#define For(i, a, len) for(int i = (a); i < (len); i++)
#define Cls(a) memset((a), 0, sizeof(a))
#define Clr(a, x) memset((a), (x), sizeof(a))
#define Full(a) memset((a), 0x7f7f, sizeof(a))
#define lrt rt << 1
#define rrt rt << 1 | 1
#define pi 3.14159265359
#define RT return
#define lowbit(x) x & (-x)
#define onenum(x) __builtin_popcount(x)
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;

typedef struct Edge {
	int u, v, w;
	Edge() {}
	Edge(int uu, int vv, int ww) : u(uu), v(vv), w(ww) {}
}Edge;
const int maxn = 10010;
const int maxm = 100010;
bool circle[maxn];
int n, m;
int pre[maxn];
Edge edge[maxm];

bool cmp(Edge a, Edge b) {
	RT a.w > b.w;
}

int find(int x) {
	return x == pre[x] ? x : pre[x] = find(pre[x]);
}

int unite(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if(fx != fy) {
		if(circle[fx] && circle[fy]) return 0;
		if(circle[fx]) pre[fy] = fx;
		else pre[fx] = fy;
		return 1;
	}
	if(fx == fy) {
		if(circle[fx]) return 0;
		circle[fx] = 1;
		return 1;
	}
}

int main() {
	// FRead();
	int u, v, c;
	while(~Rint(n) && ~Rint(m) && n + m) {
		Cls(circle);
		Rep(i, n+5) pre[i] = i;
		Rep(i, m) {
			Rint(u); Rint(v); Rint(c);
			edge[i] = Edge(u, v, c);
		}
		sort(edge, edge+m, cmp);
		int ret = 0;
		Rep(i, m) {
			if(unite(edge[i].u, edge[i].v)) {
				ret += edge[i].w;
			}
		}
		printf("%d\n", ret);
	}
	RT 0;
}
