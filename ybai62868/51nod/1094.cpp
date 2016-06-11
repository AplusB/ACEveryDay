# include <cstdio>
# include <iostream>
# include <cmath>
# include <algorithm>
using namespace std;
typedef long long LL;
# define MAX 12345
int a[MAX];
int main(void){
	int n;
	LL k;
	cin>>n>>k;
	for ( int i = 1;i <= n;i++ )
	{
		cin>>a[i];
	}
	int flag = 0;
	LL tmp = 0;
	int pos1 = 0, pos2 = 0;
	for ( int i = 1;i <= n-1;i++)
	{
		tmp = a[i];
		for ( int j = i+1;j <= n;j++ )
		{
			tmp+=a[j];
			if ( tmp==k )
			{
				pos1 = i;
				pos2 = j;
				flag = 1;
				break;
			}
		}
		if ( flag ) break;
	}
	if (flag ) cout<<pos1<<" "<<pos2<<endl;
	else puts("No Solution");
	return 0;
}
