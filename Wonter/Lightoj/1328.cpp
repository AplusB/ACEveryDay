#include <bits/stdc++.h>
using namespace std;

long long a[100050];
long long last[100050];
int main()
{
    long long T, _case = 1;
    scanf("%lld", &T);
    while(T--)
    {
        long long k, c, n;
        scanf("%lld%lld%lld%lld", &k, &c, &n, &a[0]);
        for(long long i = 1;i < n;++i)
            a[i] = (a[i - 1] * k + c) % 1000007;
        long long ans = 0;
        sort(a, a + n);
        last[n - 1] = a[n - 1];
        for(long long i = n - 2;i >= 0;--i)
            last[i] = last[i + 1] + a[i];
        for(long long i = 0;i < n - 1;++i)
            ans = ans + last[i + 1] - (n - i - 1) * a[i];
        printf("Case %lld: %lld\n", _case++, ans);
    }
    return 0;
}
