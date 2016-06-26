/*
    统计[m,n]各个数位上出现0的总个数
*/
#include<stdio.h>
typedef long long LL;
LL de[66],t,ca=0,n,m,ans;

LL get(LL x){
    LL i,j,k,res=0;
    if(x==0)return 1;
    while(x){
        res+=(x%10==0);
        x/=10;
    }
//    printf("%lld --",res);
    return res;
}

LL solve(LL x){
    LL i,j,k,l,res=0;
    for(i=1;de[i+1]<=x;i++){
        k=(x/de[i+1]-1)*de[i];
        j=x/de[i]%10;
        if(j==0)l=(x%de[i]+1);
        else l=de[i];
        res+=k+l;
//        printf("%lld --\n",res);
    }
    return res;
}

int main()
{
    de[0]=de[1]=1;
    for(t=2;t<12;t++)de[t]=de[t-1]*10;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld %lld",&m,&n);
        ans=solve(n)-solve(m)+get(m);
        printf("Case %lld: %lld\n",++ca,ans);
    }
    return 0;
}
