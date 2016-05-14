/* ***********************************************
Author        :shootPlane
Created Time  :2016年05月06日 星期五 15时01分21秒
File Name     :3368.cpp
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
const int maxn=1e5+9;
const int inf=1e9+9;

struct lisan
{
	int v,l,r;
}vv[maxn];

struct II
{
	int maxx,l,r;
}tree[4*maxn];

int n,q;
int num[maxn];

int build(int node,int l,int r);
int query(int node,int l,int r,int L,int R);

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	while(scanf("%d",&n) && n)
	{
		scanf("%d",&q);

		int loca=0;
		scanf("%d",&num[0]);
		vv[loca].v=num[0],vv[loca].l=0;
		int last=num[0];

		for(int i=1;i<n;i++)
		{
			scanf("%d",&num[i]);
			if(num[i]!=last)
			{
				last=num[i];
				vv[loca].r=i-1;
				loca++;
				vv[loca].v=num[i],vv[loca].l=i;
			}
		}
		vv[loca].r=n-1;

		build(0,0,loca);

		while(q--)
		{
			int i,j;
			scanf("%d%d",&i,&j);
			i--,j--;
			int ans=query(0,0,loca,i,j);
			printf("%d\n",ans);
		}
	}
    return 0;
}

int query(int node,int l,int r,int L,int R)
{
	if(R<tree[node].l || L>tree[node].r) return 0;
	if(l==r)
    {
        return min(tree[node].r,R)-max(tree[node].l,L)+1;
    }
	if(L<=tree[node].l && tree[node].r<=R) return tree[node].maxx;

	int mid=l+(r-l)/2;
	int t1=query(2*node+1,l,mid,L,R);
	int t2=query(2*node+2,mid+1,r,L,R);
	return max(t1,t2);
}

// [l,r]
int build(int node,int l,int r)
{
	if(l==r)
	{
		tree[node].l=vv[l].l,tree[node].r=vv[l].r;
		tree[node].maxx=tree[node].r-tree[node].l+1;
		return 0;
	}
	int mid=l+(r-l)/2;
	build(2*node+1,l,mid);
	build(2*node+2,mid+1,r);
	tree[node].l=tree[2*node+1].l;
	tree[node].r=tree[2*node+2].r;
	tree[node].maxx=max(tree[2*node+1].maxx,tree[2*node+2].maxx);
	return 0;
}
