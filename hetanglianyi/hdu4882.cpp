#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include<algorithm>
using namespace std;

struct ty
{
    int e, k;
    double b;
} a[100100];
int n;

int comp(ty x, ty y)
{
    return x.b < y.b;
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i].e);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i].k);
            a[i].b = a[i].e * 1.0 / a[i].k;
        }
        sort(a, a + n, comp);
        long long re = 0, tmp = 0;
        for (int i = 0; i < n; i++)
        {
            tmp += a[i].e;
            re += tmp * a[i].k;
        }

        printf("%I64d\n", re);
    }
    return 0;
}
