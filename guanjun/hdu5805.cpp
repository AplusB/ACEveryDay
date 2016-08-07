/* ***********************************************
Author        :guanjun
Created Time  :2016/8/7 9:01:43
File Name     :hdu5805.cpp
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
ll a[100010];
ll p[100100];
ll s[100100];
int n;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int t;
	cin>>t;
	while(t--){
		cin>>n;
		ll ans=0;
		for(int i=1;i<=n;i++)scanf("%I64d",&a[i]);
		cle(p);
		for(int i=2;i<=n;i++){
			p[i]=max(abs(a[i]-a[i-1]),p[i-1]);
		}
		cle(s);
		for(int i=n-1;i>=1;i--){
			s[i]=max(s[i+1],abs(a[i+1]-a[i]));
		}
		for(int i=1;i<=n;i++){
			if(i==1)ans+=s[2];
			if(i==n)ans+=p[n-1];
			if(i<n&&i>1){
				ans+=max(max(abs(a[i+1]-a[i-1]),p[i-1]),s[i+1]);
			}
		}
		printf("%I64d\n",ans);

	}
    return 0;
}
