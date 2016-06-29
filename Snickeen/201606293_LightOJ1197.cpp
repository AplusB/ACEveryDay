/*
    求[n,m]区间的素数个数。模拟埃拉托色尼筛法。
    
    注意：一开始用的int结果RE了，改成LL后WA；
            原来是当n==1时，要令n=1；（坑点姿势 
*/
#include<stdio.h>
#include<string.h>
long long pri[100005],t,ca=0,n,m,x;
char prime[1000005],ans[100005];
int main()
{
    long long i,j,k,l,res;prime[0]=prime[1]=1;
    for(i=2;i<1000003;i++){
        if(!prime[i]){
            pri[++pri[0]]=i; 
            for(j=i+i;j<1000003;j+=i)prime[j]=1;
        }
    }
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&m);
        if(n<2)n=2;
        res=m-n+1;memset(ans,false,sizeof(ans));
        for(i=1ll;(i<=pri[0])&&(pri[i]*pri[i]<=m);i++){
            k=n%pri[i];if(k==0)k=pri[i];
            for(j=n+pri[i]-k;j<=m;j+=pri[i]){
                if((!ans[j-n])&&(j>pri[i]))ans[j-n]=1,res-=1ll;
            }
        }
        printf("Case %lld: %lld\n",++ca,res);
    }
    return 0;
}
