# include <cstdio>
# include <iostream>
# include <cmath>
# include <stack>
# include <string>
# include <algorithm>
using namespace std;
typedef long long LL;
# define MAX 123456
string res;
string str;
stack<int>s;
int cnt;
void work( int x )
{
	while ( x )
	{
		res.push_back((x%10)+'0');
		x/=10;
	}
	reverse(res.begin(),res.end());
	str+=res;
	res.clear();
}
int main(void)
{
	int n; cin>>n;
	for ( int i = 1;i <= 10001;i++ )
	{
		work(i);
	}
	cout<<str[n-1]<<endl;
	return 0;
}
