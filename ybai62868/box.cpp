# include <cstdio>
# include <iostream>
# include <algorithm>
using namespace std;
# define MAX 123
int a[MAX];
int cmp( int a,int b )
{
	return a > b;
}
int main(void)
{
	int n;
	int t = 0;
	while ( scanf("%d",&n)!=EOF ) {
		if ( n==0 ) break;
		t++;
		int sum = 0;
		for ( int i = 0;i < n;i++ ) {
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		int ave = sum/n;
		sort(a,a+n,cmp);
		int res = 0;
		for ( int i = 0;i < n;i++ ) {
			if ( a[i]<= ave ) break;
			res += a[i]-ave;
		}
		printf("Set #%d\n",t);
		printf("The minimum number of moves is %d.\n\n",res);
	}

	return 0;
}
