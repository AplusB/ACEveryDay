#include<bits/stdc++.h>
using namespace std;

int t,n,m,ans;
string a,b,c;
map<string,string> ma;

int main()
{
	int i,j,k,l;
	cin>>n>>m;
	while(m--)
	{
		cin>>a>>b;
		if(a.size()>b.size())c=b;
		else c=a;
		ma[a]=ma[b]=c;
	}
	while(n--)
	{
		cin>>a;
		cout<<ma[a]<<" ";
	}
	return 0;
}
