/* ***********************************************
Author        :guanjun
Created Time  :2016/7/8 19:36:30
File Name     :1029.cpp
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

struct node{
	int s,e;
	int w;
}nod[maxn];
bool cmp1(node a,node b){
    return a.w<b.w;
}
bool cmp2(node a,node b){
	return a.w>b.w;
}
int n;
int sz=0;
int fa[maxn];
int sum;
void init(){
	sum=0;
	for(int i=0;i<maxn;i++)fa[i]=i;
}
int findfa(int x){
	if(x==fa[x])return x;
	return fa[x]=findfa(fa[x]);
}
int kur(int judge){
	init();
	if(judge)sort(nod,nod+sz,cmp1);
	else sort(nod,nod+sz,cmp2);
	for(int i=0;i<sz;i++){
		int a=findfa(nod[i].s);
		int b=findfa(nod[i].e);
		if(a!=b){
			fa[a]=b;
			sum+=nod[i].w;
		}
	}
	return sum;

}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int T,x,y,w;
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>n;
		sz=0;
		while(cin>>x>>y>>w){
			if(x==0&&y==0&&w==0)break;
			nod[sz].s=x;
			nod[sz].e=y;
			nod[sz].w=w;
			sz++;
		}
		x=kur(1)+kur(0);
		int c=__gcd(x,2);
		if(c==2)printf("Case %d: %d\n",t,x/2);
		else printf("Case %d: %d/%d\n",t,x,2);
	}
    return 0;
}
