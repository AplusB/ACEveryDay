#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 111;
const long long INF = (long long) 1e14;
int a[N][N];
long long dp[2 * N][N][N];

int dir[2][2] = {{1, 0}, {0, 1}};
inline void Update(long long &x, long long y)
{
    if(y > x) {
        x = y;
    }
}
int n;
inline bool valid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}
int main()
{
    while(cin >> n)
    {

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        for(int i = 0; i < 2 * n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    dp[i][j][k] = -INF;
                }
            }
        }
        dp[0][0][0] = a[0][0];
        for(int i = 1; i <= 2*n-2; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) if(dp[i - 1][j][k] != -INF){
                    for(int d1 = 0; d1 < 2; d1++) {
                        for(int d2 = 0; d2 < 2; d2++) {
                            int x = j, y = i - 1 - j;
                            x += dir[d1][0]; y += dir[d1][1];
                            int tx = k, ty = i - 1 - k;
                            tx += dir[d2][0]; ty += dir[d2][1];

                            if(valid(x, y) && valid(tx, ty)) {
                                if(x == tx && y == ty) {
                                    Update(dp[i][x][tx], dp[i - 1][j][k] + a[x][y]);
                                } else {
                                    Update(dp[i][x][tx], dp[i - 1][j][k] + a[x][y] + a[tx][ty]);
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << dp[2 * n - 2][n - 1][n - 1] << endl;
    }
    return 0;
}
