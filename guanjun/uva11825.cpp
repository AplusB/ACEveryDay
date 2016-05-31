/* ***********************************************
Author        :guanjun
Created Time  :2016/5/31 15:35:14
File Name     :uva11825.cpp
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
#define maxn 16
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
int n,m,dp[(1<<16)+2];
int cover[(1<<16)+2];
int p[17];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
	int x;
	int cas=0;
	while(cin>>n&&n){
		for(int i=0;i<n;i++){
			scanf("%d",&m);
			p[i]=(1<<i);//最初只有自己
			while(m--){
				scanf("%d",&x);
				p[i]|=(1<<x);//构造p[i]集合
			}
		}
		for(int s=0;s<(1<<n);s++){
			cover[s]=0;
			for(int i=0;i<n;i++)
				if(s&(1<<i))cover[s]|=p[i];
		}
		int all=(1<<n)-1;
		dp[0]=0;
		for(int s=1;s<(1<<n);s++){
			dp[s]=0;
			for(int s0=s;s0;s0=(s0-1)&s){
				if(cover[s0]==all){
					dp[s]=max(dp[s],dp[s^s0]+1);
				}
			}
		}
		printf("Case %d: %d\n",++cas,dp[all]);  
	}
    return 0;
}
