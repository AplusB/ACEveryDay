# include <cstdio>
# include <iostream>
using namespace std;
# define MAX 112345
int x[MAX],y[MAX];
typedef long long LL;
int main(void)
{
	LL n,m; cin>>n>>m;
	LL ans1 = 0, ans2 = 0;
	for ( int i = 0;i < m;i++ ){
		int t1,t2; cin>>t1>>t2;
		if (!x[t1]){
			ans1++;
			x[t1] = 1;
		}
		if (!y[t2]){
			ans2++;
			y[t2] = 1;
		}
		LL res = n*n-n*(ans1+ans2)+ans1*ans2;
		cout<<res<<endl;
	}
	return 0;
}
