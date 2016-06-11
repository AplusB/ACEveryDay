# include <cstdio>
# include <iostream>
# include <cmath>
# include <algorithm>
using namespace std;
typedef long long LL;
# define MAX 52345
int a[MAX];
int main(void){
	int n; cin>>n;
	int flag = 0, cnt = 0;
	LL sum = 0;
	for ( int i = 0;i < n;i++ )
	{
		cin>>a[i];
		sum += a[i];
		if ( a[i] < 0 ) cnt++;
		if ( cnt==n ) flag = 1;
	}
	if ( !flag )
	{
		LL ans1 = 0, ans2 = 0;
		LL tmp = 0;
		for ( int i = 0;i < n;i++ )
		{
			tmp+=a[i];
			ans1 = max(ans1,tmp);
			if ( tmp < 0 ) tmp = 0;
		}
		tmp = 0;
		for ( int i = 0;i < n;i++ ) a[i] = a[i]*(-1);
		for ( int i = 0;i < n;i++ )
		{
			tmp+=a[i];
			ans2 = max(ans2,tmp);
			if ( tmp < 0 ) tmp = 0;
		}
		cout<<max(ans1,sum+ans2);
	}
	else
	{
		cout<<0<<endl;
	}
	return 0;
}
