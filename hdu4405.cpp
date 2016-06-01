#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
double e[100100];
int f[100100];
int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF && (n != 0 || m != 0))
    {
        for(int i = 0; i <= n; i++)
            e[i] = 0;
        memset(f, -1, sizeof(f));
        for(int i = 0; i < m; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            f[a] = b;
        }
        for(int i = n - 1; i >= 0; i--)
        {
            if(f[i] != -1) e[i] = e[f[i]];
            else
            {
                for(int j = 1; j <= 6; j++)
                {
                    if(i + j <= n) e[i] += (1.0 / 6) * e[i + j];
                }
                e[i] += 1.0;
            }
        }
        printf("%.4lf\n", e[0]);

    }
    return 0;
}
