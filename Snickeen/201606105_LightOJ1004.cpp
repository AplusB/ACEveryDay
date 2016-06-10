#include<stdio.h>
#include<string.h>
typedef long long LL;
 
LL ff[333][111],t,n,m,i,j,k;
 
LL max(LL a,LL b){
    if(a>b)return a;
    return b;
}
 
int main()
{
    scanf("%lld",&t);int cas=0;
    while(t--){
        scanf("%lld",&n);
        memset(ff,0,sizeof(ff));
        for(i=1;i<=n;i++){
            for(j=1;j<=i;j++)scanf("%lld",&ff[i][j]);
        }
        for(i=n+1,k=n-1;k;k--,i++){
            for(j=1;j<=k;j++)scanf("%lld",&ff[i][j]);
        }
        for(i=2;i<=n;i++){
            for(j=1;j<=i;j++)ff[i][j]+=max(ff[i-1][j-1],ff[i-1][j]);
        }
        for(i=n+1,k=n-1;k;k--,i++){
            for(j=1;j<=k;j++)ff[i][j]+=max(ff[i-1][j],ff[i-1][j+1]);
        }
        printf("Case %d: %lld\n",++cas,ff[2*n-1][1]);
    }
   
    return 0;
}
