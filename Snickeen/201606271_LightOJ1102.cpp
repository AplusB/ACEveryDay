/*
    组合数：n个相同的小球放到m个不同的盒子里，盒子可以为空。 （n+m-1）选（m-1）的组合
    预处理阶乘，逆元。
    
    很弱智地把阶乘的逆元写成了下标的逆元，还好久没看出来 TAT:(~~o(>_<)o ~~) 
*/
#include<stdio.h>
typedef long long LL;

LL fac[2000005],t,ca=0,n,m,ans;
LL MOD=(LL)1e9+7;

LL qp(LL a){
    LL res=1,b=MOD-2;a%=MOD;
    while(b){
        if(b&1LL)res=res*a%MOD;
        b>>=1;
        a=a*a%MOD;
    }
    return res;
} 

int main()
{
    for(fac[0]=fac[1]=1LL,t=2;t<2000003;t++)fac[t]=fac[t-1]*t%MOD+MOD,fac[t]%=MOD;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&m);
//        n=n+m-1;m-=1;ans=fac[n]*qp(fac[m]*fac[n-m])%MOD;
        ans=fac[n+m-1]*qp(fac[m-1]*fac[n])%MOD;
        printf("Case %lld: %lld\n",++ca,(ans+MOD)%MOD);
    }
    return 0;
}
