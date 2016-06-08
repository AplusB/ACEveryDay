# include <cstdio>
# include <iostream>
# include <algorithm>
# include <cmath>
using namespace std;
typedef long long LL;
int main(void)
{
    LL n,a,b,c,d; cin>>n>>a>>b>>c>>d;
    LL ans=abs(b-c)+abs(a-d);
	cout<<max((LL)0,(LL)(n*(n-ans)))<<endl;
	return 0;
}
