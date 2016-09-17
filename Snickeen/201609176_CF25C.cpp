#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL t,n,m,p[303][303],ans,u,v,w;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	LL i,j,k,l,tmp;
	cin>>n;
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)cin>>p[i][j];
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			for(k=1;k<=n;k++){
				p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
			}
			ans+=p[i][j];
		}
	}
//	cout<<ans<<endl;
	cin>>m;
	while(m--){
		cin>>u>>v>>w;ans=0;
		for(i=1;i<=n;i++)for(j=1;j<=n;j++){
			p[i][j]=min(p[i][j],min(p[i][u]+w+p[v][j],p[i][v]+w+p[u][j]));
			ans+=p[i][j];
		}
		cout<<ans/2<<" ";
	}
	return 0;
}
