#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=2e6+9;
const int inf=2e9+9;
const ll mod=1e9+7;
const double eps=1e-9;

int pre[maxn],deq[maxn],mm[maxn],a[maxn];

int deal(int len,int m);

int main()
{ 
	int n;
	while(scanf("%d",&n) && n)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		pre[0]=0;
		for(int i=1;i<=n;i++)
			pre[i]=pre[i-1]+a[i];
		for(int i=n+1;i<=2*n;i++)
			pre[i]=pre[i-1]+a[i-n];
		int ans=deal(n,n);
		printf("%d\n",ans);
	}
	return 0;
}

int deal(int len,int m)
{
	int ans=0;
	int head,tail,now;
	head=tail=0,now=1;
	for(int i=1;i<=len;i++)
	{
		while(head!=tail && deq[head]<i) head++;
		while(now<=i+m-1)
		{
			while(head!=tail && pre[deq[tail-1]]>=pre[now])
				tail--;
			deq[tail++]=now;
			now++;
		}
		if(pre[deq[head]]-pre[i-1]>=0) ans++;
	}
	return ans;
}
