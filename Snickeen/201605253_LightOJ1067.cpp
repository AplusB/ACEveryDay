/*
    组合数，预处理阶乘，然后用下逆元
*/
#include<stdio.h>
typedef long long LL;

LL ff[1000005],t,s,r,n,m,i,j,k,ans;
LL mod=1000003;

LL qp(LL a){
	LL f=1,b=mod-2;
	while(b){
		if(b&1)f=f*a%mod;
		b/=2;
		a=a*a%mod;
	}
	return f;
}

int main()
{
	for(i=ff[0]=1LL;i<=1000003;i++)ff[i]=(ff[i-1]*i%mod);
	scanf("%lld",&t);
	for(i=1;i<=t;i++){
		scanf("%lld%lld",&n,&m);
		ans=ff[n]*qp(ff[m])%mod*qp(ff[n-m])%mod;
		printf("Case %lld: %lld\n",i,ans);
	}
	return 0;
}
