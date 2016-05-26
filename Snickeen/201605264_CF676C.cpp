#include<bits/stdc++.h>
using namespace std;

int n,m,i,j,k,l,t,s,r,mmax,mmin,num,ans;
double dd[100005],ff[100005];
char aa[100005];

int main(){
    scanf("%d%d%s",&n,&m,(aa+1));
    ff[n+1]=dd[n+1]=1e7;k=m;
    for(i=1;i<=n;i++)ff[i]=ff[i-1]+(aa[i]=='a');
    for(i=1;i<=n;i++)dd[i]=dd[i-1]+(aa[i]=='b');
    for(i=j=1;i<=n;i++){
        for(;;j++)if(ff[j]-ff[i-1]>k)break;
        j--;ans=max(ans,j-i+1);
    }
    for(i=j=1;i<=n;i++){
        for(;;j++)if(dd[j]-dd[i-1]>k)break;
        j--;ans=max(ans,j-i+1);
    }
    printf("%d\n",ans);
    return 0;
}
