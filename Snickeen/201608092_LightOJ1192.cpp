#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int ff[222],ans,n,a,b;
int main()
{
	int t,ca=0,i,j,k,l;
	scanf("%d",&t);
	while(t--){
		ans=0;memset(ff,0,sizeof(ff));
		scanf("%d",&n);
		for(i=1;i<=2*n;i+=2)scanf("%d%d",&ff[i],&ff[i+1]);
		sort(ff+1,ff+n+1);
		for(i=1;i<=2*n;i+=2)ans^=(ff[i+1]-ff[i]-1);
		printf("Case %d: ",++ca);
		puts(ans?"Alice":"Bob");
	}
	return 0;
}
