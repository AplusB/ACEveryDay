#include<cstdio>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

const int N=50007;
struct st{
	int left,right;
	int mina;
	int maxa;
};
st q[N*4];
int n,m;

void build(int num,int L,int R)
{
	q[num].left=L;
	q[num].right=R;
	if(L==R)
	{
		scanf("%d",&q[num].maxa);
		q[num].mina=q[num].maxa;
		return;
	}
	build(2*num,L,(L+R)/2);
	build(2*num+1,(L+R)/2+1,R);
	q[num].mina=min(q[2*num].mina,q[2*num+1].mina);
	q[num].maxa=max(q[2*num].maxa,q[2*num+1].maxa);
}
int ans1;
int ans2;
int get_max(int num,int s,int t)
{
	if(q[num].left>=s&&q[num].right<=t)
		return q[num].maxa;
	int mid=(q[num].left+q[num].right)/2;
	if(mid>=t)
		return get_max(2*num,s,t);
	else if(mid<s)
		return get_max(2*num+1,s,t);
	else{
		return max(get_max(2*num,s,mid),get_max(2*num+1,mid+1,t));
	}
}

int get_min(int num,int s,int t)
{
	if(q[num].left>=s&&q[num].right<=t)
		return q[num].mina;
	int mid=(q[num].left+q[num].right)/2;
	if(mid>=t)
		return get_min(2*num,s,t);
	else if(mid<s)
		return get_min(2*num+1,s,t);
	else{
		return min(get_min(2*num,s,mid),get_min(2*num+1,mid+1,t));
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	build(1,1,n);
	while(m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",get_max(1,a,b)-get_min(1,a,b));
	}
	return 0;
}

 
