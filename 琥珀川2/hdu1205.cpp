#include<iostream>
#include<algorithm>
using namespace std;



typedef long long ll;

ll k[1000010];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>k[i];
		}
		sort(k,k+n);

		ll sum=0;
		for(int i=0;i<n-1;i++)
		{
			sum+=k[i];
		}
		if(sum<k[n-1]-1)
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
	}
	return 0;
}
