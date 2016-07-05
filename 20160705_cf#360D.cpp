#include<bits/stdc++.h>
using namespace std;
long long k,t,a,b;
int n;

int main()
{
    scanf("%d%lld",&n,&k);
    t=1;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a);
        if(t==k) continue;
        t=t*a/__gcd(a,t);
        t=__gcd(t,k);
    }
    if(t==k) puts("Yes");
    else puts("No");
    return 0;
}
