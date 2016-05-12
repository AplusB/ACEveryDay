#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f;
 
int m,n;
int field[17][17], change[17][17], ans[17][17];
int dx[] = {-1,0,0,0,1};
int dy[] = {0,-1,0,1,0};

int color(int x, int y)
{
    int res = field[x][y];
    for (int i = 0; i < 5; ++i) {
        int nx = dx[i] + x, ny = dy[i] + y;
        if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
            res += change[nx][ny];
        }
    }
    return res & 1;
}

// 用于计算在第一行确定的情况下总共需要的步数
int calc()
{
    // 判是否需要反转，如果碰到黑色的话就需要反转
    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (color(i - 1, j))
                change[i][j] = 1;
        }
    }
    
    // 判无法全部反转
    for (int j = 0; j < n; ++j) {
        if (color(m - 1, j)) return INF;
    }
    
    int res = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            res += change[i][j];
        }
    }
    return res;
}

int main()
{
    
    while (scanf("%d%d", &m, &n) != EOF) {
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &field[i][j]);
            }
        }
        memset(ans, 0, sizeof(ans));
        
        int res = INF;
        for (int i = 0; i < 1 << n; ++i) {
            // 第一行有2^n种情况
            memset(change, 0, sizeof(change));
            for (int j = 0; j < n; ++j) {
                change[0][j] = (i >> j) & 1;
            }
            
            int tmp = calc();
            if(tmp < res) {
                res = tmp;
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        ans[i][j] = change[i][j];
                    }
                }
            }
        }
        if (res == INF)
                printf("IMPOSSIBLE\n");
            else {
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if (j == 0) printf("%d",ans[i][j]);
                        else printf(" %d", ans[i][j]);
                    }
                    printf("\n");
                }
            }        
    }
    
    return 0;
}