//Educational Codeforces Round 13
//A - Johny Likes Numbers
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	cout<<(n/k+1)*k<<endl;
	return 0;
}
//B - The Same Calendar
#include <bits/stdc++.h>
using namespace std;
bool ok(int n){
	if(n%400==0||(n%4==0&& n%100))return 1;
	return 0;
}
int main()
{
	int n,k;
	cin>>n;
	int now=0;
	bool flag=ok(n);
	while(n++){
		if(ok(n)) now+=366;
		else now+=365;
		if(now%7==0&&ok(n)==flag) break;
	}
	cout<<n<<endl;
	return 0;
}
//C - Joty and Chocolate
#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL lcm(LL a,LL b){
	return a/__gcd(a,b)*b;
}
int main()
{
	LL n,a,b,q,p;
	cin>>n>>a>>b>>p>>q;
	if(p>q) cout<<n/a*p-n/lcm(a,b)*q+n/b*q<<endl;
	else cout<<n/a*p-n/lcm(a,b)*p+n/b*q<<endl;
	return 0;
}
//E - Another Sith Tournament
#include <bits/stdc++.h>
using namespace std;
#define LL long long
double mp[20][20],dp[(1<<19)][20];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>mp[i][j];
	dp[1][0]=1;
	for(int i=3;i<(1<<n);i+=2)
		for(int j=1;j<n;j++)
			if(i&(1<<j))
				for(int k=0;k<n;k++)
					if(k!=j && i&(1<<k)) dp[i][j]=max(dp[i][j],dp[i^(1<<k)][j]*mp[j][k]+dp[i^(1<<j)][k]*mp[k][j]);
	double ans=0;
	for(int i=0;i<n;i++) ans=max(ans,dp[(1<<n)-1][i]);
	printf("%.10lf\n",ans);
	return 0;
}
