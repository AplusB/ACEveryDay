#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    long long T;
    long long _case = 1;
    scanf("%lld", &T);
    while(T--)
    {
        long long w;
        scanf("%lld", &w);
        if(w & 1)
        {
            printf("Case %lld: Impossible\n", _case++);
            continue;
        }
        long long n, m;
        m = 1;
        while(!(w & 1))
        {
            m *= 2;
            w >>= 1;
        }
        n = w;
        printf("Case %lld: %lld %lld\n", _case++, n, m);
    }
    return 0;
}
