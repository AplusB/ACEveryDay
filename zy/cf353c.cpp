#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
typedef long long ll;

map<ll,int> a;

int main()
{
    int n,ans=0;
    ll sum=0;
    ll now;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%I64d",&now);
        sum+=(ll)now;
        a[sum]++;
        ans=max(ans,a[sum]);
    }
    cout<<n-ans<<endl;
    return 0;
}
