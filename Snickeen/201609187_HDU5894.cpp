#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long LL;

const LL N=2e6+10;
LL t,n,m,ans,cnt;
LL MOD=1e9+7;
LL f[N];

LL qp(LL a){
	LL b=MOD-2,res=1;
	while(b){
		if(b&1)res=res*a%MOD;
		b>>=1;
		a=a*a%MOD;
	}
	return res;
}

LL C(LL a,LL b){return f[a]*qp(f[b]*f[a-b]%MOD)%MOD;}

int main()
{
	LL i,j,k,l,ca=0;
	f[0]=1;for(i=1;i<N;i++)f[i]=f[i-1]*i%MOD;
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		if(m==1){cout<<n<<endl;continue;}
		LL u=n-m-m*k;
		if(u<0)ans=0;
		else ans=(C(n-k*m-1,m-1)*n%MOD*qp(m))%MOD;
		cout<<ans<<endl;
	}
	return 0;
}
