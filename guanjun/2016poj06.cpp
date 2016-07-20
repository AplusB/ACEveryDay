/* ***********************************************
Author        :guanjun
Created Time  :2016/7/20 22:15:28
File Name     :2016poj06.cpp
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
ll a[100010];
ll dp1[100010];
ll dp2[100010];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		cle(dp1),cle(dp2);
		ll Min=a[1];
		for(int i=2;i<=n;i++){
			dp1[i]=max(dp1[i-1],a[i]-Min);
			Min=min(Min,a[i]);
		}
		ll Max=a[n];
		for(int i=n-1;i>=1;i--){
			dp2[i]=max(dp2[i+1],Max-a[i]);
			Max=max(Max,a[i]);
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,dp1[i]+dp2[i]);
		}
		printf("%lld\n",ans);
	}
    return 0;
}
