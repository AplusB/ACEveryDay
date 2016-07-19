#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;

LL MOD=998244353;
LL t,n,m,ans;
LL ff[100005],a[100005],b[100005];

int main()
{
    LL i,j,k,l;
    scanf("%I64d",&t);
    while(t--){
        scanf("%I64d",&n);
        for(i=1;i<=n;i++)scanf("%I64d",&a[i]);
        for(i=1;i<=n;i++)scanf("%I64d",&b[i]);
        if(a[1]!=b[1]){puts("0");continue;}
        ff[1]=1LL;
        for(i=2;i<=n;i++){
            if(a[i]==a[i-1]&&b[i]>b[i-1])ff[i]=ff[i-1];
            else if(a[i]<a[i-1]&&b[i]==b[i-1])ff[i]=ff[i-1];
            else if(a[i]==a[i-1]&&b[i]==b[i-1]&&b[i]-a[i]+1>=i)ff[i]=ff[i-1]*(b[i]-a[i]+1-(i-1))%MOD;
            else {ff[n]=0;break;}
        }
        printf("%I64d\n",ff[n]);
    }
    return 0;
}
