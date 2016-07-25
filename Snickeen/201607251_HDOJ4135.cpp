#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i,a,b) for(i=a;i<b;i++)
#define repu(i,a,b) for(i=a;i<=b;i++)
#define repc(i,a,b,c) for(i=a;i<b;i+=c)
#define repcu(i,a,b,c) for(i=a;i<=b;i+=c)
#define repd(i,a,b) for(i=a;i>=b;i--)

const LL N=100005;
LL f[10000];

LL pr[N/10],ans;
bitset<N> prime;

void getprime(){
	LL i,j,k,l;
	rep(i,2,N){
		if(!prime[i]){
			pr[++pr[0]]=i;
			repc(j,i+i,N,i){prime[j]=1;}
		}
	}
//	printf("%d\n",pr[0]);
}

LL check(LL x){
	LL i,j,k,l,res=0,cnt,tmp;
	rep(i,1,(1<<f[0])){
		cnt=0;tmp=1ll;
		repu(j,1,f[0]){
			if(i & (1<<j>>1)){
				tmp*=f[j];
				cnt++;
			}
		}
		tmp=x/tmp;
		(cnt&1)?res+=tmp:res-=tmp;
	}
//	printf("%I64d %I64d\n",res,x-res);
	return x-res;
}

void solve(LL a,LL b,LL n){
	LL i,j,k,l,x;
	
	f[0]=0;x=n;
	repu(i,1,pr[0]){
		if(x<pr[i])break;
		if(x%pr[i]==0){
			f[++f[0]]=pr[i];
			while(x%pr[i]==0)x/=pr[i];
		}
	}
	if(x>1)f[++f[0]]=x;
	
	LL ans1=check(a-1);
	LL ans2=check(b);
	ans=ans2-ans1;
}

int main()
{
	getprime();
	LL a,b,n;
	int t,ca=0;LL i,j,k,l;
	scanf("%d",&t);
	while(t--){
		scanf("%I64d%I64d%I64d",&a,&b,&n);
		solve(a,b,n);
		printf("Case #%d: %I64d\n",++ca,ans);
	}
	return 0;
}
