#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=2048;
int dp[N][N],n,m;
char a[N],b[N];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(~scanf("%s%s",a,b))
    {
        n=strlen(a);
        m=strlen(b);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
                dp[i][j]=max(dp[i][j],dp[i][j-1]);
            }
        }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}


