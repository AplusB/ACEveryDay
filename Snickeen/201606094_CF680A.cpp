/*
    水题签到防踢，如果还能绝杀成功就换一个
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define rep(i,a,b) for(i=a;i<b;i++)
#define repu(i,a,b) for(i=a;i<=b;i++)
#define repd(i,a,b) for(i=a;i>=b;i--)
#define db double
#define ld long double
#define FIN  freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)
#define CC(a) memset(a,0,sizeof(a))

template<typename T>inline void gn(T &x){
	x=0;T f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}

struct TT{
	int a,b;
};TT tt[11];
int n,m,i,j,k,l,t,s,r,mmax,mmin,num,ans;
LL MOD=1e9+7;
char aa[11];
int ff[11];

int main(){
//	FIN;FOUT;
    repu(i,1,5)gn(ff[i]),num+=ff[i];int ca=0;
    sort(ff+1,ff+6);ans=num;
    repu(i,1,4)if(ff[i]==ff[i+1])ans=min(ans,num-ff[i]-ff[i+1]);
    repu(i,1,3)if(ff[i]==ff[i+2])ans=min(ans,num-ff[i]-ff[i+1]-ff[i+2]);
    printf("%d\n",ans);
	return 0;
}
