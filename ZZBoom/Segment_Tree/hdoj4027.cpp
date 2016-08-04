#include<cstdio>
#include<math.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
typedef __int64 LL;

const int N=100007;
struct st{
	int left,right;
	LL sum;
	LL len;
};
st q[N*4];

void build(int num,int L,int R)
{
	q[num].left=L;
	q[num].right=R;
	if(L==R)
	{
		scanf("%lld",&q[num].sum);
		q[num].len=1;
		return;
	}
	build(2*num,L,(L+R)/2);
	build(2*num+1,(L+R)/2+1,R);
	q[num].len=R-L+1;
	q[num].sum=q[2*num].sum+q[2*num+1].sum;
}

void update(int num,int s,int t)
{
	if(q[num].left>=s&&q[num].right<=t)
	{
		if(q[num].sum==q[num].len)
			return;
		if(q[num].left==q[num].right)
		{
			q[num].sum=LL(sqrt(q[num].sum));
			return;
		}
		update(2*num,q[num].left,(q[num].left+q[num].right)/2);
		update(2*num+1,(q[num].left+q[num].right)/2+1,q[num].right);
		q[num].sum=q[2*num].sum+q[2*num+1].sum;
		return;
	}
	int mid=(q[num].left+q[num].right)/2;
	if(mid>=t)
		update(2*num,s,t);
	else if(mid<s)
		update(2*num+1,s,t);
	else
	{
		update(2*num,s,mid);
		update(2*num+1,mid+1,t);
	}
	q[num].sum=q[2*num].sum+q[2*num+1].sum;
}

LL query(int num,int s,int t)
{
	if(q[num].left>=s&&q[num].right<=t)
		return q[num].sum;
	int mid=(q[num].left+q[num].right)/2;
	LL ans=0;
	if(mid>=t)
		ans+=query(2*num,s,t);
	else if(mid<s)
		ans+=query(2*num+1,s,t);
	else
	{
		ans+=query(2*num,s,mid);
		ans+=query(2*num+1,mid+1,t);
	}
	return ans;
}


int main()
{
	int n,m;
	int cas=1;
	while(~scanf("%d",&n))
	{
		build(1,1,n);
		/*for(int i=1;i<=19;i++)
		{
			printf("%d %d %lld \n",q[i].left,q[i].right,q[i].sum);
		}*/
		printf("Case #%d:\n",cas++);
		scanf("%d",&m);
		while(m--)
		{
			int t,x,y;
			scanf("%d%d%d",&t,&x,&y);
			if(x>y)
				swap(x,y);
			if(t)
				printf("%lld\n",query(1,x,y));
			else
				update(1,x,y);
			/*puts("");
			for(int i=1;i<=19;i++)
			{
				printf("%d %d %lld \n",q[i].left,q[i].right,q[i].sum);
			}
			puts("");*/ 
		}
		puts("");
	}
}

