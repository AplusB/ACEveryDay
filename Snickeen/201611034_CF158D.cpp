/*
By Snickeen.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MAXN = 20010;
LL t,n,m,ans=-0x3f3f3f3f3f3f3f3f;
LL f[MAXN],v[MAXN];

void check(LL x){
	LL i,j,k,l;
	for(i=0;i<=x;i++)v[i]=0;
	for(i=1;i<=n;i++)v[i%x]+=f[i];
	for(i=0;i<x;i++)ans=max(ans,v[i]);
}

int main()
{
	LL i,j,k,l;
	cin>>n;
	for(i=1;i<=n;i++)cin>>f[i];
	for(i=1;i*i<=n;i++){
		if(n%i)continue;
		if(n/i>=3)check(i);
		if(i>=3)check(n/i);
	}
	cout<<ans<<endl;
	return 0;
}
