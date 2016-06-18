/* ***********************************************
Author        :guanjun
Created Time  :2016/6/18 22:38:57
File Name     :1014.cpp
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
vector<ll>v;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int T;
	ll p,l;
	cin>>T;
	for(int t=1;t<=T;t++){
		printf("Case %d: ",t);
		v.clear();
		scanf("%lld %lld",&p,&l);
		ll n=p-l;
		for(ll i=1;i*i<=n;i++){
			if(n%i==0){
				if(i>l)v.push_back(i);
				if(n/i>l&&(i*i!=n))v.push_back(n/i);
			}
		}
		sort(v.begin(),v.end());
		int m=v.size();
		for(int i=0;i<m;i++){
			printf("%lld%c",v[i],i==m-1?10:' ');
		}
		if(m==0)puts("impossible");
	}
    return 0;
}
