/* ***********************************************
Author        :guanjun
Created Time  :2016/6/19 19:11:25
File Name     :1016.cpp
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
#define INF 1<<30
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
vector<int>v;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int T,a,n,x,y;
	ll w;
	cin>>T;
	for(int t=1;t<=T;t++){
		v.clear();
		cin>>n>>w;
		for(int i=1;i<=n;i++){
			cin>>x>>y;
			v.push_back(y);
		}
		sort(v.begin(),v.end());
		int k=v[0];
		ll ans=1;
		for(int i=1;i<v.size();i++){
			if(v[i]<=k+w)continue;
			else{
				ans++;
				k=v[i];
			}
		}
		printf("Case %d: %d\n",t,ans);
	}
    return 0;
}
