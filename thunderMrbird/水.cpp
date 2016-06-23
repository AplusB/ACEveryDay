#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--){
		long long s,a,b;
		cin>>a>>b;
		s=a+b;
		s=s%100;
		cout<<s<<endl;
	}
 }
