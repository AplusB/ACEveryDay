/*
    题意：给定k和p，求所有的Almost-K-First-P-Prime的数的欧拉函数值的和,
        Almost-K-First-P-Prime是指一个数x, 有k个素因子, 恰好包含素数表前p个素数
    思路：欧拉函数+dp 
        首先预处理前p个素数乘积的欧拉函数；预处理素数prime[]; 
        k-p后剩下的素数对应前p个素数。dp[i,j]表示有i个空位对应前j个素数，dp[i][j]=dp[i][j-1]+dp[i-1][j]*prime[j];
    思路二：欧拉函数+dp， 
        令dp[i][j]表示包含i个素数, 最大的素数是第j个素数时,满足情况的数的欧拉函数值 
        dp[i][j] += dp[i-1][j-1] * (prime[j]-1) , 此时dp[i][j]只有一个素数j 
        dp[i][j] += dp[i-1][j] * prime[j], 此时dp[i][j]有多个素数j  
*/
#include<stdio.h>
#include<bitset>
using namespace std;
typedef long long LL;

LL t,ca=0,n,m,MOD=1e9+7;
LL pr[555],dp[555][555],f[555];
bitset<5555> prime;
void getprime(){
    LL i,j,N=4000;
    for(i=2;i<N;i++){
        if(!prime[i])pr[++pr[0]]=i;
        for(j=1;j<=pr[0]&&pr[j]*i<=N;j++){
            prime[i*pr[j]]=1;
            if(i%pr[j]==0)break;
        }
    }
    //printf("%lld\n",pr[0]);
}

void pre(){
    LL i,j,k,l,res;
    f[0]=1;
    for(i=1;i<=500;i++){
        f[i]=f[i-1]*(pr[i]-1)%MOD;
        dp[0][i]=1;
    }
    for(i=1;i<=500;i++){
        for(j=1;j<=500;j++){
            dp[i][j]=(dp[i][j-1]+dp[i-1][j]*pr[j]%MOD)%MOD;
        }
    }
    
}

int main()
{
    getprime();pre();
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&m);
        printf("Case %lld: %lld\n",++ca,dp[n-m][m]*f[m]%MOD);
    }
    return 0;
}
