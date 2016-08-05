/* ***********************************************
Author        :guanjun
Created Time  :2016/8/5 13:42:35
File Name     :hdu5793.cpp
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
#define MOD 1000000007
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
ll Pow(ll a,ll n,ll m){
	ll ans=1;
	while(n){
		if(n&1){
			ans*=a;
			ans%=m;
		}
		a=a*a%m;
		n>>=1;
	}
	return ans;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int t;
	ll n,m;
	cin>>t;
	while(t--){
		scanf("%I64d %I64d",&n,&m);
		printf("%lld\n",((Pow(m,n+1,MOD)-1)*Pow(m-1,MOD-2,MOD)%MOD+MOD)%MOD);
	}
    return 0;
}
