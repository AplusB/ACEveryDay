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
const ll mod=1000000007;
const int N=2048;
int dp[2][5000+10];
char s[5000+10];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
   	int n,now;
	while(~scanf("%d",&n))
	{
		scanf("%s",s);
		memset(dp,0,sizeof(dp));
		now=0;
		for(int j=0;j<n;j++)
		{
			now=!now;
			dp[now][j]=1;
			for(int i=j-1;i>=0;i--)
			{
				if(s[i]==s[j])
					dp[now][i]=2+dp[now^1][i+1];
				else
					dp[now][i]=max(dp[now^1][i],dp[now][i+1]);
			}
		}
		//for(int i=0;i<n;i++)printf("%d\n",dp[now][i]);
		printf("%d\n",n-dp[now][0]);
	}
    return 0;
}
