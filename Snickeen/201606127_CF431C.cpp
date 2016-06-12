/*
    简单递推或者简单DP
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i,a,b) for(i=a;i<b;i++)
#define repu(i,a,b) for(i=a;i<=b;i++)
#define repd(i,a,b) for(i=a;i>=b;i--)

template<typename T>inline void gn(T &x){
	x=0;T f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}

LL n,m,i,j,k,l,t,s,r,mmax,mmin,num,ans;
LL MOD=1e9+7;
LL wis[111],ff[111];

int main(){
	gn(n);gn(k);gn(m);
    wis[0]=1LL;
    ff[0]=0LL;
    repu(i,1,n){
    	t=min(i,k);
    	repu(j,1,t){
    		if(j>=m)ff[i]+=wis[i-j];
    		else wis[i]+=wis[i-j];
			ff[i]+=ff[i-j];
    		ff[i]%=MOD;wis[i]%=MOD;
		}
	}
    printf("%I64d\n",ff[n]);
	return 0;
}
