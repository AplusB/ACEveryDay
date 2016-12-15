#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
const int maxn=2000+2;
const int inf=2e9+9;
const ll mod=1e9+7;
const double eps=1e-9;


double a[maxn];

int main()
{
	int t;
	int cas=1;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		double sum=0;
		for(int i=1;i<=n;i++)
			scanf("%lf",&a[i]),sum+=a[i];
		printf("Case #%d: ",cas++);
		double ans=0;
		double pre=0;
		for(int i=1;i<n;i++)
		{
			pre+=a[i];
			double v1=1.0*pre/i;
			double v2=1.0*(sum-pre)/(n-i);
			double tmp=0;
			for(int j=1;j<=i;j++)
			{
				tmp+=(a[j]-v2)*(a[j]-v2);
			}
			for(int j=i+1;j<=n;j++)
			{
				tmp+=(a[j]-v1)*(a[j]-v1);
			}
			ans=max(ans,tmp);
		}
	
		printf("%.6f\n",ans);

		
	}
	return 0;
}
