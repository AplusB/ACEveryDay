/* ***********************************************
Author        :guanjun
Created Time  :2016/5/22 19:48:37
File Name     :hdu5701.cpp
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
int a[maxn];
int sum[maxn];
int mp[maxn*2];
int n;
int f(int x){
	cle(sum); 
	cle(mp);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]>a[x])sum[i]=1;
		else if(a[i]<a[x])sum[i]=-1;
		else sum[i]=0;
		sum[i]+=sum[i-1];
	}
	for(int i=x;i<=n;i++)mp[sum[i]+maxn]++;
	for(int i=1;i<=x;i++)ans+=mp[sum[i-1]+maxn];
	return ans;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r", stdin);
    #endif
    //freopen("out.txt","w",stdout);
    while(cin>>n){
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)printf("%d%c",a[i],i==n?10:' ');
		for(int i=1;i<=n;i++){
			printf("%d%c",f(i),i==n?10:' ');
		}
	}
    return 0;
}
