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
const int maxn=2e4+9;

int dp[maxn][2];
int num[maxn];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++) scanf("%d",&num[i]);
        memset(dp,0,sizeof(dp));
        dp[1][1]=num[1];
        for(int i=2;i<=n;i++)
        {
            dp[i][1]=dp[i-1][0]+num[i];
            dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
        }
        printf("%d\n",max(dp[n][1],dp[n][0]));
    }
    return 0;
}
