#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL maxn=1e5+10;
LL t,n,m,ans[maxn];
LL f[maxn],op[maxn];
LL pa[maxn],sum[maxn],vis[maxn];

LL find(LL x){return x==pa[x]?x:pa[x]=find(pa[x]);}

int main()
{
	LL i,j,k,u,v;
	cin>>n;
	for(i=1;i<=n;i++)cin>>f[i],pa[i]=i;
	for(i=1;i<=n;i++)cin>>op[i];
	ans[n]=0;
	for(i=n;i>1;i--){
		LL x=op[i];
		sum[x]+=f[x];vis[x]=1;
		if(vis[x-1]){
			k=find(x-1);
			pa[k]=x;
			sum[x]+=sum[k];
		}
		if(vis[x+1]){
			k=find(x+1);
			pa[k]=x;
			sum[x]+=sum[k];
		}
		ans[i-1]=max(sum[x],ans[i]);
	}
	for(i=1;i<=n;i++)cout<<ans[i]<<endl;
	return 0;
}
