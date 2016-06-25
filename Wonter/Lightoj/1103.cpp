#include <bits/stdc++.h>
using namespace std;

long long bit[300050];
long long arr[200050];
long long n, m;
void add(long long x, long long i)
{
    while(x <= n + m)
    {
        bit[x] += i;
        x += x & -x;
    }
}
long long sum(long long x)
{
    long long ret = 0;
    while(x)
    {
        ret += bit[x];
        x -= x & -x;
    }
    return ret;
}
int main()
{
    long long _case = 1;
    long long T;
    scanf("%lld", &T);
    while(T--)
    {
        memset(bit, 0, sizeof(bit));
        scanf("%lld%lld", &n, &m);
        for(long long i = 1; i <= n; i++)
        {
            long long x, y;
            scanf("%lld%lld", &x, &y);
            arr[x] = y;
        }
        long long ans = 0;
        for(long long i = 1;i <= m;i++)
        {
            long long x, y;
            scanf("%lld%lld", &x, &y);
            arr[x] = y;
        }
        for(long long i = 1;i <= n + m;i++)
        {
            ans += i - 1 - sum(arr[i] - 1);
            add(arr[i], 1);
        }
        printf("Case %lld: %lld\n", _case++, ans);
    }
    return 0;
}
