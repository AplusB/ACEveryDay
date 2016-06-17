#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
using namespace std;
long long c[450010];
int a[450010];
long long mod =  1000000007LL;
void calc2(int n)
{
    c[1] = n;
    long long k = n - 2;
    for (int i = 2; i <= (n + 1) / 2; i++)
    {
        c[i] = (c[i-1] + k) % mod;
        k -= 2;
    }
    for (int i = n / 2 + 1; i <= n; i++)
    {
        c[i] = ((c[i-1] - k) % mod + mod) % mod;
        k += 2;
    }
}
int main()
{
    int t,n;
    long long re;
    scanf("%d", &t);
    while (t--)
    {
        re = 0;
        scanf("%d", &n);
        calc2(n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            re = re + (a[i] * (c[i] % mod)) % mod;
        }
        cout << re % mod  << endl;
    }
    return 0;
}
