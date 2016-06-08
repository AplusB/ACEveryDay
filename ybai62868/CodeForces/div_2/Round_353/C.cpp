# include <cstdio>
# include <iostream>
# include <algorithm>
# include <map>
using namespace std;
typedef long long LL;
map<LL,int>mp;
int main(void)
{
	int n; cin>>n;
	LL res = n-1;
	LL sum = 0;
	for ( int i = 1;i <= n;i++ ){
		LL x; cin>>x;
		sum+=x;
		mp[sum]++;
		LL tmp = n-mp[sum];
		res = min(res,tmp);
	}
	cout<<res<<endl;
	return 0;
}
