#include<stdio.h>
int main()
{
	long long t,ca=0,n,m;
	scanf("%lld",&t);
	while(t--){
		m=1;printf("Case %lld: ",++ca);
		scanf("%lld",&n);
		while(n%2==0){
			n/=2;
			m*=2;
		}
		if(m==1)puts("Impossible");
		else printf("%lld %lld\n",n,m);
	}
	return 0;
}
