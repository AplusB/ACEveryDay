#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long long t,n;
	double x,ans;
	cin>>t;
	while(t--)
	{
		cin>>n;
		x=n*log10(n);
		ans=pow(10,x-(long long)x);
		cout<<(int)ans<<endl;
	}
}
