#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;
typedef long long ll;
const int maxn=1e3+9;
const double eps=1e-9;

int nx[200000];
double dp[200000];

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m) && n+m)
    {
        memset(nx,-1,sizeof(nx));
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            nx[x]=y;
        }
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--)
        {
            int tmp=i;
            while(nx[tmp]!=-1)
                tmp=nx[tmp];
            if(tmp!=i)
            {
                dp[i]=dp[tmp];continue;
            }
            for(int j=1;j<=6;j++)
                dp[i]+=dp[i+j];
            dp[i]=dp[i]/6+1;
        }
        printf("%.4lf\n",dp[0]);
    }
    return 0;
}
