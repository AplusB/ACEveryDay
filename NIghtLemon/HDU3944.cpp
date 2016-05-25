#include<bits/stdc++.h>
const int N = 10007;

int n,m,p;
int prime[1300];
int prilo[N];
int c[13000][N];
int inv[1300][N];
int isNotPrime[N] = {1, 1};
using namespace std;

void init()
{
	int tot = 0;
	for(int i = 2 ; i < N ; i ++)		 
	{			  
		if(!isNotPrime[i]){
			prilo[i] = tot;
			prime[tot++]=i;
		}
		for(int j = 0 ; j < tot && i * prime[j] <  N ; j ++)  
		{				 
			isNotPrime[i * prime[j]] = 1;	
			if(!(i % prime[j] ) )				 
			break;			 
		}	  
	}
	for(int i=0;i<tot;i++){
		int MOD = prime[i];
		inv[i][1] = 1;
		c[i][0] = c[i][1] = 1;
		for(int j=2 ; j <= N ; j++) {
			c[i][j] = (c[i][j-1] * j) % MOD;
			inv[i][j] = ((MOD - MOD / j) * inv[i][MOD % j]) % MOD;
		}
	}
}

int C(int n,int m){
	if(m>n) return 0;
	if(m==n) return 1;
	int k = prilo[p];
	return c[k][n]*(inv[k][c[k][n-m]]*inv[k][c[k][m]]%p)%p;
}

int Lucas(int n,int m){
	if(m==0) return 1;
	return (C(n%p,m%p)*Lucas(n/p,m/p))%p;
}

int main()
{
	init();
	int NT = 0;
	while(scanf("%d%d%d",&n,&m,&p)!=EOF){
		if(m<=n/2) m=n-m;  
        printf("Case #%d: %d\n",++NT,(m%p+Lucas(n+1,m+1)%p)%p);  
	}
	
	return 0;
}
