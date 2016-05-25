#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;

pair<int,int> a[111111];
int b[111111];
int dp[111111];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].first,&a[i].second);
    }
    
    sort(a,a+n);
    for (int i=0;i<n;i++)
    {
        b[i]=a[i].first;
    }
    int ans=1;
    dp[0] = 1;
    
    for (int i=1;i<n;i++)
    {
        int tmp=lower_bound(b,b+i+1,a[i].first - a[i].second)-b;
        
        if (tmp==0)
        {
            dp[i]=1;
        }
        dp[i]=dp[tmp-1]+1;
        ans=max(ans,dp[i]);
    }
    cout<<n-ans<<endl;
    
    return 0;
}