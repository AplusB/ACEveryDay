/*
    
*/
#include<stdio.h>
int f(int x){return x/3*2+(x%3==2?1:0);}
int main()
{
    int t,ca=0,n,m,ans;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        printf("Case %d: %d\n",++ca,f(m)-f(n-1));
    }
    return 0;
}
