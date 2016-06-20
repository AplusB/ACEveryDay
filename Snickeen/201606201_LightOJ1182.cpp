#include<stdio.h>

int main()
{
	int t,ca=0,n,ans=0;
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d",&n);
		while(n){
			ans+=(n&1);
			n/=2;
		}
		printf("Case %d: %s\n",++ca,((ans&1)?"odd":"even"));
	}
	
	return 0;
}
