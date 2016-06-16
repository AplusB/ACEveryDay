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

const int maxn = 220;
const char* zyy = "marshtomp";
const char* fjx = "fjxmlhx``";

char s[maxn], t[maxn];
int n, m;

char* cvt(char* t) {
	for(int i = 0; t[i]; i++) {
		if(t[i] >= 'A' && t[i] <= 'Z') t[i] = t[i] - 'A' + 'a';
	}
	return t;
}

bool ok(char* t) {
	bool flag = 1;
	Rep(i, m) {
		if(t[i] != zyy[i]) {
			flag = 0;
			break;
		}
	}
	return flag;
}

int main() {
	// FRead();
	m = strlen(zyy);
	while(gets(s)) {
		n = strlen(s);
		Rep(i, n) {
			Cls(t);
			Rep(j, m) t[j] = s[i+j];
			if(ok(cvt(t))) {
				Rep(k, m) t[k] = fjx[k];
				Rep(j, m) s[i+j] = t[j];
			}
		}
		Rep(i, n) {
			if(s[i] == '`') continue;
			printf("%c", s[i]);
 		}
		printf("\n");
	}
	RT 0;
}
