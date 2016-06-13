#include<iostream>
using namespace std;

int n;
int a[125],b[125];

int main()
{
	while(cin>>n)
	{
		for(int i=0;i<=n;i++)
		{
			a[i]=1;
			b[i]=0;
		}

		for(int i=2;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				for(int k=0;k+j<=n;k+=i)
				{
					b[k+j]+=a[j];
				}
			}

			for(int j=0;j<=n;j++)
			{
				a[j]=b[j];
				b[j]=0;
			}
		}

		cout<<a[n]<<endl;
	}
	return 0;
}
