/* ***********************************************
Author        :guanjun
Created Time  :2016/7/10 20:16:39
File Name     :uva10891.cpp
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
int vis[110][110];
int sum[110];
int d[110][110];
int dp(int i,int j){
	if(vis[i][j])return d[i][j];
	vis[i][j]=1;
	int m=0;
	for(int k=i+1;k<=j;k++)m=min(m,dp(k,j));
	for(int k=i;k<j;k++)m=min(m,dp(i,k));
	d[i][j]=sum[j]-sum[i-1]-m;
	return d[i][j];
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
	int a,n;
    while(cin>>n){
		cle(vis);
		sum[0]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a);
			sum[i]=sum[i-1]+a;
		}
		printf("%d\n",2*dp(1,n)-sum[n]);
	}
    return 0;
}
