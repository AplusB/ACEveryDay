#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
int a[10][10];
int b[10][10];
int n, m, q, re;

int calc(int x, int y)
{
    if(a[x][y] == 1) return 0;
    int b = 0;
    for(int i = y-1; i >= 0; i--)
    {
        if(a[x][i] == 1) b++;
        else if(a[x][i] == 2)
        {
            if(b == 1) return 0;
            else b++;
        }
    }
    b = 0;
    for(int i = x-1; i >= 0; i--)
    {
        if(a[i][y] == 1) b++;
        else if(a[i][y] == 2)
        {
            if(b == 1)return 0;
            else b++;
        }
    }
    return 1;
}

void dfs(int x, int y, int cnt)
{
    int tx = x / n, ty = y % m;
    if(n == 1)
        tx = 0;
    re = max(re, cnt);
    if(tx >= n) return;
    if(tx == 0 && y >= n * m)return;
    if(calc(tx, ty))
    {
        a[tx][ty] = 2;
        dfs(x+1, y+1, cnt+1);
        a[tx][ty] = 0;
        dfs(x+1, y+1, cnt);
    }
    else dfs(x+1, y+1, cnt);
}

int main()
{
    while(scanf("%d%d%d", &n, &m, &q) != EOF)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        re = 0;
        while(q--)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            a[x][y] = 1;
            b[x][y] = 1;
        }
        dfs(0,0,0);
        printf("%d\n", re);
    }
    return 0;
}
