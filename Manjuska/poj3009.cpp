#include <iostream>
#include <algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;

const int INFS = 0x3fffffff;
int grid[25][25], row, col, ans;
int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};

inline bool judge(int x, int y) {
    if (0 < x && x <= row && 0 < y && y <= col) {
        return true;
    }
    return false;
}

void dfs(int x, int y, int step) {
    if (step > 10)
        return ;

    for (int i = 0; i < 4; ++i) {
        int a = x, b = y, cflag = 0;
        while (judge(a, b)) {
            a += dir[i][0];
            b += dir[i][1];
            cflag += 1;

            if (grid[a][b] == 3) {
                ans = min(ans, step + 1);
                return ;
            }
            if (grid[a][b] == 1) 
                break ;
        }
        if (grid[a][b] == 1 && cflag > 1) {
            grid[a][b] = 0;
            dfs(a-dir[i][0], b-dir[i][1], step+1);
            grid[a][b] = 1;
        }
    }
}

int main() {

    while (scanf("%d%d", &col, &row) && col && row) {
        int x, y;
        memset(grid, 0, sizeof(grid));

        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                scanf("%d", &grid[i][j]);
                if (grid[i][j] == 2) 
                    x = i, y = j;
            }
        }

        ans = INFS;
        dfs(x, y, 0);
        if (ans <= 10)
            printf("%d\n", ans);
        else
            printf("-1\n");
    }
}
