#include<iostream>
#include<cstring>
#include<cstdio>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int n, m, d;
double f[10010][60];
bool a[60][60];
int deg[60];
double ans[60];
bool comp(int a, int b)
{
    return a > b;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &n, &m, &d);
        memset(a, 0, sizeof(a));
        memset(f, 0, sizeof(f));
        memset(deg, 0, sizeof(deg));
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            a[x][y] = 1;
            a[y][x] = 1;
            deg[x]++;
            deg[y]++;
        }

        for (int i = 1; i <= n; i++)
        {
            ans[i]=1;
            f[0][i] = 1.0 / n;
        }
        for (int k = 1; k <= n; k++)
        {
            for (int step = 1; step <= d; step++)
            {
                for (int i = 1; i <= n; i++)
                {
                    f[step][i] = 0;
                    for (int j = 1; j <= n; j++)
                    {
                        if ((j != k) && (a[j][i] == 1))
                        {
                            f[step][i] +=  (f[step - 1][j] *  (1.0 / (deg[j])));
                            //printf("%d %d %.6lf\n ", i, j, f[step - 1][j] *  (1.0 / deg[j]));
                            //if (f[step][i] > 1.0) f[step][i] = 1.0;
                        }
                    }
                }
            }

            double sum = 1;
            for(int step = 0; step <= d; step++)
            {
                ans[k] -= f[step][k];
                //printf("%.10lf ", f[step][k]);
                //ans[k]-=(sum*f[step][k]);
                //sum*=(1-f[step][k]);
            }
           // printf("\n");
            //for (int  t = 0; t <= 10; t++)
           // printf("%.6lf\n", f[t][k], f[1][k], f[2][k], f[3][k]);
           printf("%.10lf\n",fabs(ans[k]));

           for (int i = 1; i <= n; i++)
            {

                f[0][i] = 1.0 / n;

            }
        }

    }
    return 0;
}
