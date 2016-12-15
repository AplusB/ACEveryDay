#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;
const int maxn=2e5+200;
const double eps=1e-9;

int num[maxn];
map<int,int> aha;

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		ll ans=0;
		aha.clear();
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&num[i]);
			aha[num[i]]=i;
		}
		int pos=aha[1];
		while(1)
		{
			int nx=num[pos]+1;
			if(nx>n) break;
			ans+=(ll)abs((pos-aha[nx]));
			pos=aha[nx];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
