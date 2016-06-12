/*
    NCPC2010的D题
    
    dd数组没用
*/

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<iomanip>
#include<algorithm> 
#include<stdlib.h>
#include<math.h> 
#include<queue>
#include<stack>
#include<map>
using namespace std;
typedef long long LL;

LL n,m,i,j,k,l,t,s,r,mmax,mmin,num,ans;
LL MOD=1e9+7;
char aa[11];
LL ff[100005],dd[100005];

int main(){
    LL p;
    scanf("%lld%lld",&n,&p);
    for(i=0;i<n;i++)scanf("%lld",&ff[i]);
    sort(ff,ff+n);
    for(i=0;i<n;i++)dd[i]=dd[i-1]+ff[i];
    ans=0;
    for(i=n-1;i>=0;i--){
    	m=i+1;
    	t=p*m;
    	ans=max(ans,max(0LL,t-ff[i]));
	}
	printf("%lld\n",ans+ff[0]);
	return 0;
}


