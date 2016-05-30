#include <stack>
#include <cstdio>
#include <list>
#include <cassert>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
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
#define MS(arr, num) memset(arr, num, sizeof(arr))
#define PB push_back
#define X first
#define Y second
#define ROP freopen("input.txt", "r", stdin);
#define MID(a, b) (a + ((b - a) >> 1))
#define LC rt << 1, l, mid
#define RC rt << 1|1, mid + 1, r
#define LRT rt << 1
#define RRT rt << 1|1
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int dir[][2] = { {-1, 0}, {0, -1}, { 1, 0 }, { 0, 1 } };
int cases = 0;
typedef std::pair<int, int> pii;

int factoies[MAXN];
LL c[MAXN];
int n;

void init() {
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            ++factoies[j];
        }
    }
}

long long read(){
	long long ans=0;
	char last=' ',ch=getchar();
	while(ch<'0' || ch>'9')last=ch,ch=getchar();
	while(ch>='0' && ch<='9')ans=ans*10+ch-'0',ch=getchar();
	if(last=='-')ans=-ans;
	return ans;
}

int main() {
    //ROP;
    int q;
    scanf("%d%d", &n, &q);
    init();
    while (q--) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int x, y;
            scanf("%d%d", &x, &y);
            for (int i = x; i <= n; i += x) {
                c[i] += y * factoies[i/x];
            }
        }
        else {
            LL ans = 0;
            int x;
            scanf("%d", &x);
            printf("%lld\n", c[x]);
        }
    }
    return 0;
}
