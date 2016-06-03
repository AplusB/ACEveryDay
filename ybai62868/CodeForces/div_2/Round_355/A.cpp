# include <cstdio>
# include <iostream>
using namespace std;
# define MAX 12345
int a[MAX];
int main(void)
{
	int n,h; cin>>n>>h;
	for ( int i = 0;i < n;i++ ) cin>>a[i];
	int res = 0;
	for ( int i = 0;i < n;i++ )
	{
		if ( a[i] > h ) res+=2;
		else res+=1;
	}
	cout<<res<<endl;
	return 0;
}
