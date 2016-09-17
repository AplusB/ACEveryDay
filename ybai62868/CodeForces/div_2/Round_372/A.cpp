# include <cstdio>
# include <iostream>
using namespace std;
typedef long long LL;
int main(void)
{
	LL l1,r1,l2,r2; cin>>l1>>r1>>l2>>r2;
	LL k; cin>>k;
	LL a = max(l1,l2);
	LL b = min(r1,r2);
	cout<<max(b-a+((k > b)||(k < a )),0LL);
	return 0;
}
