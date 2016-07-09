#include<stdio.h>
int main()
{
    int t,ca=0;
    scanf("%d",&t);
    while(t--){
        int n,i,j,k,l,cnt=0,ans=0;
        scanf("%d",&n);
        while(n--){
            scanf("%d",&k);k-=2;
            if(k>cnt){ans+=(k-cnt+4)/5;cnt=k;}
        }
        printf("Case %d: %d\n",++ca,ans);
    }
    return 0;
}
