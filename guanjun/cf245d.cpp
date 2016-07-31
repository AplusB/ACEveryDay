  /* ***********************************************
Author        :guanjun
Created Time  :2016/7/31 12:51:10
File Name     :cd.cpp
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
int dp[4][1100][1100];
int a[1100][1100];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int n,m;
	while(cin>>n>>m){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j];
		cle(dp);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				dp[0][i][j]=max(dp[0][i-1][j],dp[0][i][j-1])+a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=m;j>=1;j--){
				dp[1][i][j]=max(dp[1][i-1][j],dp[1][i][j+1])+a[i][j];
			}
		}
		for(int i=n;i>=1;i--){
			for(int j=m;j>=1;j--){
				dp[2][i][j]=max(dp[2][i+1][j],dp[2][i][j+1])+a[i][j];
			}
		}
		for(int i=n;i>=1;i--){
			for(int j=1;j<=m;j++){
				dp[3][i][j]=max(dp[3][i+1][j],dp[3][i][j-1])+a[i][j];
			}
		}
		int ans=0;
		for(int i=2;i<n;i++){
			for(int j=2;j<m;j++){
				ans=max(max(dp[0][i][j-1]+dp[3][i+1][j]+dp[1][i-1][j]+dp[2][i][j+1],
					   dp[0][i-1][j]+dp[2][i+1][j]+dp[3][i][j-1]+dp[1][i][j+1]),ans);
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}
