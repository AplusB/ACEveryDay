#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct point
{
    long long x;
    int cnt;
};

long long bfs(int n)
{
    queue<point> q;
    point a;
    a.x = 1, a.cnt = 0;
    q.push(a);
    
    while (!q.empty()) {
        point tmp = q.front(), next;
        q.pop();
        if (tmp.x % n == 0) return tmp.x;
        next.x = tmp.x * 10, next.cnt = tmp.cnt + 1;
        q.push(next);
        next.x += 1;
        q.push(next);
    }
    
    return -1;
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF && n) {
        printf("%lld\n", bfs(n));
    }
    
    return 0;
}