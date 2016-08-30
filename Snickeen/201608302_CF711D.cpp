#include<bits/stdc++.h>
//#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
typedef long long LL;
#define repu(i,a,b) for(i=a;i<=b;i++)

const LL N=200003;

LL t,n,m,ans,cnt,flag;
LL MOD=1e9+7,inf=0x1f1f1f1f;
LL f[N],x,y,v[N],vis[N];

LL qp(LL a,LL b){
	LL res=1;
	while(b){
		if(b&1)res=res*a%MOD;
		b>>=1;
		a=a*a%MOD;
	}
	return res;
}

void dfs(LL node,LL sum,LL num){
	LL i,j,k=0;
	if(vis[node]){
		if(v[node]==num){
			x=sum-vis[node];y=vis[node]-1;
		}
		else {
			x=0;y=sum-1;
		}
		return ;
	}
	v[node]=num;
	vis[node]=sum;
	dfs(f[node],vis[node]+1,num);
}

int main()
{
// 	ios_base::sync_with_stdio(false);cin.tie(0);
	LL i,j,k,l,ca=0;
	cin>>n;
	repu(i,1,n){
		cin>>f[i];
	}
	for(i=1;i<=n;i++){
		if(!vis[i]){
			v[i]=++cnt;vis[i]=1;
			dfs(f[i],vis[i]+1,cnt);
			if(!flag){
				ans=(qp(2,x)-2)*qp(2,y)%MOD;
				flag=1;
			}
			else {
				if(x)ans=ans*(qp(2,x)-2)%MOD;
				ans=ans*qp(2,y)%MOD;
			}
		}
	}
	ans=(ans%MOD+MOD)%MOD;
	cout<<ans<<endl;
	return 0;
}
