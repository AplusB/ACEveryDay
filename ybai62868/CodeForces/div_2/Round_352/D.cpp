# include <cstdio>
# include <iostream>
using namespace std;
# define inf 1000000007
# define MAX 512345
typedef long long LL;
LL a[MAX];
LL n,k;
int candrop( int x )
{
    LL res = 0;
    for ( int i = 0;i < n;i++ )
    {
        if ( a[i] > x ) res += a[i]-x;
    }
    return res <= k;
}
int canraise( int x )
{
    LL res = 0;
    for ( int i = 0;i < n;i++ )
    {
        if ( a[i] < x ) res+=x-a[i];
    }
    return res <= k;
}
int main(void)
{
    scanf("%lld %lld",&n,&k);
    LL sum = 0;
    for ( int i = 0;i < n;i++ )
    {
        scanf("%lld",&a[i]);
        sum += a[i];
    }
    LL lo = 0;
    LL hi = inf;
    LL ans1 = 0, ans2 = 0;
    while( lo <= hi )
    {
        LL mid = (lo+hi)>>1;
        if ( candrop(mid) )
        {
            hi = mid-1;
            ans1 = mid;
        }
        else
        {
            lo = mid+1;
        }
    }
    lo = 0; hi = inf;
    while ( lo <= hi )
    {
        LL mid = (lo+hi)>>1;
        if ( canraise(mid) )
        {
            lo = mid+1;
            ans2 = mid;
        }
        else
        {
            hi = mid-1;
        }
    }
    //cout<<"ans1 = "<<ans2<<" "<<"ans2 = "<<ans2<<endl;
    if ( sum%n==0 )
    {
        printf("%lld\n",max((LL)0,ans1-ans2));
    }
    else
    {
        printf("%lld\n",max((LL)1,ans1-ans2));
    }
    return 0;
}
