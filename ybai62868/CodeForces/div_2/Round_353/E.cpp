# include <cstdio>
# include <iostream>
# include <map>
# include <algorithm>
using namespace std;
# define MAX 100004
typedef long long LL;
LL dp[MAX];
int Prev[MAX],x[MAX];
int main(void)
{
	int u,pos=0;
	int n; cin>>n;
	for( int i = 1;i <= n-1;i++ ) cin>>x[i];
	Prev[++pos]= -n;
	dp[n]= 0;
	LL ret=0;
	for( int i = n-1;i >= 1;i--) 
	{
		u = lower_bound(Prev+1,Prev+1+pos,-x[i])-Prev;
		u = -Prev[u];
		dp[i]= dp[u]-(x[i]-u)+ n-i;
		//cout<<dp[i]<<endl;
		ret+=dp[i];
		while( pos>0 && x[-Prev[pos]]<=x[i]) --pos;
		Prev[++pos]= -i;
	}
	cout<<ret<<endl;
}
