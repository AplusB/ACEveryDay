# include <cstdio>
# include <iostream>
# define MAX 123
using namespace std;
int a[MAX];
int cnt[MAX];
int main(void)
{
	int n; cin>>n;
	int sum = 0;
	for ( int i = 1;i <= n;i++ ){
		cin>>a[i];
		sum+=a[i];
	}
	sum = sum/(n/2);
	for ( int i = 1;i <= n-1;i++ ){
		int temp = sum-a[i];
		for ( int j = i+1;j <= n;j++ ){
			if ( cnt[j]==0&&cnt[i]==0&&temp==a[j] ){
				cout<<i<<" "<<j<<endl;
				cnt[i] = cnt[j] = 1;
				break;
			}
		}
	}
	return 0;
}
