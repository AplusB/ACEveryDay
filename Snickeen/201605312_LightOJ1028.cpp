/*
    约数个数定理 
*/
#include<stdio.h>
using namespace std;
typedef long long LL;

LL n,m,i,j,k,l,t,s,r,mmax,mmin,num,ans;
LL ff[1000000+7];

int main(){
    
    for(i=2;i<=1000000;i++){
    	if(!ff[i]){
    		ff[t++]=i;
    		for(j=i+i;j<=1000000;j+=i)ff[j]=1;
		}
	}
    scanf("%lld",&n);int ca=0;
	while(n--){
		scanf("%lld",&m);ans=0;
		ans=1LL;
		for(i=0;i<t&&ff[i]*ff[i]<=m;i++){//注意 ff[i]*ff[i]<=m，否则会TLE 
			k=0;
			while(m%ff[i]==0)k+=1,m/=ff[i];
			ans*=(k+1);
		}
		if(m>1)ans*=2;
		printf("Case %d: %lld\n",++ca,ans-1);
	}
	return 0;
}
