#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
int f[20][1000][1000];
int n, m;
char a[1000], b[1000];
const int mod = 1024523;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf(" %c", &a[i]);
    for (int i = 1; i <= m; i++)
        scanf(" %c", &b[i]);

    memset(f, 0, sizeof(f));
    f[0][0][0] = 1;
    for (int i = 1; i <= n+m; i++)
    {
        int t = min(i, n);
        for (int j = 0; j <= t; j++)
        for (int k = 0; k <= t; k++)
        {
            if (j > 0 && k > 0 && a[j] == a[k]) f[i%2][j][k] += f[(i-1)%2][j-1][k-1];
            if (b[i-j] == b[i-k]) f[i%2][j][k] += f[(i-1)%2][j][k];
            if (j > 0  && a[j] == b[i-k]) f[i%2][j][k] += f[(i-1)%2][j-1][k];
            if (k > 0 && b[i-j] == a[k]) f[i%2][j][k] += f[(i-1)%2][j][k-1];
            f[i%2][j][k]  %= mod;
    //         cout << i<<' '<<j <<' ' << k <<": "<<f[i%2][j][k] <<endl;
        }
        for (int j = 0; j <= n; j++)
        for (int k = 0; k <= n; k++)
            f[(i-1) % 2][j][k] = 0;
    }


    printf("%d\n", f[(n+m) %2][n][n]);
    return 0;
}
