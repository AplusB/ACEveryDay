#include<iostream>
using namespace std;

int main()
{
	long long a,b,c;
	while(cin>>a>>b>>c)
	{
				if((a+b)==c||(a+c)==b||(b+c)==a)
					cout<<"oh,lucky!"<<endl;
				else if((a*b)==c||(a*c)==b||(b*c)==a)
					cout<<"oh,lucky!"<<endl;
				else if((b!=0&&(a%b==c||c%b==a))||(c!=0&&(a%c==b||b%c==a))||(a!=0&&(b%a==c||c%a==b)))
					cout<<"oh,lucky!"<<endl;
				else
					cout<<"what a pity!"<<endl;
	}
	return 0;
}
