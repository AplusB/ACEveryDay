#include<iostream>
#include<algorithm>
using namespace std;

struct arr{
	int len;
	int num;
}a[55];


bool cmp(arr a,arr b)
{
	return a.len<b.len;
}

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
			cin>>a[i].len>>a[i].num;
		}
		sort(a,a+n,cmp);

		for(int i=0;i<n;i++)
		{
			//if(i!=0)
				//
			for(int j=0;j<a[i].num;j++)
			{
				cout<<">+";
				for(int k=0;k<a[i].len-2;k++)
					cout<<"-";
				cout<<"+>";
				cout<<endl;
			}
			cout<<endl;
		}

	}
	return 0;
}
