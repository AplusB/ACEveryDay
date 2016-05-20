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
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef map<string, int> msi;
typedef vector<LL> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;

const int maxn = 10010;
int n, in[maxn];
vector<int> G[maxn];
int pre[maxn];
bool vis[maxn];
int u, v;

int find(int x) {
	return x == pre[x] ? x : pre[x] = find(pre[x]);
}

void unite(int x, int y) {
	x = find(x); y = find(y);
	if(x != y) pre[y] = x;
}

void dfs(int u) {
	vis[u] = 1;
	if(u == ::u && vis[::v]) printf("%d\n", find(::v));
	if(u == ::v && vis[::u]) printf("%d\n", find(::u));
	Rep(i, G[u].size()) {
		if(!vis[G[u][i]]) {
			dfs(G[u][i]);
			unite(u, G[u][i]);
		}
	}
}

int main() {
	// FRead();
	int T;
	Rint(T);
	W(T) {
		Cls(in); Cls(vis);
		Rep(i, maxn) G[i].clear(), pre[i] = i;
		Rint(n);
		Rep(i, n-1) {
			Rint(u); Rint(v);
			G[u].push_back(v); in[v]++;
		}
		Rint(u); Rint(v);
		For(i, 1, n+1) if(!in[i]) dfs(i);
	}
	RT 0;
}
