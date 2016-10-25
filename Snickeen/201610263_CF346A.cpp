/*
By Snickeen.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL t,n,m,ans,f[111];

int main()
{
	LL i,j,k,l;
	cin>>n;
	for(i=1;i<=n;i++)cin>>f[i],ans=__gcd(ans,f[i]),t=max(t,f[i]);
	for(i=1;i<=n;i++)m+=(f[i]%ans==0);
	ans=t/ans-m;
	cout<<(ans&1?"Alice":"Bob")<<endl;
	return 0;
}
