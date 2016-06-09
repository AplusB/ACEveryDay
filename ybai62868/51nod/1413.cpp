# include <cstdio>
# include <iostream>
# include <cmath>
# include <algorithm>
using namespace std;
typedef long long LL;
int main(void)
{
	int n; cin>>n;
	int res = 0;
	while ( n ){
		res = max(res,n%10);
		n/=10;
	}
	cout<<res<<endl;
	return 0;
}
