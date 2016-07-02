#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int N = 50050;
const double INF = 0x7f7f7f7f;
int n, k;
double a[N], sum1[N], sum2[N];
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; i++)
            scanf("%lf", &a[i]);
        sort(a+1, a+n+1);
        sum1[0] = sum1[1] = sum2[0] = sum2[1] = 0;
        for(int i = 1; i <= n; i++)
        {
            sum1[i] = sum1[i-1] + a[i];
            sum2[i] = sum2[i-1] + a[i] * a[i];
        }
        int m = n - k;
        if(m  <= 1)
        {
            printf ("0\n");
            continue;
        }
        else{
            double re = sum2[m] + m * (sum1[m] / m) * (sum1[m] / m) - 2.0 * (sum1[m] / m) * sum1[m];
            for(int j = m; j <= n; j++)
            {
                int s = j - m + 1;
                double eve = (sum1[j] - sum1[s-1]) / m;
                double tmp = sum2[j] - sum2[s-1] + m * eve * eve - 2.0 * eve * (sum1[j] - sum1[s-1]);
                re = min(re, tmp);
            }
            printf("%.10lf\n", re);
        }

    }
    return 0;
}
