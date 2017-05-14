#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int N=100000+5;
const int mod=1e9+7;
int n,a[N],dp[N],cnt[N],f[N];

int main()
{
    f[0]=1;
    for(int i=1;i<=100000;i++)
        f[i]=(f[i-1]*2)%mod;
    cin>>n;
    memset(cnt,0,sizeof cnt);
    memset(dp,0,sizeof dp);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        for(int j=2;j*j<=a[i];j++)
        {
            if(a[i]%j==0)
            {
                cnt[j]++;
                if(j*j!=a[i]) cnt[a[i]/j]++;
            }
        }
        cnt[a[i]]++;
    }
    for(int i=100000;i>1;i--)
    {
        dp[i]=(f[cnt[i]]-1+mod)%mod;
        for(int j=2*i;j<=100000;j+=i)
        {
            dp[i]=(dp[i]-dp[j]+mod)%mod;
        }
    }
    int ans=0;
    ans=(f[n]-1+mod)%mod;
    for(int i=100000;i>1;i--)
        ans=(ans-dp[i]+mod)%mod;
    cout<<ans<<endl;
    return 0;
}
