# include <cstdio>
# include <iostream>
using namespace std;
# define MAX 123
int a[MAX];
int main(void)
{
	int icase = 1;
	int t; cin>>t;
	while ( t-- ) {
		int n,m; cin>>n>>m;
		for ( int i = 0;i < n;i++ ) cin>>a[i];
		for ( int i = 0;i < m;i++ ) {
			char ch; cin>>ch;
			if ( ch=='S' ) {
				int d; cin>>d;
				for ( int i = 0;i < n;i++ ) a[i]+=d;
			}
			else if ( ch=='M' ) {
				int d; cin>>d;
				for ( int i = 0;i < n;i++ ) a[i]*=d;
			}
			else if ( ch=='D' ) {
				int k; cin>>k;
				for ( int i = 0;i < n;i++ ) a[i]/=k;
			}
			else if ( ch=='R' ) {
				for ( int i = 0;i < n/2;i++ ) swap(a[i],a[n-1-i]);
			}
			else {
				int y,z; cin>>y>>z;
				swap(a[y],a[z]);
			}
			/*for ( int i = 0;i < n;i++ ) cout<<a[i]<<" ";
				cout<<endl;
				*/
		}
		printf("Case %d:\n",icase++ );
		cout<<a[0];
		for ( int i = 1;i < n;i++ ) {
			cout<<" "<<a[i];
		}
		cout<<endl;
	}


	return 0;
}
