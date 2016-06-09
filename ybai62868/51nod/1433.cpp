# include <cstdio>
# include <iostream>
using namespace std;
# define MAX 1234
int a[MAX];
int main(void)
{
	int n; cin>>n;
	int flag = 0, cnt = 0;
	for ( int i = 0;i < n;i++ ) cin>>a[i];
	for ( int i = 0;i < n;i++ ){
		if ( a[i]==0 ){
			flag = 1;
		}
		else{
			cnt++;
		}
	}
	if ( flag ){
		int res = cnt/9;
		for ( int i = 1;i <= res;i++ ){
			cout<<555555555;
		}
		if ( res==0 ){
			cout<<0<<endl;
			return 0;
		}
		for ( int i = 1;i <= n-cnt;i++ ){
			cout<<0;
		}
		cout<<endl;
	}
	else{
		cout<<-1<<endl;
	}
	return 0;
}
