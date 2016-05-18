#include<stdio.h>

int prime[111],ff[111][111],t,s,r,n,m,i,j,k,l;

int main()
{
//	freopen("myout.txt","w",stdout);
	for(i=2;i<=100;i++){
		if(!prime[i]){
			prime[++k]=i;
			for(j=i+i;j<=100;j+=i)prime[j]=1;
		}
	}
	for(i=2;i<=100;i++){
		t=i;
		for(j=1;j<=k;j++){
			if(t==1)break;
			while(t%prime[j]==0)ff[j][i]++,t/=prime[j];
		}
	}
	for(i=2;i<=100;i++){
		for(j=1;j<=k;j++){
			ff[j][i]+=ff[j][i-1];
			if(ff[j][i])ff[0][i]++;
		}
	}
	
//	for(i=1;i<=k;i++)printf("%2d ",prime[i]);puts("");
//	for(i=2;i<=100;i++){
//		for(j=1;j<=k;j++)printf("%2d ",ff[j][i]);puts("");
//	}
	
	
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d",&n);
		printf("Case %d: %d = 2 (%d)",i,n,ff[1][n]);
		m=ff[0][n]-1;
		for(j=2;j<=k;j++){
			if(!m)break;
			m--;
			printf(" * %d (%d)",prime[j],ff[j][n]);
		}
		puts("");
	}
	return 0;
}
