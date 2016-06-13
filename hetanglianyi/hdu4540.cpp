#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 1 << 30;
using namespace std;
int a[25][25];
int f[25][25];
int n, m;
int main()
{
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            scanf("%d", &a[i][j]);
            f[i][j] = N;
        }

        for(int i = 1; i <= m; i++) f[1][i] = 0;

        for(int i = 2; i <= n; i++)
        for(int j = 1; j <= m; j++)
        for(int k = 1; k <= m; k++)
            f[i][j] = min(f[i][j], f[i-1][k] + abs(a[i][j] - a[i-1][k]));


        int re = N;
        for(int i = 1; i <= m; i++)
        {
            re = min(re, f[n][i]);
        }
        printf("%d\n", re);
    }
    return 0;
}
