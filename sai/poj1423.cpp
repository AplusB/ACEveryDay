#include<iostream>
#include<math.h>
using namespace std;

#define pi acos(-1.0)
#define e 2.718281828

double strling(int n)
{
	return log10(2*pi*n)/2.0+n*log10(n/e);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int m;
		cin>>m;
		cout<<(int)strling(m)+1<<endl;
	}
	return 0;
}
