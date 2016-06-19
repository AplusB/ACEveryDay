#include <cstdio>

#define REP(i, n) for(int _n = n, i = 0; i < _n; i++)
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define RFOR(i, b, a) for (int i = (b), _b = (a); i >= _b; i--)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define Abs(x) ((x) > 0 ? (x) :(-(x)))
#define L(fmt, ...) do {if(true) printf(fmt"\n", ##__VA_ARGS__);} while(false)

int cnt[1010][1010];
int dp[1010][1010][12];

char s[1010];
char t[1010];

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    scanf("%s", s + 1);
    scanf("%s", t + 1);

    //get cnt
    //
    FOR(i, 1, n) {
        FOR(j, 1, m) {
            if (s[i] == t[j]) cnt[i][j] = 1 + cnt[i - 1][j - 1];
        }
    }

    // get dp
    //
    FOR(i, 1, n) {
        FOR(j, 1, m) {
            FOR(p, 1, k) {
                if (s[i] == t[j]) {
                    int num = cnt[i][j];
                    dp[i][j][p] = num + dp[i - num][j - num][p - 1];
                    dp[i][j][p] = Max(dp[i][j][p], dp[i - 1][j][p]);
                    dp[i][j][p] = Max(dp[i][j][p], dp[i][j - 1][p]);
                } else {
                    dp[i][j][p] = Max(dp[i - 1][j][p], dp[i][j - 1][p]);
                }
            }
        }
    }
    printf("%d\n", dp[n][m][k]);
    return 0;
}
