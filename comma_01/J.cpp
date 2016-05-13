#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <vector>

using namespace std;

char field[1003][1003];
bool vis[1003][1003];
int m,n;
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};

struct point{
  int x, y;
  int cnt;  
  bool flag;
}q1[1000003];

int bfs()
{
    memset(vis, false, sizeof(vis));
    //queue<point> q1;
    memset(q1, 0, sizeof(q1));
    //q1.push(F), q1.push(J);
    int head = 0, tail = 0;
    point J;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (field[i][j] == 'J') J = (point){i,j,0,false};
            if (field[i][j] == 'F') {
                q1[tail++] = (point){i,j,0,true};
                vis[i][j] = true;
            }
        }
    }
    q1[tail++] = J;
    vis[J.x][J.y] = true;    
    
    while (head < tail) {
        //point t1 = q1.front();
        //q1.pop();
        point t1 = q1[head++];
        
        if (!t1.flag && (t1.x == 0 || t1.y == 0 || t1.x == m - 1 || t1.y == n - 1)) {
            return t1.cnt;
        }
        
        for (int i = 0; i < 4; ++i) {
            point tmp = (point){t1.x + dx[i], t1.y + dy[i], 0, t1.flag};
            if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < m && tmp.y < n) {
               if (field[tmp.x][tmp.y] == '.' && !vis[tmp.x][tmp.y]) {
                    vis[tmp.x][tmp.y] = true;
                    if (tmp.flag) field[tmp.x][tmp.y] = 'F';
                    else tmp.cnt = t1.cnt + 1;
                    //q1.push(tmp);
                    q1[tail++] = tmp;
                }
            }
        }       
    }
    
    return -1;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &m, &n);
        getchar();
        for (int i = 0; i < m; ++i) {
            //getchar();
            for (int j = 0; j < n; ++j) {
                scanf("%c", &field[i][j]);
            }
            getchar();
        }
        int ans = bfs();
        if (ans == -1) puts("IMPOSSIBLE");
        else printf("%d\n", ans + 1);
    }
    
    return 0;
}

/*
2 
4 4 
####
#JF#
#..#
#..#
3 3
###
#J.
#.F
*/