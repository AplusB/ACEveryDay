//hdoj1789
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const double eps=1e-5;
const double pi=acos(-1.0);
const int mod=1e9+7;
const int INF=0x3f3f3f3f;

const int N=1e3+10;

struct asd{
	int d;
	int t;
};
asd q[N];
bool vis[N];
bool cmp(asd x,asd y)
{
	if(x.t>y.t)
		return 1;
	else if(x.t==y.t){
		if(x.d<y.d)
			return 1;
	}
	return 0;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,i,sum,j;
		cin>>n;
		for(i=1;i<=n;i++){
			scanf("%d",&q[i].d);
		}
		for(i=1;i<=n;i++){
			scanf("%d",&q[i].t);
		}
		sort(q+1,q+n+1,cmp);
		memset(vis,0,sizeof(vis));
		
		sum=0;
		for(i=1;i<=n;i++){
			for(j=q[i].d;j>=1;j--){
				if(!vis[j]){
					vis[j]=1;
					break;
				}
			}
			if(j==0)
				sum+=q[i].t;
		}
		cout<<sum<<endl;
	}
	return 0;
}
