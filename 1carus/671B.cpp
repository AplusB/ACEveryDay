#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

const int MAXN = 5e6 + 5; 
ll n,k;
ll coin[MAXN];
ll sum;

ll get_min()
{
	ll l,r;
	l = *min_element(coin,coin + n);
	r = sum / n;
	int i;
	
	while(l < r)
	{
		int mid = l + ((r - l + 1) >> 1);
		ll temp = 0;
		for(i = 0;i < n;i++)
		{
			if(coin[i] < mid)
			{
				temp += mid - coin[i];
			}
		}
		
		if(temp <= k)
		{
			l = mid;
		}
		else r = mid - 1;
	}
}

ll get_max()
{
	ll l,r;
	l = (sum + n - 1) / n; // 向上取整
	r = *max_element(coin,coin + n);
	
	int i;
	while(l < r)
	{
		int mid = l + ((r - l) >> 1);
		ll  temp = 0;
		for(i = 0;i < n;i++)
		{
			if(coin[i] > mid)
			{
				temp += coin[i] - mid;
			}
		}
		
		if(temp <= k)
		{
			r = mid;
		}
		else l = mid + 1;
	} 
}
int main()
{
	while(scanf("%lld %lld",&n,&k) == 2)
	{
		sum = 0;
		int i;
		for(i = 0;i < n;i++)
		{
			scanf("%lld",&coin[i]);
			sum += coin[i];
		}
		
		cout << get_max() - get_min() << endl;
	}
	return 0;
}
