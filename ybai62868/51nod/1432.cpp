# include <cstdio>
# include <iostream>
# include <cmath>
# include <algorithm>
using namespace std;
# define MAX 12345
typedef long long LL;
int a[MAX];
int main(void)
{
	int n,m; cin>>n>>m;
	for ( int i = 0;i < n;i++ ){
		cin>>a[i];
	}
	sort(a,a+n);
	//for ( int i = 0;i < n;i++ ) cout<<a[i]<<endl;
	int tmp = 0,res = 0;
	int x = n-1, y = 0;
	while ( n ){
		if ( n==1 ){
			res++;
			break;
		}
		if ( a[x]+a[y] <= m ){
			x--;
			y++;
			res++;
			n-=2;
		}
		else{
			x--;
			n--;
			res++;
		}
	}
	cout<<res<<endl;
	return 0;
}
