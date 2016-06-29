#include <cstdio>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <math.h>
#include <stdlib.h>
#define N 100010
#define INF 0x3f3f3f3f
#define endl '\n'
#define ll long long
typedef long long LL;
#define mod 1000000007
using namespace std;
int n,ans;
char a[1000];
int vis[1100][1100][2][2],dp[1100][1100][2][2];
int dfs(int x,int y,int z,int mark)
{

    if(vis[x][y][z][mark]) return dp[x][y][z][mark];
    vis[x][y][z][mark]=1;
    int l=(y-x+1);
    dp[x][y][z][mark]=y-x+1;
    if(l==1) return 1;
    if(z==0)
    {
        if(l%2==0)
        {
            int i;
            for(i=0;i<l/2;i++) if(a[x+i]!=a[l/2+i+x]) break;
            if(i==l/2) dp[x][y][0][mark]=min(dp[x][y][0][mark],dfs(x,x+l/2-1,0,1)+1);
        }
        if(mark) for(int i=x;i<y;i++) dp[x][y][0][mark]=min(dp[x][y][0][mark],dfs(x,i,0,mark)+y-i);
        else for(int i=x;i<y;i++) dp[x][y][0][mark]=min(dp[x][y][0][mark],dfs(x,i,0,mark)+dfs(i+1,y,1,mark));
        return dp[x][y][z][mark];
    }
    for(int i=x;i<y;i++)
    {
        int res1=dfs(x,i,1,mark);
        dp[x][y][z][mark]=min(dp[x][y][z][mark],res1+y-i);
        if(!mark)dp[x][y][z][mark]=min(dp[x][y][z][mark],res1+1+dfs(i+1,y,0,mark));
    }
    return dp[x][y][z][mark];
}
int main()
{
   // freopen("in.in","r",stdin);
   // freopen("out.out","w",stdout);
    while(~scanf("%s",a))
    {
        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));
        n=strlen(a);
    cout<<min(dfs(0,n-1,0,0),dfs(0,n-1,1,0))<<endl;
    }

    return 0;
}
