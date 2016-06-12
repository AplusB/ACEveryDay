#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int m,n;
		cin>>m>>n;
		cout<<((n*(n+1))/2)*((m*(m+1))/2)<<endl;
	}
	return 0;
}
