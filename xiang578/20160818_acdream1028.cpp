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
#define cl(a) memset(a,0,sizeof(a))
typedef vector<int> VI;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
const ll mod=1000000007;
const int N=1e5+10;
int n,m,l,t;
int h[N],to[2*N],w[2*N],ne[2*N],dp[N][2],ans[2];

void dfs(int x,int fa)
{
    //printf("%d\n",x);
    for(int i=h[x]; i!=-1; i=ne[i])
    {

        int y=to[i];
        int c=w[i];
        if(fa==y) continue;
        //printf("%d %d %d\n",x,y,i);
        dfs(y,x);
        if(c==1)
        {
            if(dp[x][0]%2==0&&dp[y][0]%2==0)
                ans[1]=max(ans[1],dp[x][0]+dp[y][0]+1);
            if(dp[x][1]%2==1&&dp[y][1]%2==1)
                ans[1]=max(ans[1],dp[x][1]+dp[y][1]+1);
            if(dp[x][0]%2==0&&dp[y][1]%2==1)
                ans[0]=max(ans[0],dp[x][0]+dp[y][1]+1);
            if(dp[x][1]%2==1&&dp[y][0]%2==0)
                ans[0]=max(ans[0],dp[x][1]+dp[y][0]+1);

            if(dp[y][1]%2==1)
            {
                dp[x][0]=max(dp[x][0],dp[y][1]+1);
            }
            if(dp[y][0]%2==0)
            {
                dp[x][1]=max(dp[x][1],dp[y][0]+1);
            }
        }
        else
        {
            if(dp[x][0]%2==0&&dp[y][0]%2==0)
                ans[0]=max(ans[0],dp[x][0]+dp[y][0]+2);
            if(dp[x][1]%2==1&&dp[y][1]%2==1)
                ans[0]=max(ans[0],dp[x][1]+dp[y][1]+2);
            if(dp[x][1]%2==1&&dp[y][0]%2==0)
                ans[1]=max(ans[1],dp[x][1]+dp[y][0]+2);
            if(dp[x][0]%2==0&&dp[y][1]%2==1)
                ans[1]=max(ans[1],dp[x][0]+dp[y][1]+2);

            if(dp[y][1]%2==1)
            {
                dp[x][1]=max(dp[x][1],dp[y][1]+2);
            }
            if(dp[y][0]%2==0)
            {
                dp[x][0]=max(dp[x][0],dp[y][0]+2);
            }
        }

        /*for(int a=0; a<2; a++)
            for(int b=0; b<2; b++)
            {
                if(dp[x][a]%2!=a) continue;
                if(dp[y][b]%2!=b) continue;
                ans[(a+b+c)%2]=max(ans[(a+b+c)%2],dp[x][a]+dp[y][b]+c);
            }
        for(int j=0; j<2; j++)
        {
            if(dp[y][j]%2!=j) continue;
            dp[x][(j+c)&1]=max(dp[x][(j+c)&1],c+dp[y][j]);
        }*/
        //dp[x][1]=max(dp[x][1],dp[y][1]+);
        //dp[x][0]=max(dp[x][0],dp[y][0]+2);

    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(~scanf("%d%d",&n,&m))
    {
        int u,v,c;
        memset(h,0xff,sizeof(h));
        memset(dp,0,sizeof(dp));
        ans[0]=ans[1]=0;
        t=0;
        for(int i=0; i<n-1; i++)
        {
            scanf("%d%d%d",&u,&v,&c);
            w[t]=c;
            to[t]=v;
            ne[t]=h[u];
            h[u]=t;
            t++;
            w[t]=c;
            to[t]=u;
            ne[t]=h[v];
            h[v]=t;
            t++;
        }
        dfs(1,0);
        //printf("%d %d\n",ans[0],ans[1]);
        for(int i=0; i<m; i++)
        {
            scanf("%d",&l);
            if(l<0||l>2*n-2) puts("No");
            else
            {
                if(l<=ans[l%2]) puts("Yes");
                else puts("No");
            }
        }
    }
    return 0;
}
