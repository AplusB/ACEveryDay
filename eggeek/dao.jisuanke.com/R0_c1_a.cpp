#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <random>
#include <cmath>
#include <ctime>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>
#include <limits>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <array>
#include <list>
#include <map>
#include <set>
using namespace std;
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) int((a).size())
#define MP(x, y) make_pair((x),(y))
#define FI first
#define SE second
#define LOWB(x) (x & (-x))
#define UNIQUE(a) sort(ALL(a)), (a).erase(unique(ALL(a)), (a).end())
#define HEIGHT(n) (sizeof(int) * 8 - __builtin_clz(n)) //height of range n segment tree
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template<class T> inline T min(T a, T b, T c) {return min(min(a,b),c);}
template<class T> inline T min(T a, T b, T c, T d) {return min(min(a,b),min(c,d));}
template<class T> inline T max(T a, T b, T c) {return max(max(a,b),c);}
template<class T> inline T max(T a, T b, T c, T d) {return max(max(a,b),max(c,d));}
const int INF = 1e9;
const ll INF_LL = 4e18;
const double pi = acos(-1.0);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
/*-----------------------------------*/

int finds(string s, int l, int r, char c) {
    int res = -1;
    for (int i=l; i<r; i++) if (s[i] == c) res = i;
    return res;
}

string no_syb(string s) {
    if (s[0] == '+' || s[0] == '-') return s.substr(1, s.size());
    else return s;
}

string no_lead_zero(string s) {
    int id = 0, t=-1;
    for (int i=0; i<SZ(s); i++) {
        if (s[i] != '0') {
            t = i;
            break;
        }
        id = i;
    }
    if (t == -1) {
        return "0";
    } else if (s[t] == '.') {
        return "0." + s.substr(t+1, s.size());
    } else {
        return s.substr(t, s.size());
    }
}

string no_tail_zero(string s) {
    int dot = finds(s, 0, s.size(), '.');
    if (dot == -1) return s;
    else {
        int tail = -1;
        for (int i=s.size()-1; i>=0; i--) {
            if (s[i] == '0') tail = i;
            else break;
        }
        if (tail != -1) {
            if (s[tail-1] == '.') {
                return s.substr(0, dot);
            } else {
                return s.substr(0, tail);
            }
        }
        return s;
    }
}

string format_f(string s) {
    int dot = finds(s, 0, s.size(), '.');
    bool sym = true;
    if (s[0] == '-') sym = false;

    s = no_syb(s);
    s = no_lead_zero(s);
    if (dot != -1)
        s = no_tail_zero(s);
    if (!sym) s = "-" + s;
    return s;
}

string format_n(string s) {
    bool sym = true;
    if (s[0] == '-') sym = false;

    s = no_syb(s);
    s = no_lead_zero(s);
    if (!sym) return "-" + s;
    return s;
}

string solve(string s) {
    for (int i=0; i<SZ(s); i++) {
        if (s[i] == 'e') {
            string a = format_f(s.substr(0, i));
            string b = format_n(s.substr(i+1, s.size()));
            return a + "e" + b;
        }
    }
    return "";
}

int main() {
    string s;
    while (cin >> s) {
        cout << solve(s) << endl;
    }
    return 0;
}
