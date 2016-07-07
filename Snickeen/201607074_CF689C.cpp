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
template<typename T>inline void gt(T x){
    if(!x)return;
    gt(x/10);putchar(x%10+'0');
}

const LL N=100011;
struct TT{
    int a,b;
};TT tt[5],ss,rr;
LL n,m,t,s,r,l,mmax,mmin,num,ans;
LL MOD=1e9+7,mod;
LL ff[N];

inline LL get(LL x){return 1ll*x*x*x;}

LL check(LL x){
    LL i,j,k,res=0;
    for(i=2;;i++){
        j=get(i);
        if(j>x)break;
        res+=x/j;
    }
    return res;
}

int main(){
    //FIN;FOUT;
    LL i,j,k;
    gn(m);
    LL L=1,R=(1ll<<63)-1ll;
    while(L<R){
        LL mid=L+(R-L)/2;
        if(check(mid)>=m)R=mid;
        else L=mid+1;
    }
    if(check(L)==m)printf("%I64d\n",L);
    else puts("-1");
    return 0;
}
