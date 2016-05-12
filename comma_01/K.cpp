#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int field[7][7];
bool vis[7][7];
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};

struct point {
    int x,y;  
    //int cnt;
    int before;
}q[107];

void dfs(int n)
{
    if (n < 0) return;
    dfs(q[n].before);
    printf("(%d, %d)\n",q[n].x, q[n].y);
    
}

void bfs()
{
    point t;
    vis[0][0] = true;
    t.x = 0, t.y = 0, 
    //t.cnt = 0, 
    t.before = -1;
    q[0] = t;
    int head = 0, tail = 1;
    while (head < tail) {
        point tmp = q[head++];
       // cout << 0 << endl;
        if (tmp.x == 4 && tmp.y == 4) {
            dfs(head - 1);
           // cout << 1 << endl;
            break;
        }
       // cout << 2 << endl;
        for (int i = 0; i < 4; ++i) {
            point n;
            n.x = tmp.x + dx[i];
            n.y = tmp.y + dy[i];
            if (n.x >= 0 && n.x < 5 && n.y >= 0 && n.y < 5) {
                if (!vis[n.x][n.y] && !field[n.x][n.y]) {
                    vis[n.x][n.y] = true;
                    //n.cnt = tmp.cnt + 1;
                    n.before = head - 1;
                    q[tail++] = n;
                }
            }
            
        }
       // cout << 3 << endl;
    }   
}

int main()
{
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            scanf("%d", &field[i][j]);
        }
    }      
    bfs();
    
    return 0;
}