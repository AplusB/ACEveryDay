//poj 3186
//从里到外递推
#include<iostream>
#include<cstdio>
#include<math.h>
#include<queue>
#include<map>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
#define INF 0x3f3f3f3f
#define PI acos(-1.0)

const int N=1e3+10;

int a[N*2];
int dp[N*2][N*2];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    memset(dp,0,sizeof(dp));

    for(int i=n;i>=1;i--){
        for(int j=i;j<=n;j++)
            dp[i][j]=max(dp[i+1][j]+(n-(j-i))*a[i],dp[i][j-1]+(n-(j-i))*a[j]);
    }
    cout<<dp[1][n]<<endl;
}
//记忆化搜索

#include<iostream>
#include<cstdio>
#include<math.h>
#include<queue>
#include<map>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
#define INF 0x3f3f3f3f
#define PI acos(-1.0)

const int N=1e3+10;

int a[N*2];
int dp[N*2][N*2];
int n;

int DFS(int s,int e)
{
    if(dp[s][e])
        return dp[s][e];
    if(s==e)
        return dp[s][e]=n*a[s];
    int ans=0;
    ans=max(DFS(s+1,e)+(n-e+s)*a[s],DFS(s,e-1)+(n-e+s)*a[e]);
    return dp[s][e]=ans;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        scnf("%d",&a[i]);
    memset(dp,0,sizeof(dp));
    cout<<DFS(1,n)<<endl;
    return 0;
}
