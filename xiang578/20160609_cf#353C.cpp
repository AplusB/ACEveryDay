#include<bits/stdc++.h>
using namespace std;
long long a[100000+10];
map<long long ,long long>mp;
int main() {
	int _;
	long long n,t,s,ans;
	scanf("%lld",&n);
	s=0;
	ans=n-1;
	mp.clear();
	for(int i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
		s+=a[i];
		mp[s]++;
		ans=min(ans,n-mp[s]);
	}
	printf("%lld\n",ans);
	return 0;
}
