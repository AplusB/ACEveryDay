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
#define N 200000+10
#define INF 0x3f3f3f3f
#define endl '\n'
#define mod  1000000007
#define ll unsigned long long
#define eps 1e-10
using namespace std;
int n,m,k=11,mi=20;
ll MOD;
ll dp[N][11][3];
vector<int>v[N];
ll f(ll x)
{
    if(x!=0&&x%MOD==0) return MOD;
    return x%MOD;
}
void dfs(int x,int fa)
{
    for(int i=0;i<11;i++) dp[x][i][0]=1;
    for(int i=0;i<v[x].size();i++)
    {
        int xx=v[x][i];
        if(xx==fa) continue;
        dfs(xx,x);
        ll x1=0,x2=0;
        for(int j=0;j<k;j++)
        {
            x2=dp[xx][j][0]+dp[xx][j][1];
            if(j) x1=dp[xx][j-1][0]+dp[xx][j-1][1]+dp[xx][j-1][2];
            dp[x][j][2]=f(dp[x][j][2]*x1+dp[x][j][1]*x2);
            dp[x][j][1]=f(dp[x][j][1]*x1+dp[x][j][0]*x2);
            dp[x][j][0]=f(dp[x][j][0]*x1);
           // cout<<dp[x][j][0]<<" "<<dp[x][j][1]<<" "<<dp[x][j][2]<<" "<<x<<" "<<j<<" "<<x1<<" "<<x2<<endl;
        }
    }
}
int main()
{
    int x,y;
    scanf("%d%d%lld",&n,&m,&MOD);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    if(m<n-1){cout<<-1<<endl<<-1<<endl;return 0;}
    dfs(1,0);
    for(int i=0;i<11;i++)
        if(dp[1][i][0]+dp[1][i][1]+dp[1][i][2])
        {
            cout<<i<<endl<<(dp[1][i][0]+dp[1][i][1]+dp[1][i][2])%MOD<<endl;
            break;
        }
    return 0;
}

