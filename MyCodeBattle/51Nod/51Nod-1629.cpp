#include <stack>
#include <cstdio>
#include <list>
#include <cassert>
#include <set>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <functional>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <cmath>
#define LL long long
#define ULL unsigned long long
#define SZ(x) (int)x.size()
#define Lowbit(x) ((x) & (-x))
#define MP(a, b) make_pair(a, b)
#define MS(p, num) memset(p, num, sizeof(p))
#define PB push_back
#define X first
#define Y second
#define ROP freopen("input.txt", "r", stdin);
#define MID(a, b) (a + ((b - a) >> 1))
#define LC rt << 1, l, mid
#define RC rt << 1|1, mid + 1, r
#define LRT rt << 1
#define RRT rt << 1|1
#define FOR(i, a, b) for (int i=(a); (i) < (b); (i)++)
#define FOOR(i, a, b) for (int i = (a); (i)<=(b); (i)++)
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int MAXN = 100000+10;
const int MOD = 1e9 + 7;
const int dir[][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
//const int seed = 131;
int cases = 0;
typedef std::pair<int, int> pii;

double getv(double l, double r) {
    return 1.0/3*PI*r*r*sqrt(l*l-r*r);
}

int main() {
    double S;
    std::cin >> S;
    double left = 0.0000001, right = sqrt(S/(2*PI)), midmid_v, mid_v;
    for (int i = 0; i < 100; ++i) {
        double mid = (left+right)/2, midmid = (mid + right)/2;
        double mid_l = (S-PI*mid*mid) / (PI*mid);
        mid_v = getv(mid_l, mid);

        double midmid_l = (S-PI*midmid*midmid) / (PI*midmid);
        midmid_v = getv(midmid_l, midmid);

        if (mid_v > midmid_v) {
            right = midmid;
        }
        else left = mid;
    }
    printf("%.6f\n", mid_v);
    return 0;
}
