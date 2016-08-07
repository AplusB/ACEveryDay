#include<cstdio>
#include<math.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;

const int N=1e4+10;

struct asd{
	int left,right;
	int ls,rs;
	int ms;
};
asd q[N*20];

void build(int num,int L,int R)
{
	q[num].left=L;
	q[num].right=R;
	q[num].ls=q[num].rs=q[num].ms=R-L+1;
	if(L!=R)
	{
		int mid=(L+R)/2;
		build(2*num,L,mid);
		build(2*num+1,mid+1,R);
	}
}

int query(int num,int t)
{
	if(q[num].left==q[num].right||q[num].ms==0||q[num].ms==(q[num].right-q[num].left+1))
		return q[num].ms;
	int mid=(q[num].right+q[num].left)/2;
	

	if(t<=mid)
	{
		if(t>=(q[2*num].right-q[2*num].rs+1))
			return query(2*num,t)+query(2*num+1,mid+1);
		else
			return query(2*num,t);
	}
	else
	{
		if(t<=q[2*num+1].left+q[2*num+1].ls-1)
			return query(2*num+1,t)+query(2*num,mid);
		else
			return query(2*num+1,t);
	}
}

void update(int num,int t,int x)
{
	if(q[num].left==q[num].right)
	{
		if(x==1)
			q[num].ls=q[num].rs=q[num].ms=1;
		else
			q[num].ls=q[num].rs=q[num].ms=0;
		return;
	}

	int mid=(q[num].left+q[num].right)/2;
	
	if(mid>=t)
		update(2*num,t,x);
	else
		update(2*num+1,t,x);

	q[num].ls=q[2*num].ls;
	q[num].rs=q[2*num+1].rs;

	q[num].ms=max(q[2*num].ms,max(q[2*num+1].ms,q[2*num].rs+q[2*num+1].ls));

	if(q[2*num].ls==(q[2*num].right-q[2*num].left+1))
		q[num].ls+=q[2*num+1].ls;
	if(q[2*num+1].rs==(q[2*num+1].right-q[2*num+1].left+1))
		q[num].rs+=q[2*num].rs;
}

int re[N*5];
int main()
{
	char ss[5];
	int n,m,x,pos,u;
	while(~scanf("%d%d",&n,&m))
	{
		scanf("%d%d",&n,&m);
		build(1,1,n);
		pos=0;
		for(int i=0;i<m;i++)
		{
			scanf("%s",ss);
			if(strcmp(ss,"R")==0)
			{
				u=re[pos];
				pos--;
				update(1,u,1);
			}
			else if(strcmp(ss,"D")==0)
			{
				scanf("%d",&x);
				re[++pos]=x;
				update(1,x,0);
			}
			else
			{
				scanf("%d",&x);
				printf("%d\n",query(1,x));
			}
		}
	}
	return 0;
}
