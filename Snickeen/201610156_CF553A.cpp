#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MAXN = 1e3+10;
LL t,n,m,ans,tot;
LL MOD=1e9+7;

LL f[MAXN],fac[MAXN];

LL qp(LL a){
	LL res=1LL,b=MOD-2LL;
	while(b){
		if(b&1)res=res*a%MOD;
		b>>=1;
		a=a*a%MOD;
	}
	return res;
}

int main()
{
	LL i,j,k,l,u,v;
	for(fac[0]=i=1;i<MAXN;i++)fac[i]=fac[i-1]*i%MOD;
	cin>>n;
	for(i=1;i<=n;i++)cin>>f[i];
	for(ans=i=1;i<=n;i++){
		tot+=f[i];
		u=tot-1LL;v=f[i]-1LL;
		ans=ans*fac[u]%MOD*qp(fac[v]*fac[u-v]%MOD)%MOD;
	}
	ans=(ans%MOD+MOD)%MOD;
	cout<<ans<<endl;
	return 0;
}
