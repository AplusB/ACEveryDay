/*
    水题签到防踢，赶车去膜QAQ
*/
#include<stdio.h>
typedef long long LL;

LL n,m,t,s,r,i,j,k,l,ans;

int main()
{
	scanf("%lld",&t);
	for(i=1;i<=t;i++){
		scanf("%lld",&n);
		//不是很懂 
		r=n&-n;
		s=n+r;
		ans=((n&~s)/r>>1)|s;
		printf("Case %lld: %lld\n",i,ans);
	}
	return 0;
}
