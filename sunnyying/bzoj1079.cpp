#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace std;
#define N 100100
#define INF 0x7fffffff
#define endl '\n'
#define ll long long
#define mod 1000000007
ll dp[6][16][16][16][16][16];
ll dfs(int a,int b,int c,int d,int e,int x)
{
    if(a+b+c+d+e==0) return dp[x][a][b][c][d][e]=1;
    if(dp[x][a][b][c][d][e]) return dp[x][a][b][c][d][e];
    ll ans=0;
    if(a) (ans+=(a-(x==2))*dfs(a-1,b,c,d,e,1))%=mod;
    if(b) (ans+=(b-(x==3))*dfs(a+1,b-1,c,d,e,2))%=mod;
    if(c) (ans+=(c-(x==4))*dfs(a,b+1,c-1,d,e,3))%=mod;
    if(d) (ans+=(d-(x==5))*dfs(a,b,c+1,d-1,e,4))%=mod;
    if(e) (ans+=e*dfs(a,b,c,d+1,e-1,5))%=mod;
    return dp[x][a][b][c][d][e]=ans;
}
int main()
{
  //  freopen("in.in","r",stdin);
    int z[5];
    int n,k,x;
    scanf("%d",&k);
    memset(z,0,sizeof(z));
    for(int i=0;i<k;i++) scanf("%d",&x),z[x-1]++,n+=x;
    ll ans=dfs(z[0],z[1],z[2],z[3],z[4],0);
    cout<<ans<<endl;
    return 0;
}
