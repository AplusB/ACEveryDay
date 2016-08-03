/* ***********************************************
Author        :guanjun
Created Time  :2016/8/2 14:20:58
File Name     :p511.cpp
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
#define mod 1000000007
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
ll dp[1100][1100];
int n,m;
int a[1100];
int b[1100];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
	while(cin>>n>>m){
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int j=1;j<=m;j++)scanf("%d",&b[j]);
		cle(dp);
		ll x;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i]==b[j])x=dp[i-1][j-1]+1;
				else x=0;
				dp[i][j]=(dp[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+mod)%mod;
				dp[i][j]=(dp[i][j]+x)%mod;
			}
		}
		printf("%I64d\n",dp[n][m]);
	}
    return 0;
}
