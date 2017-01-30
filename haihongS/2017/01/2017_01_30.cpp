#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e3+9;
const ll mod=1e9+7;
const ll inf=2e9+9;
double eps=1e-9;
double pi=acos(-1.0);

int judge(ll x);
vector<ll> ans;

int main()
{
	ll n,k;
	while(~scanf("%lld%lld",&n,&k))
	{
		ll go=1;
		ans.clear();
		for(ll i=1;i*i<=n;i++)
		{
			if(n%i==0)
			{
				ans.push_back(i);
				if(i*i!=n) ans.push_back(n/i);
			}
		}
		sort(ans.begin(),ans.end());
		int len=ans.size(),flag=1;
		for(int i=0;i<len;i++)
		{
			if(k==0) break;
			go=ans[i];
			k--;
		}
		if(k>0) flag=0;
		if(flag) printf("%lld\n",go);
		else puts("-1");
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
