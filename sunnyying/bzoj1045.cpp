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
ll a[2000000],sum[2000000];
int main()
{
    ll n,x,ans=0;
    scanf("%lld",&n);
    sum[0]=0;x=0;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]),x+=a[i],sum[i]=sum[i-1]+a[i];
    x=x/n;
    for(int i=1;i<=n;i++) sum[i]=sum[i]-i*x;
    sort(sum+1,sum+1+n);
    for(int i=1;i<=n;i++) ans=ans+abs(sum[i]-sum[n/2]);
    cout<<ans<<endl;
    return 0;
}
