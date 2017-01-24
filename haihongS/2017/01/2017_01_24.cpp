#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e6 + 9;
const ll inf = 2e9 + 9;

map<ll,int> aha;
map<int,ll> rev;
int flag[maxn];

int judge(ll x);

int main()
{
	ll n;
	while(~scanf("%lld",&n))
	{
		if(n==1)
		{
			printf("1=1\n");continue;
		}
		aha.clear();
		rev.clear();
		ll pri=n;
		memset(flag,0,sizeof(flag));
		int id=1;
		for(ll i=2;;i++)
		{
			if(judge(n))
			{
				if(aha[n]==0)
					aha[n]=id++,rev[id-1]=n;
				int tmp=aha[n];
				flag[tmp]++;
				break;
			}
			if(n==1) break;
			if(judge(i)==0) continue;
			while(n%i==0)
			{
				if(aha[i]==0)
					aha[i]=id++,rev[id-1]=i;
				int tmp=aha[i];
				flag[tmp]++;
				n/=i;
			}
		}
		printf("%lld=",pri);
		int ok=0;
		for(int i=1;i<id;i++)
		{
			if(rev[i]==1) continue;
			if(ok==1) printf("*");
			ok=1;
			printf("%lld",rev[i]);
			if(flag[i]>1) printf("^%d",flag[i]);
		}
		printf("\n");
	}
	return 0;
}

int judge(ll x)
{
	if(x==1) return 0;
	for(ll i=2;i*i<=x;i++)
	{
		if(x%i==0) return 0;
	}
	return 1;
}
