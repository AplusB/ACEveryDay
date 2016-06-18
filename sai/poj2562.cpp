#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main()
{
	string n1,n2;
	while(cin>>n1>>n2)
	{
		if(n1=="0"&&n2=="0")break;

		int sum=0;
		int flag=0;
		int l1=n1.length();
		int l2=n2.length();
		l1--;
		l2--;

		while(l1>=0&&l2>=0)
		{
			int num=(n1[l1]-'0')+(n2[l2]-'0');
			if(flag==1)
			{
				num++;
				flag=0;
			}
			if(num>9)
			{
				sum++;
				flag=1;
			}

			l1--;
			l2--;
		}

		while(l1>=0)
		{
			int num=(n1[l1]-'0');
			if(flag==1)
			{
				num++;
				flag=0;
			}
			if(num>9)
			{
				sum++;
				flag=1;
			}

			l1--;
		}

		while(l2>=0)
		{
			int num=(n2[l2]-'0');
			if(flag==1)
			{
				num++;
				flag=0;
			}
			if(num>9)
			{
				sum++;
				flag=1;
			}

			l2--;
		}

		if(sum==0)
		{
			cout<<"No carry operation."<<endl;
		}
		else if(sum==1)
		{
			cout<<"1 carry operation."<<endl;
		}
		else
		{
			cout<<sum<<" carry operations."<<endl;
		}
	}
	return 0;
}
