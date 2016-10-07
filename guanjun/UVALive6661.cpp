/* ***********************************************
Author        :guanjun
Created Time  :2016/10/7 14:20:37
File Name     :La6661.cpp
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
//dp[i][j][k]
//i个数 最大值为j 和为k的方案数
int dp[11][25][200];
int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int n,K,s;
	while(cin>>n>>K>>s){
		if(n==0&&K==0&&s==0)break;
		cle(dp);
		for(int j=1;j<=20;j++){
			dp[1][j][j]=1;
			dp[0][j][0]=1;
		}
		dp[1][1][1]=1;
		for(int i=1;i<=K;i++){
			for(int j=2;j<=n;j++){
				for(int k=1;k<=i*j;k++){
					dp[i][j][k]=dp[i][j-1][k];
					if(k>=j)dp[i][j][k]+=dp[i-1][j-1][k-j];

				}
			}
		}
		cout<<dp[K][n][s]<<endl;
	}
    return 0;
}
