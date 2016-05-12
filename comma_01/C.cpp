#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct point {
    int x;
    int depth;  
};
int n,k;
bool vis[100003];

int bfs(point s)
{
    memset(vis, false, sizeof(vis));
    queue<point> q;
    q.push(s);
    vis[s.x] = true;
    
    while (!q.empty()) {
        point tmp = q.front();
        q.pop();
        if (tmp.x == k) 
            return tmp.depth;
        point next;
        if (tmp.x - 1 >= 0 && !vis[tmp.x - 1]) {
            vis[tmp.x - 1] = true;
            next.x = tmp.x - 1;
            next.depth = tmp.depth + 1;
            q.push(next);    
        }
        if (tmp.x + 1 <= 100000 && !vis[tmp.x + 1]) {
            vis[tmp.x + 1] = true;
            next.x = tmp.x + 1;
            next.depth = tmp.depth + 1;
            q.push(next);    
        }
        if (tmp.x * 2 <= 100000 && !vis[tmp.x * 2]) {
            vis[tmp.x * 2] = true;
            next.x = tmp.x * 2;
            next.depth = tmp.depth + 1;
            q.push(next);    
        }
    }
    return 0;
}

int main()
{
    while (scanf("%d%d", &n, &k) != EOF) {
        point s;
        s.x = n;
        s.depth = 0;
        printf("%d\n", bfs(s));
    }
    
    return 0;
}