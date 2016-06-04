# include <cstdio>
# include <iostream>
using namespace std;
# define MAX 123456
typedef long long LL;
int a[MAX];
int main(void)
{
	LL n,h,k; cin>>n>>h>>k;
	LL res = 0;
	LL t = 0;
	for ( int i = 0;i < n;i++ ){
		LL tmp; cin>>tmp;
		if ( t+tmp > h ){
			res++;
			t = 0;
		}
		t+=tmp;
		res+=t/k;
		t%=k;
	}
	if ( t!=0) res++;
	cout<<res<<endl;
	return 0;
}
