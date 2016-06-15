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

const int maxn = 110;
string s, t, f;
bool vis[maxn];
int n, m, k;
int ret;

int check(int p, char c) {
    t.cl(); f.cl();
    if(p == 0) {
        t.pb(c);
        Rep(i, n) t.pb(s[i]);
    }
    else if(p == n) {
        t = s;
        t.pb(c);
    }
    else {
        Rep(i, p) t.pb(s[i]);
        t.pb(c);
        For(i, p, n) t.pb(s[i]);
    }
    while(1) {
        bool exflag = 1;
        m = t.length();
        f.cl(); Cls(vis);
        Rep(i, m-1) {
            if(t[i] == t[i+1]) {
                vis[i] = 1;
                vis[i+1] = 1;
                exflag = 0;
            }
        }
        Rep(i, m) {
            if(!vis[i]) {
                f.pb(t[i]);
            }
        }
        t = f;
        if(exflag) break;
    }
    return n + 1 - m;
}

int main() {
    // FRead();
    int T;
    Rint(T);
    W(T) {
        cin >> s;
        n = s.length();
        ret = 0;
        For(i, 0, n+1) {
            ret = max(ret, check(i, 'A'));
            ret = max(ret, check(i, 'B'));
            ret = max(ret, check(i, 'C'));
        }
        printf("%d\n", ret);
    }
    RT 0;
}
