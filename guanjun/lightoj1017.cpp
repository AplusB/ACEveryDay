/* ***********************************************
Author        :guanjun
Created Time  :2016/6/20 20:26:19
File Name     :1017.cpp
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
ll y[maxn];
map<int ,int >mp;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int T,n,w,k;
	ll x;
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>n>>w>>k;
		for(int i=1;i<=n;i++){
			cin>>x>>y[i];
		}
		sort(y+1,y+1+n);
		int a[1010]={0};
		int num=1;
		for(int i=1;i<=n;i++){
			x=y[i];
			for(int j=i;j>=1;j--){
				if(x-y[j]>w)break;
				a[i]++;
			}
		}
		//a[i]表示在i处刷一下 能覆盖前面多少点
		int dp[110][110]={0};//前 i个数选 j次能得到的最大值
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++){
				dp[i][j]=max(dp[i-1][j],dp[i-a[i]][j-1]+a[i]);
			}
		}
		printf("Case %d: %d\n",t,dp[n][k]);
	}
    return 0;
}
