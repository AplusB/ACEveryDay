#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const double e =  2.718281828459;
const double PI = acos(-1.0);

void solve()
{
    int n,k;
    scanf("%d %d",&n,&k);
    if(n == 0)
    {
        printf("1\n");
    }
    else
    {
        double ans;
        ans = log10(sqrt(2.0*PI*n))+1.0*n*log10(1.0*n/e);
        ans /= log10(k);
        printf("%lld\n",(LL)ans+1);
    }

}

int main(void)
{
    int t,cnt = 0;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d: ",++cnt);
        solve();
    }
    return 0;
}
