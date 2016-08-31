/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.com
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
const int inf=0x3f3f3f3f;
const ll mod=1000000007;
const int N=2048;
const int M=1e6+10;
int a[N],n,dp[N][3];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
    memset(dp,0x3f,sizeof(dp));
    //printf("%d %d\n",inf,dp[0][0]);
    dp[0][0]=1;
    if(a[0]==2||a[0]==3) dp[0][1]=0;
    if(a[0]==3||a[0]==1) dp[0][2]=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]==0)
        {
            dp[i][0]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]))+1;
        }
        else if(a[i]==1)
        {
            dp[i][0]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]))+1;
            dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
        }
        else if(a[i]==2)
        {
            dp[i][0]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]))+1;
            dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
        }
        else if(a[i]==3)
        {
            dp[i][0]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]))+1;
            dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
        }
    }
    cout<<min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));
    return 0;
}
