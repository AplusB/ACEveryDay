#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int t, n, m;
long long f[3100];
int a[3100];
int b[3100];
int w[3100];
bool boo[3100];
int main()
{
    while(scanf("%d", &t) != EOF)
    {
        while(t--)
        {
            scanf("%d%d", &m, &n);
            for (int i = 1; i <= n; i++)
                scanf("%d%d%d", &w[i], &a[i], &b[i]);
            for (int i = 1; i <= m; i++)
                f[i] = -2147483647;
            f[0] = 0;
            for (int i = 1; i <= n; i++)
            {
                for (int j = m; j >= w[i]; j--)
                    f[j] = max(f[j], f[j- w[i]] + a[i]+ b[i]);
                for (int j = w[i]; j <= m; j++)
                    f[j] = max(f[j], f[j- w[i]] + a[i]);

            }
            long long re = 0;
            for (int i = 1; i <= m; i++)
            {
               // if (f[i] >= 0)printf("%d %d \n", i, f[i]);
                re = max(re, f[i]);
            }
            printf("%I64d\n", re);

        }
    }
    return 0;
}
