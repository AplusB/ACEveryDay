/* ***********************************************
Author        :guanjun
Created Time  :2016/6/14 19:21:17
File Name     :1011.cpp
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
int dp[1<<16];
int n,m;
int a[30][30];
int dfs(int s,int cnt){
	if(s==(1<<n)-1){
		return dp[s]=0;
	}
	if(dp[s]!=-1)return dp[s];
	for(int i=0;i<n;i++){
		if(!(s&(1<<i))){
			dp[s]=max(dp[s],dfs(s|(1<<i),cnt+1)+a[cnt][i]);
		}
	}
	return dp[s];
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int T;
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>n;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		memset(dp,-1,sizeof dp);
		printf("Case %d: %d\n",t,dfs(0,0));

	}
    return 0;
}
