/* ***********************************************
Author        :shootPlane
Created Time  :2016年06月07日 星期二 21时12分53秒
File Name     :3171.cpp
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
	int l,r,s;
}num[maxn];

struct X
{
	int minn;
}tree[4*maxn];

int n,m,e;
int dp[maxn];

int build(int node,int l,int r);
int	query(int node,int l,int r,int L,int R);
int update(int node,int l,int r,int pos,int v);
int cmp(const II&a,const II&b);

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(~scanf("%d%d%d",&n,&m,&e))
	{
		m++,e++;
		e++;
		for(int i=0;i<maxn;i++) dp[i]=inf;
		dp[m-1]=0;

		build(0,m,e);
		update(0,m,e,m-1,0);

		for(int i=0;i<n;i++)
		{
			int l,r,s;
			scanf("%d%d%d",&l,&r,&s);
			l++,r++;
			r++;
			num[i].l=l,num[i].r=r,num[i].s=s;
		}
		sort(num,num+n,cmp);

		for(int i=0;i<n;i++)
		{
			int l,r,s;
			l=num[i].l,r=num[i].r,s=num[i].s;
			int mm=query(0,m,e,l,r-1);
			dp[r]=min(dp[r],mm+s);
			update(0,m,e,r,dp[r]);
		}

		if(dp[e]==inf)
			printf("-1\n");
		else
			printf("%d\n",dp[e]);

	}
    return 0;
}


int cmp(const II&a,const II&b)
{
	if(a.r==b.r) return a.l<b.l;
	return a.r<b.r;
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
		mm=update(2*node+2,mid+1,r,pos,v);
	tree[node].minn=min(tree[node].minn,mm);
	return tree[node].minn;
}

int	query(int node,int l,int r,int L,int R)
{
	if(L<=l && r<=R) return tree[node].minn;
	if(r<L || l>R) return inf;
	int mid=l+(r-l)/2;
	int m1=query(2*node+1,l,mid,L,R);
	int m2=query(2*node+2,mid+1,r,L,R);
	return min(m1,m2);
}


int build(int node,int l,int r)
{
	if(l==r){tree[node].minn=inf;return 0;}
	int mid=l+(r-l)/2;
	build(2*node+1,l,mid);
	build(2*node+2,mid+1,r);
	tree[node].minn=inf;
	return 0;
}
