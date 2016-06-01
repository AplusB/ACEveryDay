/*
    这题学习到了分段打表，数据范围太大，合理打表，降低复杂度到O(39)，学习学习：D
*/

#include<stdio.h>
 
const int MAXN=1e8+10;
double ff[MAXN/40+44],a,b,ans;
int t,i,n,m,j,k;
 
int main()
{
    for(i=k=1;i<=MAXN;i++){
        a+=(1.0/i);
        if(i%40==0)ff[k++]=a;
    }
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d",&n);
        ans=ff[n/40];
        for(j=n/40*40+1;j<=n;j++){
            ans+=1.0/j;
        }
        printf("Case %d: %.12lf\n",i,ans);
    }
    return 0;
}
