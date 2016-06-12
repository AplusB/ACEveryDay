# include <cstdio>
# include <iostream>
# include <cmath>
# include <algorithm>
using namespace std;
typedef long long LL;
# define MAX 52345
const int mod = 1e9+7;
int a[MAX];
void pre()
{
	a[0] = a[1] = 1;
	a[2] = 2;
	for ( int i = 3;i <= 1000;i++ ){
		a[i] = (a[i-1]%mod+a[i-2]%mod)%mod;
	}
}
int main(void){
	pre();
	int n; cin>>n;
	cout<<a[n]<<endl;
	return 0;
}
