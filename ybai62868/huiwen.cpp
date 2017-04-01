# include <cstdio>
# include <iostream>
using namespace std;
int cal ( int n )
{
	int temp = n;
	int m = 0;
	while ( temp ) {
		m = m * 10+temp%10;
		temp/=10;
	}
	return m==n;
}
int main(void)
{
	int n; cin>>n;
	if ( cal(n) ) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
