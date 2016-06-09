/* ***********************************************
Author        :guanjun
Created Time  :2016/6/9 16:02:10
File Name     :1005.cpp
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
ll dp[33][33];
int n,k;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int T;
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>n>>k;
		printf("Case %d: ",t);
		if(k>n){
			puts("0");continue;
		}
		cle(dp);
		dp[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=i;j++){
				if(j)dp[i][j]=dp[i-1][j]+dp[i-1][j-1]*(n-j+1);
				else dp[i][j]=dp[i-1][j];
			}
		}
		printf("%lld\n",dp[n][k]);
	}
    return 0;
}
