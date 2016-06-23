#include<stdio.h>
#include<algorithm>
using namespace std;

int ff[111],t,n,m,ca=0,i,j,k,l;

int main()
{
	scanf("%d",&t);
	while(t--){
		
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++)scanf("%d",&ff[i]);
		while(m--){
			char a;getchar();
			scanf("%c",&a);
//			printf("%c--\n",a);
			if(a=='S'){
				scanf("%d",&k);
				for(j=0;j<n;j++)ff[j]+=k;
			}
			else if(a=='M'){
				scanf("%d",&k);
				for(j=0;j<n;j++)ff[j]*=k;
			}
			else if(a=='D'){
				scanf("%d",&k);
				for(j=0;j<n;j++)ff[j]/=k;
			}
			else if(a=='R'){
				for(j=0;j<n/2;j++){
					swap(ff[j],ff[n-j-1]);
				}
			}
			else if(a=='P'){
				scanf("%d%d",&j,&k);
				swap(ff[j],ff[k]);
			}
		}
		
		printf("Case %d:\n",++ca);
		printf("%d",ff[0]);
		for(i=1;i<n;i++)printf(" %d",ff[i]);
		puts("");
	}
	
	return 0;
}
