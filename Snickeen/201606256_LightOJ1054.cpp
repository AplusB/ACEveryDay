/*
    201606256 LightOJ 1054
	 
    题意：求n的m次幂的约数和
	
    题解：n的所有素因子和n^m的所有素因子一样，所以枚举素因子，然后计算个数，运用约数和公式即可。
            约数和是素因子个等比数列和的连乘积，
                      k
                    ——————     pri[j]^(a[j]+1)-1
            sum =    |  |   ----------------------- 
                     |  |          pri[j]-1
                     j=1
            
            n=prime1^a1+prime2^a2+......+primej^aj ， 当然这里a[j]=aj*m 。
    
    注意：这里筛不筛素数都行，筛素数0.060ms，不筛素数0.240ms
	
    重点重点重点：注意对结果的取模不能出现负值，需要及时用 ans=(ans+MOD)%MOD;确保答案为正值。
	 
*/
#include<stdio.h>
#include<bitset>
using namespace std;
typedef long long LL;

LL t,ca=0,n,m,s,r,ans,cnt=0;
LL MOD=1e9+7,moll=1e9+7;
LL pri[100005];
bitset<1000007> prime;

LL qp(LL a,LL b){
    LL res=1LL;a=(a+MOD)%MOD;
    while(b){
        if(b&1)res=res*a%MOD;
        b/=2;
        a=a*a%MOD;
    }
    return res;
}
    
LL get(LL a,LL b){
    LL res;
    res=qp(a,b)-1;
    res=res*qp(a-1,MOD-2)%MOD;
    res=(res+MOD)%MOD; 
    return res; 
}

int main()
{
    LL i,j,k,l;
    
    for(i=2;i<=1000005;i++){
        if(!prime[i]){
            pri[++pri[0]]=i;
            for(j=i+i;j<=1000005;j+=i)prime[j]=1;
        }
    }
    
    scanf("%lld",&t);
    while(t--){
        scanf("%lld %lld",&n,&m);ans=1;
        
        for(i=1;i<=pri[0]&&pri[i]*pri[i]<=n;i++){
            if(n%pri[i]==0){
                cnt=0;
                while(n%pri[i]==0&&n)n/=pri[i],cnt++;
                ans=ans*(qp(pri[i],cnt*m+1LL)-1)%MOD*qp(pri[i]-1,MOD-2)%MOD;ans=(ans+MOD)%MOD;
//                ans=ans*get(pri[i],cnt*m+1LL)%MOD;ans=(ans+MOD)%MOD;
            }
        }
        
        /***********************************///不筛素数 
        /*
        for(i=2;i*i<=n;i++){
            if(n%i==0){
                cnt=0;
                while(n%i==0&&n)n/=i,cnt++;
                ans=ans*(qp(i,cnt*m+1LL)-1)%MOD*qp(i-1,MOD-2)%MOD;ans=(ans+MOD)%MOD;
            }
        }
        */
        /**********************************/
        
        if(n>1){
//            ans=ans*get(n,m+1LL)%MOD;ans=(ans+MOD)%MOD;
            ans=ans*((qp(n,m+1LL)-1)%MOD*qp(n-1,MOD-2)%MOD+MOD)%MOD;ans=(ans+MOD)%MOD;
        }
        printf("Case %lld: %lld\n",++ca,ans);
    }
    return 0;
}
