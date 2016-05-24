/*
    写了两个并查集，结果都WA了，先水题签到防踢一下，TAT，继续调错
*/
#include<stdio.h>

long long t,n,m,i,ans;

int main()
{
	scanf("%lld",&t);
	for(i=1;i<=t;i++){
		scanf("%lld%lld",&n,&m);
		ans=m*m;
		ans=n/(2*m)*ans;
		//ans=n*m/2;
		printf("Case %lld: %lld\n",i,ans);
	}
	return 0;
}
