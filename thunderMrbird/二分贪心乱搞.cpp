#include<iostream>
#include <cstdio>
#include<queue>
#include<string>
#include<algorithm>
#include<map>
#include <cstring>
#include<queue>
#include<vector>
#include<cmath>
#include<set>
using namespace std;
typedef long long ll;
ll a[100005],b[100005];
ll sum[100005];
int main()
{
    int n,m,k,T;
    ll x;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
                scanf("%lld %lld",a+i,b+i);
        sum[n]=a[n-1]*b[n-1];
        for(int i=n-1;i>=0;i--)
        {
                sum[i]=min(sum[i+1],a[i]*b[i]);
        }
        for(int z=0;z<m;z++)
        {
                int ans;
                scanf("%lld",&x);
                int l=0,r=n-1;
                        while (l <= r)
                        {
                                int mid = (l + r) / 2;
                                if (a[mid] <= x)
                                {
                                        ans=mid;
                                        l = mid + 1;
                                }
                                else
                                        r = mid - 1;
                        }
                        if(ans!=n-1)
                        printf("%lld\n",min(b[ans]*x,sum[ans+1]));
                        else
                        printf("%lld\n",x*b[ans]);
        }
    }
    return 0;
}
