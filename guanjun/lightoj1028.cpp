/* ***********************************************
Author        :guanjun
Created Time  :2016/7/6 23:39:26
File Name     :1028.cpp
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
#define maxn 1001000
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
ll prime[maxn];
ll vis[maxn];
int tot;
void init(){
	cle(vis);
	tot=0;
	for(ll i=2;i<maxn;i++){
		if(!vis[i]){
			prime[tot++]=i;
			for(ll j=i*i;j<maxn;j+=i)
				vis[j]=1;
		}
	}
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    init();

	int T;
	ll n;
	cin>>T;
	for(int t=1;t<=T;t++){
		int num=0;
		ll ans=1;
		scanf("%lld",&n);
		for(int i=0;i<tot&&prime[i]*prime[i]<=n;i++){
			if(n%prime[i]==0){
				num=0;
				while(n%prime[i]==0){
					num++;n/=prime[i];
				}
				ans*=(num+1);
			}
		}
		if(n>1)ans*=2;
		printf("Case %d: %lld\n",t,ans-1);  
	}
    return 0;
}
