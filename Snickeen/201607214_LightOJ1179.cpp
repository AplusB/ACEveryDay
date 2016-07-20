/*
    约瑟夫问题，用递推公式求解。 
*/
#include<stdio.h>
int t,ca=0,n,k,i,ans;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(ans=0,i=1;i<=n;i++){ans=(ans+k)%i;}
        printf("Case %d: %d\n",++ca,ans+1);
    }
    return 0;
}
