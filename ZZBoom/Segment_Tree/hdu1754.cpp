#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

const int INF=-0x3f3f3f3f;
const int MAXN=200000;

struct st{
	int left,right;
	int maxx;
};
st q[MAXN*4];
int n,m;


void built(int num,int L,int R)
{
	q[num].left=L;
	q[num].right=R;
	if(q[num].left==q[num].right)
	{
		scanf("%d",&q[num].maxx);
		return;
	}
	built(2*num,L,(L+R)/2);
	built(2*num+1,(L+R)/2+1,R);
	q[num].maxx=max(q[2*num].maxx,q[2*num+1].maxx);
}

int get_maxa(int s,int t,int num)
{
	if(s<=q[num].left&&t>=q[num].right)
		return q[num].maxx;
	if(s>q[num].right||t<q[num].left)
		return INF;
	int a,b;
	a=get_maxa(s,t,2*num);
	b=get_maxa(s,t,2*num+1);
	return max(a,b);
}

void update(int i,int x,int num)
{
	if(q[num].left>i||q[num].right<i)
		return;
	if(q[num].left==i&&q[num].right==q[num].left)
	{
		q[num].maxx=x;
		return;
	}
	if(q[num].left<=i&&q[num].right>=i)
	{
		update(i,x,2*num);
		update(i,x,2*num+1);
		q[num].maxx=max(q[2*num].maxx,q[2*num+1].maxx);
	}
}

int main()
{
	char ss[5];
	int x,y;
	while(~scanf("%d%d",&n,&m))
	{
		built(1,1,n);
		while(m--)
		{
			scanf("%s%d%d",&ss,&x,&y);
			if(strcmp(ss,"Q")==0)
			{
				int ans=get_maxa(x,y,1);
				printf("%d\n",ans);
			}
			else
			{
				update(x,y,1);
			}
		}
	}
	return 0;
}



