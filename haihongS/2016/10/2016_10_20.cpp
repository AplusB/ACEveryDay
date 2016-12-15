#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;

int a[maxn];
int dp[maxn],go[maxn];

int bi(int lt,int rt,int v);

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        if(n==1)
        {
            printf("-1\n");continue;
        }
        dp[n]=a[n];
        for(int i=n-1;i>=1;i--)
        {
            dp[i]=min(dp[i+1],a[i]);
        }
        for(int i=1;i<=n;i++)
        {
            int pos=bi(i+1,n,a[i]);
            if(a[pos]>=a[i])
                go[i]=-1;
            else
                go[i]=pos-i-1;
        }
        for(int i=1;i<n;i++)
        {
            if(i!=1) printf(" ");
            printf("%d",go[i]);
        }
        printf(" -1\n");
    }
    return 0;
}

int bi(int lt,int rt,int v)
{
    int ans=lt;
    while(lt<=rt)
    {
        int mid=lt+(rt-lt)/2;
        if(dp[mid]<v)
        {
            ans=max(ans,mid);
            lt=mid+1;
        }
        else
            rt=mid-1;
    }
    return ans;
}
