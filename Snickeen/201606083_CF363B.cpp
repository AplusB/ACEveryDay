#include<stdio.h>
int n,k,i,j,ans=0,s[150005];
int main(){
  scanf("%d%d",&n,&k);
  for(i=1;i<=n;i++) scanf("%d",&s[i]),s[i]+=s[i-1];
  for(j=0;j<=n-k;j++) if(s[ans+k]-s[ans]>s[j+k]-s[j]) ans=j;
  printf("%d\n",ans+1);
}
