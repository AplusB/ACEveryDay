#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,c,d,i;
int main(){
    scanf("%d%d %d%d%d%d",&n,&m,&a,&b,&c,&d);
    if(n==4||m<n+1)return 0*puts("-1");
    printf("%d %d ",a,c);
    for(i=1;i<=n;i++)if(i!=a&&i!=b&&i!=c&&i!=d)printf("%d ",i);
    printf("%d %d\n",d,b);
    
    printf("%d %d ",c,a);
    for(i=n;i;i--)if(i!=a&&i!=b&&i!=c&&i!=d)printf("%d ",i);
    printf("%d %d\n",b,d);
    
	return 0;
}
