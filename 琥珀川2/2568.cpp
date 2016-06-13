#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		long long sum=0;
		cin>>n;

		while(n>0)
		{
			if(n&1==1)
			{
				sum++;
				n--;
			}
			else
			{
				n=(n>>1);
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
