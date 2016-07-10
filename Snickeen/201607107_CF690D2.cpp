#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef double db;
typedef long double ldb;
#define rep(i,a,b) for(i=a;i<b;i++)
#define repu(i,a,b) for(i=a;i<=b;i++)
#define repd(i,a,b) for(i=a;i>=b;i--)
#define FIN freopen("input.in","r",stdin)
#define FOUT freopen("output.out","w",stdout)
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

LL t,n,m,i,j,k,ans;
LL MOD=1e6+3;
LL fac[700007];

LL qpm(LL a){
    a%=MOD;
    LL b=MOD-2,res=1LL;
    while(b){
        if(b&1LL)res=res*a%MOD;
        b/=2;
        a=a*a%MOD;
    }
    return res;
}

LL C(LL a,LL b){
    LL res=fac[a]*qpm(fac[b]*fac[a-b]%MOD)%MOD;
    return (res+MOD)%MOD;
}

int main()
{
    //FIN;FOUT;
    fac[0]=1LL;
    rep(i,1,700003){
        fac[i]=fac[i-1]*i%MOD;
    }
    gn(n);gn(m);
    repu(i,1,n){
        k=C(i+m-1,m-1);
        ans+=k;
        ans%=MOD;
        //printf("%I64d %I64d \n",i,k);
    }
    printf("%I64d\n",ans);
    
    return 0;
}
