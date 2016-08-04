#include<cstdio>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

const int N=50007;
struct st{
	int left,right;
	int w;
};
st q[N*4];
int n;



void build(int num,int L,int R)
{
	q[num].left=L;
	q[num].right=R;
	if(L==R)
	{
		scanf("%d",&q[num].w);
		return;
	}
	build(2*num,L,(L+R)/2);
	build(2*num+1,(L+R)/2+1,R);
	q[num].w=q[2*num].w+q[2*num+1].w;
}

int Query(int num,int s,int t)
{
	if(q[num].left>=s&&q[num].right<=t)
		return q[num].w;
	int mid=(q[num].left+q[num].right)/2;
	int ans=0;
	if(mid>=t)
		ans+=Query(2*num,s,t);
	else if(mid<s)
		ans+=Query(2*num+1,s,t);
	else{
		ans+=Query(2*num,s,mid);
		ans+=Query(2*num+1,mid+1,t);
	}
	return ans;
}
void add(int num,int i,int j)
{
	if(q[num].left==q[num].right&&q[num].left==i)
	{
		q[num].w+=j;
		return;
	}
	int mid=(q[num].left+q[num].right)/2;
	if(mid>=i)
		add(2*num,i,j);
	else if(mid<i)
		add(2*num+1,i,j);
	q[num].w=q[2*num].w+q[2*num+1].w;
}

int main()
{
	int t;
	int cas=1;
	char ss[5];
	int a,b;
	scanf("%d",&t);
	while(t--)
	{
		printf("Case %d:\n",cas++);
		scanf("%d",&n);
		build(1,1,n);
		while(scanf("%s",ss))
		{
			if(strcmp(ss,"End")==0)
				break;
			scanf("%d%d",&a,&b);
			if(strcmp(ss,"Query")==0)
				printf("%d\n",Query(1,a,b));
			else if(strcmp(ss,"Sub")==0)
				add(1,a,-b);
			else
				add(1,a,b);
		}
	}
}


 
