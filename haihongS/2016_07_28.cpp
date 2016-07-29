#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;
const int inf=1000000;

int num[maxn];
int dp[maxn];

int bi(int len,int x);

int main()
{
    int t;
    scanf("%d",&t);
    int cas=1;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&num[i]);
        memset(dp,-1,sizeof(dp));

        if(num[0]==0)
            dp[1]=0;
        else
            dp[1]=num[0];

        int len=2;
        for(int i=1;i<n;i++)
        {
            if(num[i]!=0)
            {
                int loca=bi(len,num[i]);
                dp[loca]=num[i];
                if(loca==len)
                    len++;
            }
            else
            {
                for(int j=len-1;j>=0;j--)
                {
                    dp[j+1]=dp[j]+1;
                }
                dp[0]=0;
                len++;
            }
        }
        int ans=1;
        for(int i=n;i>=1;i--)
        {
            if(dp[i]!=-1)
            {
                ans=i;break;
            }
        }
        printf("Case #%d: ",cas++);
        printf("%d\n",ans);
    }
    return 0;
}
int bi(int len,int x)
{
    int lt,rt,mid,ans=len;
    lt=1,rt=len;
    while(lt<=rt)
    {
        mid=lt+(rt-lt)/2;
        if(mid==len) break;
        if(dp[mid]>=x)
        {
            ans=min(ans,mid);
            rt=mid-1;
        }
        else
            lt=mid+1;
    }
    return ans;
}
