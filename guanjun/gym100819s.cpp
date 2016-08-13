/* ***********************************************
Author        :guanjun
Created Time  :2016/8/13 13:48:58
File Name     :voh.cpp
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
#define maxn 300100
#define cle(a) memset(a,0,sizeof(a))
const ull inf = 1LL << 61;
const double eps=1e-5;
using namespace std;

struct Node{
	ll beg;
	ll end;
	ll val;
	int id;
}nod[maxn];

struct cmp{
    bool operator()(Node a,Node b){
        if(a.end==b.end) return a.beg<b.beg;
        return a.end>b.end;
	}
};

bool cmp1(Node a,Node b){
	if(a.beg==b.beg)return a.end<b.end;
	return a.beg<b.beg;
}
int n;
ll dp[maxn][2];
priority_queue<Node,vector<Node>,cmp>q;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    while(cin>>n){
		ll x;
		for(int i=1;i<=n;i++){
			scanf("%lld %lld %lld",&nod[i].beg,&nod[i].val,&x);
			nod[i].end=nod[i].beg+x;
		}
		sort(nod+1,nod+1+n,cmp1);
		int sum=0;
		for(int i=1;i<=n;i++)nod[i].id=i;
		while(!q.empty())q.pop();
		Node u,v;
		ll Max=0;
		cle(dp);
		for(int i=1;i<=n;i++){
			v=nod[i];
			q.push(v);
			while(!q.empty()){
				u=q.top();
				if(u.end<=v.beg){
					q.pop();
					Max=max(Max,dp[u.id][1]);
				}
				else break;
			}
			dp[i][1]=Max+nod[i].val;
			dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
		}
		printf("%lld\n",max(dp[n][1],dp[n][0]));
	}
    return 0;
}
