/* ***********************************************
Author        :guanjun
Created Time  :2016/8/29 9:10:36
File Name     :cfaim3b.cpp
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
#define INF 1LL<<60
#define maxn 100010
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
ll a[maxn];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
	int n;ll x;
	while(cin>>n>>x){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n==1){
			cout<<0<<endl;continue;
		}
		sort(a+1,a+1+n);
		ll ans=0;
		if(a[1]>=x){
			ans=a[n-1]-x;
		}
		else if(x>=a[n]){
			ans=x-a[2];
		}
		else{
			ll x1=INF,x2=INF,x3=INF,x4=INF;
			if(a[n-1]-x<=0){
				x1=x2=x-a[1];
			}
			else{
				x1=2*(a[n-1]-x)+x-a[1];
				x2=2*(x-a[1])+a[n-1]-x;
			}
			x1=min(x1,x2);
			if(x-a[2]<=0){
				x3=x4=a[2]-x+a[n]-a[2];
			}
			else{
				x3=2*(x-a[2])+a[n]-x;
				x4=2*(a[n]-x)+x-a[2];
			}
			x3=min(x3,x4);
			ans=min(x3,x1);
		}
		cout<<ans<<endl;
	}
    return 0;
}
