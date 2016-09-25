#include <iostream>
#include <fstream>
#include <cstring>
#include <climits>
#include <deque>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <functional>
#include <algorithm>

using namespace std;

const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int, int> PLL;
const LL INF = (1LL << 60);

int bit[40];

int cmp(int a, int b) {
    return a > b;
}

int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        LL tmp = n;
        int cnt = 0;
        int one = 0;
        while (n) {
            bit[cnt++] = n % 2;
            n /= 2;
            if (bit[cnt - 1]) {
                ++one;
            }
        }
        int pos = -1;
        bool flag = 0;
        for (int i = 0; i < cnt; ++i) {
            if (bit[i]) {
                pos = i;
            }
            else if (!bit[i] && pos != -1) {
                swap(bit[i], bit[pos]);
                flag = 1;
                break;
            }
        }
        LL ans = 0;
        if (!flag) {
            ans = 2;
            sort(bit, bit + cnt - 1, cmp);
            for (int i = cnt - 2; i >= 0; --i) {
                ans <<= 1;
                ans |= bit[i];
            }
        }
        else {
            sort(bit, bit + pos, cmp);
            for (int i = cnt - 1; i >= 0; --i) {
                ans <<= 1;
                ans |= bit[i];
            }
        }
        printf("Case %d: %lld\n", icase++, ans);
    }
    return 0;
}
