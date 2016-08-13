#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;
const int inf=2e9+9;

char num[maxn];
int dp[maxn];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        scanf("%s",num);
        memset(dp,0,sizeof(dp));
        int lt=maxn,rt=-1;
        if(num[0]=='(')
            dp[0]=1,rt=0;
        else
            dp[0]=-1,lt=0;
        for(int i=1;i<n;i++)
        {
            if(num[i]=='(')
            {
                rt=max(rt,i);
                dp[i]=dp[i-1]+1;
            }
            else
            {
                lt=min(lt,i);
                dp[i]=dp[i-1]-1;
            }
        }
        if(dp[n-1]!=0)
        {
            printf("No\n");continue;
        }
        int flag;
        if(lt<=rt)
        {
            flag=1;
            for(int i=lt;i<=rt;i++)
            {
                if(dp[i]<-2)
                {
                    flag=-1;break;
                }
            }
        }
        else
        {
            flag=-1;
            for(int i=0;i<n-1;i++)
            {
                if(dp[i]>=2 && dp[i+1]>=2)
                {
                    flag=1;break;
                }
            }
        }
        if(flag==1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
