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
#define mod 1000000007
#define ll long long
using namespace std;
#include <iostream>
#include <stdio.h>
using namespace std;
ll dp[12][1<<(11)];
int n,m;
void dfs(int r,int c,int last,int now)
{
    if(c==m)
    {
        dp[r][now]+=dp[r-1][last];
        return;
    }
    if(c+1<=m)
    {
        dfs(r,c+1,last<<1,now<<1|1);
        dfs(r,c+1,last<<1|1,now<<1);
    }
    if(c+2<=m) dfs(r,c+2,last<<2|3,now<<2|3);
    return;
}
int main()
{
    int i;
    while(~scanf("%d%d",&m,&n))
    {
        if(!m) break;
        if((m*n)%2)
        {
            printf("0\n");
            continue;
        }
        if(m>n) swap(n,m);
        memset(dp,0,sizeof(dp));
        dp[0][(1<<m)-1]=1;
        for(i=1;i<=n;i++) dfs(i,0,0,0);
        cout<<dp[n][(1<<m)-1]<<endl;
    }
    return 0;
}
