/*
    LightOJ1215
    关键地方在求符合lcm(m,c)==L的最小c。
    一开始不是很懂，感谢各位巨巨的指点。
    
    难理解的地方详见注释。
*/
#include<stdio.h>
typedef long long LL;

LL n,m,t,s,r,i,j,k,l;

LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}

int main()
{
    scanf("%lld",&t);
    for(i=1;i<=t;i++){
        printf("Case %lld: ",i);
        scanf("%lld %lld %lld",&n,&m,&l);
        k=n/gcd(n,m)*m;
        if(k>l||l%k)puts("impossible");//判断k>l容易被忽略 
        else {
            r=l/k;//r中包含了 l中不在m中的素因子 和 l中的指数大于在m中的素因子的指数差
            while((j=gcd(r,k))!=1){// c中已经有了l中指数大的因子 m中也有
                r*=j;k/=j;   //不断gcd就是把m中的次数乘到c上
            }
            printf("%lld\n",r);
        }
    }
    return 0;
}
