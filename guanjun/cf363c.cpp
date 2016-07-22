/* ***********************************************
Author        :guanjun
Created Time  :2016/7/22 20:16:52
File Name     :cf363c.cpp
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
int a[110];
int dp[110][4];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		dp[i][0]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]))+1;
		if(a[i]==1||a[i]==3)dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
		else dp[i][1]=INF;
		if(a[i]==2||a[i]==3)dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
		else dp[i][2]=INF;
	}
	printf("%d\n",min(dp[n][0],min(dp[n][1],dp[n][2])));
    return 0;
}
