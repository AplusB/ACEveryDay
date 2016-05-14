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
#define Rint(a) scanf("%d", &a)
#define Rll(a) scanf("%I64d", &a)
#define Rs(a) scanf("%s", a)
#define FRead() freopen("in", "r", stdin)
#define FWrite() freopen("out", "w", stdout)
#define Rep(i, n) for(int i = 0; i < (n); i++)
#define For(i, a, n) for(int i = (a); i < (n); i++)
#define Cls(a) memset((a), 0, sizeof(a))
#define Full(a) memset((a), 0x7f7f, sizeof(a))

const int maxn = 1000010;
int k, cnt;
char pos[maxn];
char s[maxn];

int main() {
	// FRead();
	int T, _ = 1;
	Rint(T);
	while(T--) {
		Cls(s); Cls(pos);;
		getchar(); gets(s); Rint(k);
		int n = strlen(s); cnt = 0;
		int p = n % k;
		int r = n / k + 1;
		Rep(i, p) {
			Rep(j, r) {
				pos[i+k*j] = s[cnt++];
			}
		}
		For(i, p, k) {
			Rep(j, r-1) {
				pos[i+k*j] = s[cnt++];
			}
		}
		printf("Case #%d:\n", _++);
		printf("%s\n", pos);
	}
	return 0;
}
