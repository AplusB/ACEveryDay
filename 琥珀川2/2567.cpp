#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s,in;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>s>>in;
		s.insert(s.length()/2,in);
		cout<<s<<endl;
	}
	return 0;
}
