#include<iostream>
using namespace std;

int gcd(int a,int b)
{
	return (b==0?a:gcd(b,a%b));
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		int e,f;
		e=a*d+b*c;
		f=b*d;
		int g=gcd(e,f);
		e/=g;
		f/=g;
		cout<<e<<" "<<f<<endl;
	}
	return 0;
}
