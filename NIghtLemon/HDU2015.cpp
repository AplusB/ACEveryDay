#include<bits/stdc++.h>
using namespace std;
int n,m,ans;

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF){
		ans = m+1;
		printf("%d",ans);
		while(n>=m){
			ans+=2*m;
			n-=m;
			if(n>=m)
			printf(" %d",ans);
		}
		if(n){
			printf(" %d",ans-(m-n));
		}
		printf("\n");
	}
	
}
