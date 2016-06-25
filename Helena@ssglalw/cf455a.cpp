#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#define FREAD(fn) freopen((fn), "r", stdin)
#define RINT(vn) scanf("%d", &(vn))
#define PINT(vb) printf("%d", vb)
#define RSTR(vn) scanf("%s", (vn))
#define PSTR(vn) printf("%s", (vn))
#define CLEAR(A, X) memset(A, X, sizeof(A))
#define REP(N) for(i=0; i<(N); i++)
#define REPE(N) for(i=1; i<=(N); i++)
#define pb(X) push_back(X)
#define pn() printf("\n")
using namespace std;
const int MAX_N = 100000;

int i, j, k;
int n;
int x;

int cnt[MAX_N+5];
__int64 dp[MAX_N+5];

int main()
{
    FREAD("455a.txt");
    CLEAR(cnt, 0);
    CLEAR(dp, 0);
    RINT(n);
    while(n--){
        RINT(x);
        cnt[x]++;
    }
    i = 1;
    while(cnt[i] == 0) i++;
    dp[i] = (__int64)cnt[i]*i;//first non-zero
    i++;
    dp[i] = max(dp[i-1], (__int64)cnt[i]*i);//second
    i++;
    while(i <= MAX_N){
        dp[i] = max(dp[i-1], dp[i-2] + (__int64)cnt[i]*i);
        i++;
    }
    printf("%I64d\n", dp[MAX_N]);
    return 0;
}
