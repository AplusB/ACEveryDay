/* ***********************************************
Author        :guanjun
Created Time  :2016/6/11 16:15:19
File Name     :1008.cpp
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
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
	int T;
	ll s;
	ll n,x,y;
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>s;
		n=ceil(sqrt(s*1.0));
		if(n*n-s<n)x=n,y=n*n-s+1;
		else x=2*n-n*n+s-1,y=n;
		if(n&1)swap(x,y);
		printf("Case %d: %lld %lld\n",t,x,y);
	}
    return 0;
}
