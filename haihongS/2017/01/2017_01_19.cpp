#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>


using namespace std;
typedef long long ll;
const int maxn=2e6+9;
const double inf=2e13+9;
const ll mod=1e9+7;
double eps=1e-6;
double pi=acos(-1.0);

ll a[maxn];
int n;
vector<ll> go;

void update(int x);
ll sum(int x);
int lowbit(int x);

int main()
{
	int k;
	while(~scanf("%d%d",&n,&k))
	{
		go.clear();
		memset(a,0,sizeof(a));
		if(k>n/2)
			k=n-k;
		ll ans=1;
		int now=1;
		for(int i=1;i<=n;i++)
		{
			int to=now+k;
			if(to>n) to-=n;
			ans+=1;
			if(now<to)
			{
				ans+=sum(to-1)-sum(now);
			}
			else
			{
				ll tmp=sum(n)-sum(now);
				tmp+=sum(to-1);
				ans+=tmp;
			}
			go.push_back(ans);
			update(now);
			update(to);
			now=to;
		}
		int len=go.size();
		for(int i=0;i<len;i++)
		{
			if(i!=0) putchar(' ');
			printf("%lld",go[i]);
		}
		printf("\n");
	}
	return 0;
}

ll sum(int x)
{
	ll ans=0;
	while(x>0)
	{
		ans+=a[x];
		x-=lowbit(x);
	}
	return ans;
}

void update(int x)
{
	while(x<=n)
	{
		a[x]+=1;
		x+=lowbit(x);
	}
}

int lowbit(int x)
{
	return x&(-x);
}
