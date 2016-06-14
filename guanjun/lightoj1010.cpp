/* ***********************************************
Author        :guanjun
Created Time  :2016/6/13 20:53:50
File Name     :1010.cpp
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
int n,m;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int T,ans;
	cin>>T;
	for(int t=1;t<=T;t++){
		scanf("%d%d",&n,&m);
		if(n>m)swap(n,m);
		int x,y;
		if(n&1){
			x=(n+1)/2;//第一个填 1
		}
		else x=n/2;
		if(m&1){
			y=(m+1)/2;
		}
		else y=m/2;
		ans=x*y+(n-x)*(m-y);

		if(n==1)ans=m;
		if(n==2){
			 ans=m/4*4;
			 if((m%4)==1)ans+=2;
			 if((m%4)>=2)ans+=4;
		}
		printf("Case %d: %d\n",t,max(max(n,m),ans));
	}
    return 0;
}
