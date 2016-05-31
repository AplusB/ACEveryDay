# include <cstdio>
# include <iostream>
# include <vector>
# include <cmath>
using namespace std;
# define MAX 12345
int a[MAX];
int main(void)
{
	int n; cin>>n;
	for ( int i = 1;i <= n;i++ )
	{
		cin>>a[i];
	}
	int pos1 = 0, pos2 = 0;
	for ( int i = 1;i <= n;i++ )
	{
		if ( a[i]==n ) pos1 = i;
		if ( a[i]==1 ) pos2 = i;
	}
	if ( pos1 > pos2 ) swap(pos1,pos2);
	printf("%d\n",max(n-pos1,pos2-1));
	return 0;
}
