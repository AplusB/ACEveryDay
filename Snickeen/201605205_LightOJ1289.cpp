/*
    好不容易有了思路写了出来，结果MLE了
    然后就优化一下啊，换了个用数位标记筛出来素数的方法。由于后面进行素数的幂次统计的时候循环可能太多，TLE了。
    然后又重新MLE了几次，弱还不是很懂为啥又MLE了好几次。
    调啊调，WA一次，然后把后面的ans*ff[k]调到前面替换ans=1ll，然后终于AC了
    
    求LCM，统计素数的最高次幂，然后相乘。但是坑点略多啊~
*/
#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
using namespace std;
#define N 100000007
//const int N=100000007;  
typedef long long LL;

int pri[5800000],t,i,j,k,l,m;
int pr[N/32+10];
unsigned int ff[5800000];
LL ans,s,r,n;
LL MOD=(1LL<<32);

void getprime(){
    pri[++pri[0]]=2;
	for(i=3;i<N;i+=2){
		if(!(pr[i/32]&(1<<(i/2)%16))){
		    pri[++pri[0]]=i;
			for(j=i*3;j<N;j+=i*2)pr[j/32]|=(1<<(j/2)%16);
		}
	}
	ff[0]=1;
	for(i=1;i<=pri[0];i++)ff[i]=ff[i-1]*pri[i];
}

int bs(int ak,int L,int R){
	while(L<R){
		int M=L+(R-L+1)/2;
		if(pri[M]<=ak)L=M;
		else R=M-1;
	}
	return L;
}

void solve()
{
//	k=bs(n,1,pri[0]);
	k=upper_bound(pri,pri+pri[0]+1,n)-pri-1;
	ans=ff[k];
//	printf("%lld %u %u-\n",ans,ans,ff[k]);
	for(j=1;(pri[j]*pri[j]<=n)&&(j<=pri[0]);j++){
		r=(LL)(log10(n)/log10(pri[j]))-1;
		s=pow(pri[j],r+1);
		while(s<=(LL)n)r++,s=(LL)pow(pri[j],r+1);
		s=pow(pri[j],r-1);
		ans=ans*(s%MOD)%MOD;
	}
}

int main()
{
	getprime();
//	printf("%d %d %d\n",5800000*8,N/32+10,64*1024*1024);
//	printf("%d %lld--\n",pri[0],MOD);
    scanf("%d",&t);
    for(i=1;i<=t;i++){
    	scanf("%lld",&n);
    	solve();
    	printf("Case %d: %lld\n",i,ans);
	}
	
	return 0;
}
