#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <stack>
using namespace std;
typedef long long ll;
const int maxn=1e5+9;
const int inf=1e9+9;
double dp[maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        memset(dp,0,sizeof(dp));
        dp[1]=1;
        for(int i=2;i<=m;i++)
        {
            dp[i]=(1-dp[i-1])*dp[i-1]+dp[i-1]*(dp[i-1]-1.0/n);
        }
        double ans=0;
        for(int i=1;i<=m;i++)
            ans+=dp[i];
        printf("%.9lf\n",ans);
    }
    return 0;
}
