#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
using namespace std;
typedef long long ll;
map<ll,int> mp;
int main()
{
	int n;
	scanf("%d",&n);
	ll sum=0;
	int ans=n-1,x;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		sum+=x;
		mp[sum]++;
		ans=min(ans,n-mp[sum]);
	}
	printf("%d\n",ans);
}
