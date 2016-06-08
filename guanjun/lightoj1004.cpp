/* ***********************************************
Author        :guanjun
Created Time  :2016/6/8 10:57:05
File Name     :1004.cpp
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
int a[210][210];
int dp[210][210];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
	int T,n;
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>n;
		cle(a);cle(dp);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++)
				cin>>a[i][j];
		}
		for(int i=n+1;i<=2*n-1;i++){
			for(int j=1;j<=2*n-i;j++)
				cin>>a[i][j];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+a[i][j];
			}
		}
		for(int i=n+1;i<=2*n-1;i++){
			for(int j=1;j<=2*n-i;j++){
				dp[i][j]=max(dp[i-1][j+1],dp[i-1][j])+a[i][j];
			}
		}
		printf("Case %d: %d\n",t,dp[2*n-1][1]);
	}
    return 0;
}
