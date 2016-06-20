
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
#define Full(a) memset((a), 0x7f7f7f, sizeof(a))
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
typedef pair<LL, LL> pll;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;

typedef struct Node {
	Node* l;
	Node* r;
	LL d;
	Node() { l = NULL; r = NULL; }
}Node;

const int maxn = 100100;
int n;
LL d;
char c[5];
Node nodes[maxn];
int cnt;
LL ret;

Node* insert(Node* rt, Node* p) {
	if(rt == NULL) {
		rt = &nodes[cnt++];
		rt->l = NULL;
		rt->r = NULL;
		rt->d = d;
		return rt;
	}
	if(d < rt->d) rt->l = insert(rt->l, rt);
	if(d > rt->d) rt->r = insert(rt->r, rt);
	return rt;
}

void find(Node* rt) {
	if(rt == NULL) return;
	if(rt->d <= d) ret = max(ret, rt->d);
	if(rt->d == d) return;
	if(rt->d > d) find(rt->l);
	if(rt->d < d) find(rt->r);
}

int main() {
	// FRead();
	while(~Rint(n)) {
		Node* rt = NULL;
		Cls(nodes);	cnt = 0;
		W(n) {
			Rs(c);
			if(c[0] == 'I') {
				cin >> d;
				rt = insert(rt, NULL);
			}
			if(c[0] == 'Q') {
				cin >> d;
				ret = -0x7f7f7f7f;
				if(rt->d <= d) ret = max(ret, rt->d);
				find(rt);
				cout << ret << endl;
			}
		}
	}
	RT 0;
}
