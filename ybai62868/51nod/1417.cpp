# include <cstdio>
# include <iostream>
# include <cmath>
# include <algorithm>
using namespace std;
typedef long long LL;
LL gcd ( LL a, LL b ){
	if ( b==0 ) return a;
	return gcd(b,a%b);
}
int main(void)
{
	int t; cin>>t;
	while ( t-- ){
		LL a, b; cin>>a>>b;
		LL fenzi = a+3*b;
		LL fenmu = 4*(a+b);
		cout<<fenzi/gcd(fenzi,fenmu)<<"/"<<fenmu/gcd(fenzi,fenmu)<<endl;
	}
	return 0;
}
