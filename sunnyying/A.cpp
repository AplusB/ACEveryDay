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
#define mod 1073741824
#define ll long long
using namespace std;
int prime[1000001],a,b,k,sum[1000001],vis[1000001];
void init()
{
    memset(prime,0,sizeof(prime));
    memset(vis,-1,sizeof(vis));
    for(int i=2;i*i<=1000000;i++)
    {
        if(prime[i]) continue;
        for(int j=i*i;j<=1000000;j+=i) prime[j]=1;
    }
    sum[1]=0;
    for(int i=2;i<=1000000;i++)
    {
        if(prime[i]) sum[i]=sum[i-1];
        else sum[i]=sum[i-1]+1;
    }
}
int judge(int l)
{
   // cout<<l<<" "<<a<<" "<<b<<endl;
    for(int i=a;i<=b-l+1;i++)
    {
      //  cout<<sum[i+l-1]<<" "<<sum[i-1]<<" "<<i+l-1<<" "<<i-1<<endl;
        if(sum[i+l-1]-sum[i-1]>=k) continue;
        else return 0;
    }
    return 1;
}
int main()
{
    init();
    scanf("%d%d%d",&a,&b,&k);
    if(!judge(b-a+1))
    {
        cout<<-1<<endl;
        return 0;
    }
    int l=1,r=b-a+1,ans=b-a+1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(judge(mid)) r=mid-1,ans=mid;
        else l=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}
