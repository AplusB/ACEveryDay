#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAX = 100 + 10;
int dp[MAX][MAX], s[MAX][MAX];
int n, k;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int dfs(int x, int y)
{
    int maxx = 0, sum, xx, yy;
    if (!dp[x][y]) {
        for (int i = 1; i <= k; ++i) {
            for (int j = 0; j < 4; ++j) {
                xx = x + dx[j] * i;
                yy = y + dy[j] * i;
                if (xx >= 0 && xx < n && yy >= 0 && yy < n && s[xx][yy] > s[x][y]) {
                    sum = dfs(xx, yy);
                    maxx = max(maxx, sum);
                }
            }
        }
        dp[x][y] = maxx + s[x][y];
    }
    return dp[x][y];
}

int main()
{
    while (scanf("%d%d", &n, &k), n != -1, k != -1) {
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &s[i][j]);
            }
        }
        memset(dp, 0, sizeof(dp));
        printf("%d\n", dfs(0,0));
    }
    
    return 0;
}