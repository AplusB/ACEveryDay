#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#define INF 32768
#define mod 1000000007
#define ll long long
using namespace std;
ll gcd(ll x,ll y)
{
    if(y==0) return x;
    return gcd(y,x%y);
}
int main()
{
    ll n,ans=0;
    scanf("%lld",&n);
    for(ll i=1;i*i<=2*n;i++)
    {
        if(2*n%i) continue;
        for(ll x=1;x*x<=2*n/i;x++)
        {
            ll y=sqrt(2*n/i-x*x);
            if(y*y!=2*n/i-x*x) continue;
            if(x>=y) continue;
            if(gcd(x,y)>1) continue;
            ans++;
        }
        if(i==2*n/i) continue;
        for(ll x=1;x*x<=i;x++)
        {
            ll y=sqrt(i-x*x);
            if(y*y!=i-x*x) continue;
            if(x>=y) continue;
            if(gcd(x,y)>1) continue;
            ans++;
        }
    }
    ans=(ans+1)*4;
    cout<<ans<<endl;
    return 0;
}
