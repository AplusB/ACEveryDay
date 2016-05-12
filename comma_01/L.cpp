#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <vector>

using namespace std;

char field[103][103];
int m,n;
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

void dfs(int x, int y)
{
    field[x][y] = '*';
    
    for (int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && field[nx][ny] == '@'){
                dfs(nx,ny);
            }
        }
    }
}

int main()
{
    while (scanf("%d%d", &m, &n) != EOF && m && n) {
        int ans = 0;
        memset(field, 0, sizeof(field));
        for (int i = 0; i < m; ++i) {
            //char ch = getchar();
            //for (int j = 0; j < n; ++j) 
                scanf("%s", field[i]);
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (field[i][j] == '@') {
                    ++ans;
                    dfs(i,j);
                }
            }
        }
        printf("%d\n", ans);          
    }
    
    return 0;
}