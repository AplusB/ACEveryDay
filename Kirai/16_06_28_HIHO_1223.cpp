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
#define Rll(a) scanf("%I64d", &a)
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
	char p[5];
	int c;
}Node;

const int maxn = 1100;
int n;
char qx[5];
Node k[maxn];

int main() {
	// FRead();
	while(~Rint(n)) {
		Cls(k);
		For(i, 1, n+1) {
			Rs(qx); Rs(k[i].p); Rint(k[i].c);
			k[i].c <<= 2;
		}
		int ret = 0;
		For(x, -1005, 4005) {
			int cur = 0;
			For(i, 1, n+1) {
				int len = strlen(k[i].p);
				if(k[i].p[0] == '<' && len == 1)
					if(x < k[i].c) cur++;
				if(k[i].p[0] == '<' && k[i].p[1] == '=')
					if(x <= k[i].c) cur++;
				if(k[i].p[0] == '=' && len == 1)
					if(x == k[i].c) cur++;
				if(k[i].p[0] == '>' && len == 1)
					if(x > k[i].c) cur++;
				if(k[i].p[0] == '>' && k[i].p[1] == '=')
					if(x >= k[i].c) cur++;
			}
			ret = max(ret, cur);
		}
		printf("%d\n", ret);
	}
	RT 0;
}
