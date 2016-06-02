#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int n, m;
double f[1010][12];
const double pi = acos(-1.0);
inline int fabs(int a)
{
    return a > 0 ? a : -a;
}
int main()
{
    while (scanf("%d%d", &n, &m) != EOF && n != 0 &&m != 0)
    {
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                f[i][j] = 100000.0 * 100000.0;
            }
        }
        for (int i= 0; i < m; i++)
            f[0][i] = 0;
        for (int i = 1; i <= n; i++)
        {
            char c;
            int len;
            scanf(" %c %d", &c, &len);
            if (c == 'S')
            {
                for (int j = 0; j < m; j++)
                {
                    int tt = len/100;
                    f[i][j] = f[i - 1][j] + len;
                    for (int k = 0; k < m; k++)
                    {
                        if (fabs(k - j) > tt) continue;
                        if (j != k)
                            f[i][j] = min(f[i][j], f[i-1][k] + sqrt(1.0 * len*len + (10*(k-j)) * (10*(k-j))));
                    }
                }
            }
            if (c == 'L')
            {
                for (int j = 0; j < m; j++)
                {
                    f[i][j] = f[i - 1][j] + 0.5 * pi * (5 + len + 10*fabs(j*1.0));
                }
            }
            if (c == 'R')
            {
                for (int j = 0; j < m; j++)
                {
                    f[i][j] = f[i - 1][j] + 0.5 * pi * (5 + len + 10*fabs((m-j-1)*1.0));
                }
            }
        }
        double re  = f[n][0];
        for (int i = 0; i < m; i++)
        {
            if (re > f[n][i]) re = f[n][i];
        }

        printf("%.2f\n", re);
    }
}
