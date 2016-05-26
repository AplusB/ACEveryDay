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
#define Rll(a) scanf("%I64d", &a)
#define Rs(a) scanf("%s", a)
#define Cin(a) cin >> a
#define FRead() freopen("in", "r", stdin)
#define FWrite() freopen("out", "w", stdout)
#define Rep(i, len) for(int i = 0; i < (len); i++)
#define For(i, a, len) for(int i = (a); i < (len); i++)
#define Cls(a) memset((a), 0, sizeof(a))
#define Clr(a, x) memset((a), (x), sizeof(a))
#define Full(a) memset((a), 0x7f7f, sizeof(a))
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

const int maxn = 100010;
int n, k;
int a[maxn];
char s[maxn];

int main() {
	// FRead();
	while(~Rint(n) && ~Rint(k)) {
		Rs(s+1);
		For(i, 1, n+1) {
			if(s[i] == 'a') a[i] = 0;
			else a[i] = 1;
		}
		int l = 1, r = 1;
		int cur = 0, ans = 0;
		while(1) {
			if(r > n) break;
			while(r <= n && cur <= k) {
				if(a[r] == 0) {
					if(cur == k) break;
					cur++;
				}
				r++;
			}
			if(r - l > ans) ans = r - l;
			while(l <= r && a[l] == 1) l++;
			cur--;
			l++;
		}
		int ret = ans;
		For(i, 1, n+1) {
			if(s[i] == 'a') s[i] = 'b';
			else s[i] = 'a';
		}
		For(i, 1, n+1) {
			if(s[i] == 'a') a[i] = 0;
			else a[i] = 1;
		}
		l = 1, r = 1; cur = 0, ans = 0;
		while(1) {
			if(r > n) break;
			while(r <= n && cur <= k) {
				if(a[r] == 0) {
					if(cur == k) break;
					cur++;
				}
				r++;
			}
			if(r - l > ans) ans = r - l;
			while(l <= r && a[l] == 1) l++;
			cur--;
			l++;
		}
		printf("%d\n", max(ans, ret));
	}
	RT 0;
}
