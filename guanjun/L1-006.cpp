/* ***********************************************
Author        :guanjun
Created Time  :2016/7/14 9:17:25
File Name     :L1-006.cpp
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
#define maxn 40100
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
ll n,lx,rx;
vector<ll>v;
int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    while(cin>>n){
		v.clear();
		v.push_back(n);
		for(ll i=2;i*i<=n;i++){
			if(n%i==0){
				if(i*i==n)v.push_back(i);
				else v.push_back(i),v.push_back(n/i);
			}
		}
		sort(v.begin(),v.end());
		int m=v.size();
		int x,y,t;
		int ans=0;
		for(int i=0;i<m;i++){
			x=i+1;
			y=i-1;
			t=i;
			ll k=v[i];
			while(y>0&&(n%(k*v[y])==0)){
				k*=v[y];
				if(v[y]==v[t]-1)t=y,y--;
				else break;
			}
			t=i;
			while(x<m&&(n%(k*v[x])==0)){
				k*=v[x];
				if(v[x]==v[t]+1)t=x,x++;
				else break;
			}
			if(x-y-1>ans&&(n%k==0)){
				ans=x-y-1;
				lx=y;rx=x;
			}
		}
		printf("%d\n",ans);
		for(int i=lx+1;i<rx;i++){
			printf("%lld%c",v[i],i==rx-1?10:'*');
		}
	}
    return 0;
}
