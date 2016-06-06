#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 1100;
int n, m;
double f[N][N], p[N][N][3];

int main()
{
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%lf%lf%lf", &p[i][j][0], &p[i][j][1], &p[i][j][2]);
        memset(f, 0, sizeof(f));
        for(int i = n; i >= 1; i--)
        for(int j = m; j >= 1; j--)
        {
            if((i != n || j != m) && (p[i][j][0] != 1.00))
                f[i][j] = (p[i][j][1]*f[i][j+1] + p[i][j][2]*f[i+1][j] + 2) / (1 - p[i][j][0]);
        }
        printf("%.3lf\n", f[1][1]);
    }
    return 0;
}
