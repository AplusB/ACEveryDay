//A+B签到
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T,a,b,c,d;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&b);
		c=d=0;
		for(int i=1;i<=a/2;i++) if(a%i==0) c+=i;
		for(int i=1;i<=b/2;i++) if(b%i==0) d+=i;
		if(c==b && a==d) printf("YES\n");
		else printf("NO\n");
	}	
	return 0;
}
