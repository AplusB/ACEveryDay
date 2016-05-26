/* ***********************************************
Author        :guanjun
Created Time  :2016/5/26 15:30:33
File Name     :cf354c.cpp
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
int a[maxn];
int b[maxn];
int sum[maxn];
int n,k;
int solve(int *sum){
	int len=-1;
	for(int i=1;i<=n;i++){
		int x=upper_bound(sum+1,sum+1+n,sum[i-1]+k)-sum;
		x--;
		if(x-i+1>len)len=x-i+1;
	}
	return len;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
	char s[maxn];
	while(cin>>n>>k){
		scanf("%s",s+1);
		cle(sum);
		cle(a),cle(b);
		for(int i=1;i<=n;i++){
			if(s[i]=='a')a[i]=1;
			else b[i]=1;
		}
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+b[i];
		}
		int x=solve(sum);
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+a[i];
		}
		int y=solve(sum);
		cout<<max(x,y)<<endl;
	}
    return 0;
}
