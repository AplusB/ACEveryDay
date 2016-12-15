/* ***********************************************
Author        :shootPlane
Created Time  :2016年06月06日 星期一 21时02分09秒
File Name     :1769.cpp
Blog          :http://haihongblog.com
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <stack>
using namespace std;
typedef long long ll;
const int maxn=5e5+9;
const int inf=1e9+9;

struct II
{
	int lt,rt;
}num[maxn];

struct X
{
	int minn;
}tree[4*maxn];

int n,m;
int dp[maxn];

int build(int node,int lt,int rt);
int query(int node,int l,int r,int L,int R);
int update(int node,int l,int r,int pos,int v);

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	while(~scanf("%d%d",&n,&m))
	{
		build(0,1,n);
		for(int i=0;i<maxn;i++)
			dp[i]=inf;
		dp[1]=0;
		update(0,1,n,1,0);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&num[i].lt,&num[i].rt);
		}
		for(int i=0;i<m;i++)
		{
			int s=num[i].lt,e=num[i].rt;
			dp[e]=min(dp[e],query(0,1,n,s,e-1)+1);
			update(0,1,n,e,dp[e]);
		}
		printf("%d\n",dp[n]);
	}
    return 0;
}


int update(int node,int l,int r,int pos,int v)
{
	if(l==r)
	{
		tree[node].minn=min(tree[node].minn,v);
		return tree[node].minn;
	}
	int mid=l+(r-l)/2;
	int mm;
	if(pos<=mid)
		mm=update(2*node+1,l,mid,pos,v);
	else 
		mm=min(mm,update(2*node+2,mid+1,r,pos,v));
	tree[node].minn=min(tree[node].minn,mm);
	return tree[node].minn;
}


int query(int node,int l,int r,int L,int R)
{
	if(L<=l && r<=R)
		return tree[node].minn;
	if(r<L || l>R) return inf;

	int mid=l+(r-l)/2;
	int mm=query(2*node+1,l,mid,L,R);
	mm=min(mm,query(2*node+2,mid+1,r,L,R));
	return mm;
}

int build(int node,int lt,int rt)
{
	if(lt==rt)
	{
		tree[node].minn=inf;return tree[node].minn;
	}
	int mid=lt+(rt-lt)/2;
	int mm=build(2*node+1,lt,mid);
	mm=min(mm,build(2*node+2,mid+1,rt));
	tree[node].minn=mm;
	return mm;
}
