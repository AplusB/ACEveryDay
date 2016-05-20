#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 5000005;
bool isprime[N];
LL PrimeList[1000005];
LL phi[N];

void init()
{
    memset(isprime,true,sizeof(isprime));
    LL primecount = 0;
    for(int i = 2; i <= N; i++)
    {
        if(isprime[i])
        {
            primecount += 1;
            PrimeList[primecount] = i;
            phi[i] = i - 1;
        }

        for(int j = 1; j <= primecount; j++)
        {
            if(i * PrimeList[j] > N) break;

            isprime[i * PrimeList[j]] = false;
            if(i % PrimeList[j] == 0)
            {
                phi[i* PrimeList[j] ] = phi[i] * PrimeList[j];
                break;
            }
            else
                phi[i * PrimeList[j] ] = phi[i] *  (PrimeList[j] - 1);
        }
    }
}

void solve()
{
    LL l,r;
    LL ans = -1,minsum = N+1;
    scanf("%lld %lld",&l,&r);
    for(int i = l; i <= r; i++)
    {
        if(minsum > phi[i])
        {
            ans = i;
            minsum = phi[i];
        }
    }
    printf("%lld\n",ans);
}

int main()
{
    init();
    solve();
    return 0;
}
