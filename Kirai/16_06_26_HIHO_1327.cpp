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

const int maxn = 100100;
char s[maxn], ret[maxn];
int cnt[266];
int n;

bool ok(char p, int m) {
	int k = 0;
	For(i, 'a', 'z'+1) k = max(k, cnt[i]);
	if(cnt[p] == k) return k <= m / 2;
	return k <= (m + 1) / 2;
}

int main() {
	// FRead();
	Cls(cnt); Cls(ret);
	Rs(s); n = strlen(s);
	Rep(i, n) cnt[s[i]]++;
	bool flag = 1;
	Rep(i, n) {
		bool cur = 0;
		For(j, 'a', 'z'+1) {
			if(cnt[j] > 0 && (i == 0 || j != ret[i-1])) {
				cnt[j]--;
				if(ok(j, n-i-1)) {
					ret[i] = j;
					cur = 1;
					break;
				}
				else cnt[j]++;
			}
		}
		if(!cur) {
			flag = 0;
			break;
		}
	}
	if(flag) printf("%s\n", ret);
	else printf("INVALID\n");
	RT 0;
}
