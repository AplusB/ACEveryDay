#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <stack>
#include <algorithm>

using namespace std;

const int MAX = 1000 + 3;
const int INF = 0x3f3f3f3f;

int dp[MAX][MAX];

int same(char x, char y)
{
    return x == y ? 1 : 0; 
}

int maxx(int a, int b, int c)
{
    if (a >= b && a >= c) return a;
    if (b >= a && b >= c) return b;
    return c;
}

int main()
{
    char a[MAX],b[MAX];
    while (scanf("%s %s", a, b) != EOF) {
        int len1 = strlen(a), len2 = strlen(b);
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                dp[i][j] = maxx(dp[i-1][j-1] + same(a[i-1],b[j-1]), dp[i-1][j], dp[i][j-1]);
            }
        }
        printf("%d\n", dp[len1][len2]);
    }
    
    return 0;
}