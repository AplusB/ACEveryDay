#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T,a,b,c,d,i;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&b);
		c=d=1;
		for(i=2;i<=sqrt(a);i++) if(a%i==0) { c+=i; c+=a/i;}
		if(i*i==a) c+=i;
		for(i=2;i<=sqrt(b);i++) if(b%i==0) { d+=i; d+=b/i;}
		if(i*i==b) d+=i;
		if(c==b && a==d) printf("YES\n");
		else printf("NO\n");
	}	
	return 0;
}
