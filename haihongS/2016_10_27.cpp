#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;
const int maxn=2e5+9;

ll n,m;
vector<ll> aha;
vector<ll> go;

ll change(ll x);
void bb(ll x);

int main()
{
	while(~scanf("%lld%lld",&n,&m))
	{
		aha.clear();
		for(ll i=1;i*i<=n;i++)
		{
			if(n%i==0)
			{
				if(i*i==n)
				{
					aha.push_back(i);
				}
				else
				{
					aha.push_back(i);
					aha.push_back(n/i);
				}
			}
		}
		int len=aha.size();
		ll ans=0;
		for(int i=0;i<len;i++)
		{
			ans+=change(aha[i]);
		}
		bb(ans);
	}

	return 0;
}

void bb(ll x)
{
	go.clear();
	while(x>0)
	{
		ll tmp=x%m;
		go.push_back(tmp);
		x/=m;
	}
	int len=go.size();
	for(int i=len-1;i>=0;i--)
	{
		if(go[i]>=10)
		{
			printf("%c",(char)(go[i]-10+'A'));
		}
		else
			printf("%lld",go[i]);
	}
	printf("\n");
}

ll change(ll x)
{
	ll ans=0;
	while(x>0)
	{
		ans+=(x%m)*(x%m);
		x/=m;
	}
	return ans;
}
