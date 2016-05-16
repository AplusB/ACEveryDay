#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long LL;
const LL MOD = 100003;
LL n, m;
LL pow(LL n, LL p)
{
    LL y = 1;
    while(p)
    {
        if(p & 1) y = y * n % MOD;
        n = n * n % MOD;
        p >>= 1;
    }
    return y;
}

int main()
{
    cin >> m >> n;
    LL re = pow(m, n);
    re = (re - m * pow(m-1, n-1) % MOD + MOD) % MOD;
    cout << re << endl;;
    return 0;
}
