/* ***********************************************
Author        :guanjun
Created Time  :2016/6/17 23:15:46
File Name     :1013.cpp
************************************************ */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <list>
#include <deque>
#include <stack>
#define ull unsigned long long
#define ll long long
#define mod 90001
#define INF 0x3f3f3f3f
#define maxn 10010
#define cle(a) memset(a,0,sizeof(a))
const ull inf = 1LL << 61;
const double eps=1e-5;
using namespace std;
priority_queue<int,vector<int>,greater<int> >pq;
struct Node{
	int x,y;
};
struct cmp{
    bool operator()(Node a,Node b){
        if(a.x==b.x) return a.y> b.y;
        return a.x>b.x;
	}
};

bool cmp(int a,int b){
    return a>b;
}
ll cnt[60][60];
int dp[60][60];
char a[100];
char b[100];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int T;
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>a>>b;
		int n=strlen(a);
		int m=strlen(b);
		cle(cnt);
		cnt[0][0]=1;

		memset(dp,INF,sizeof dp);
		dp[0][0]=0;

		for(int i=1;i<=n;i++){
			dp[i][0]=i;
			cnt[i][0]=1;
		}
		for(int j=1;j<=m;j++){
			dp[0][j]=j;
			cnt[0][j]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(dp[i][j]>dp[i-1][j]+1)
					dp[i][j]=dp[i-1][j]+1;
				if(dp[i][j]>dp[i][j-1]+1)
					dp[i][j]=dp[i][j-1]+1;
				if(a[i-1]==b[j-1]){
					if(dp[i][j]>dp[i-1][j-1]+1)
						dp[i][j]=dp[i-1][j-1]+1;
				}
				if(dp[i][j]==dp[i-1][j]+1&&a[i-1]!=b[j-1]){
					cnt[i][j]+=cnt[i-1][j];
				}
				if(dp[i][j]==dp[i][j-1]+1&&a[i-1]!=b[j-1]){
					cnt[i][j]+=cnt[i][j-1];
				}
				if(a[i-1]==b[j-1]&&dp[i][j]==dp[i-1][j-1]+1){
					cnt[i][j]+=cnt[i-1][j-1];
				}
			}
		}
		printf("Case %d: %d %lld\n",t,dp[n][m],cnt[n][m]);
	}
    return 0;
}
