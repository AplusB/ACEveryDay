/* ***********************************************
Author        :guanjun
Created Time  :2016/5/15 19:30:57
File Name     :1.cpp
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
struct node{
	int l,r;
}nod[maxn];
int in[maxn];
int po[maxn];
int build(int l1,int r1,int l2,int r2){
	if(l1>r1)return 0;
	int root=po[r2];
	int p=l1;
	while(in[p]!=root)p++;
	int cnt=p-l1;
	nod[root].l=build(l1,p-1,l2,l2+cnt-1);
	nod[root].r=build(p+1,r1,l2+cnt,r2-1);
	return root;
}

void bfs(int x){
	queue<int>q;
	q.push(x);
	vector<int>v;
	while(!q.empty()){
		int w=q.front();q.pop();
		if(w==0)break;
		v.push_back(w);
		if(nod[w].l!=0)q.push(nod[w].l);
		if(nod[w].r!=0)q.push(nod[w].r);
	}
	int m=v.size();
	for(int i=0;i<m;i++){
		printf("%d%c",v[i],i==m-1?10:' ');
	}
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int n;
	while(cin>>n){
		for(int i=1;i<=n;i++)cin>>po[i];
		for(int i=1;i<=n;i++)cin>>in[i];
		build(1,n,1,n);
		int root=po[n];
		bfs(root);
	}
    return 0;
}
