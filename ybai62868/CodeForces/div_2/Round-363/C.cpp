# include <cstdio>
# include <iostream>
using namespace std;
# define MAX 123
int a[MAX];
int main(void)
{
	int res = 0;
	int n; cin>>n;
	for( int i = 1;i <= n;i++ ) cin>>a[i];
	a[0]=3;
	for( int i = 1;i <= n;i++ ) {
        if( a[i]==3&&a[i-1]!=3 ) a[i]=3-a[i-1];
        if( a[i]==1&&a[i-1]==1 ) a[i]=0;
        if( a[i]==2&&a[i-1]==2 ) a[i]=0;
        if( a[i]==0 ) res++;
	}
	cout<<res<<endl;
	return 0;
}
