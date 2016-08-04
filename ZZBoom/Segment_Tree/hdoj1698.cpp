#include<cstdio>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

/*

DOTA中屠夫的钩子有N个链子组成，每个链子可有金，银，铜，三种材质做成，

铜链价值1，银价值2，金价值3，

先对钩子进行Q次的更新操作，

求出更新完后钩子的价值。

*/
const int N=100007;
struct st{
	int left,right;
	int sum;
	int val;
};
st q[N*4];
int n,m;

void build(int num,int L,int R)
{
	q[num].left=L;
	q[num].right=R;
	if(L==R)
	{
		q[num].sum=1;
		q[num].val=0;
		return;
	}
	build(2*num,L,(L+R)/2);
	build(2*num+1,(L+R)/2+1,R);
	q[num].sum=q[2*num].sum+q[2*num+1].sum;
	q[num].val=0;
}

void update(int num,int s,int t,int c)
{
	if(q[num].left>=s&&q[num].right<=t)
	{
		q[num].val=c;
		q[num].sum=c*(q[num].right-q[num].left+1);
		return;
	}
	if(q[num].val)
	{
		q[2*num].val=q[num].val;
		q[2*num].sum=q[num].val*(q[2*num].right-q[2*num].left+1);
		q[2*num+1].val=q[num].val;
		q[2*num+1].sum=q[num].val*(q[2*num+1].right-q[2*num+1].left+1);
		q[num].val=0;
	}
	int mid=(q[num].left+q[num].right)/2;
	if(mid>=t)
		update(2*num,s,t,c);
	else if(mid<s)
		update(2*num+1,s,t,c);
	else
	{
		update(2*num,s,mid,c);
		update(2*num+1,mid+1,t,c);
	}
	q[num].sum=q[2*num+1].sum+q[2*num].sum;
}

int main()
{
	int t;
	scanf("%d",&t);
	int cas=1;
	while(t--)
	{
		scanf("%d",&n);
		build(1,1,n);
		scanf("%d",&m);
		while(m--)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			update(1,a,b,c);
		}
		printf("Case %d: The total value of the hook is %d.\n",cas++,q[1].sum);
	}
	return 0;
}



