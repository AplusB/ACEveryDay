#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cmath>
#define N 2000010
using namespace std;
long long f[40][40];
int n, m;
int main()
{
    memset(f, 0, sizeof(f));
    for(int i = 0; i <= 20; i++)
        f[i][0] = 1;
    for(int i = 1; i <= 20; i++)
        for(int j = i; j <= 20; j++)
            f[j][i] = f[j-1][i] + f[j][i-1];
    while(scanf("%d%d", &m, &n) != EOF)
    {
        printf("%I64d\n", f[m][n]);
    }
    return 0;
}
