/*
    题意：给你n和t，n!在b进制下末尾0的个数要大于等于t，求最大的b
    思路：筛n之内的素数，然后依次看在素数p进制下0的个数k，
            如果大于t，快速幂优化p^(k/t)，然后作连乘积 
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL t,ca=0,n,m,s,r;
LL pr[10011],MOD=10000019;
bitset<111111> prime;

void getprime(){
    LL i,j,k,l;
    for(i=2;i<100011;i++){
        if(!prime[i]){
            pr[++pr[0]]=i;
            for(j=i+i;j<100011;j+=i)prime[j]=i;
        }
    }
    //printf("%lld\n",pr[0]);
}

LL get(LL x){
    LL i,j,k=x,res=0;
    while(x<=n){
        res+=n/x;
        x*=k;
    }
    return res;
}

LL qp(LL a,LL b){
    LL res=1,x=a;
    while(b){
        if(b&1)res=res*x%MOD;
        b/=2;
        x=x*x%MOD;
    }
    return res;
}

int main()
{
    LL i,j,k,l;
    getprime();
    scanf("%lld",&t);
    while(t--){
        scanf("%lld %lld",&n,&m);LL ans=1;
        for(i=1;i<=pr[0];i++){
            k=get(pr[i]);
            if(k<m)break;
            ans=ans*qp(pr[i],k/m)%MOD;
        }
        if(ans==1)ans=-1;
        printf("Case %lld: %lld\n",++ca,ans);
    }
    return 0;
}
