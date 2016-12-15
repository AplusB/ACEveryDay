#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=2e5+60;
const int inf=2e9+9;
const ll mod=1e9+7;
const double eps=1e-9;

string a;
string b[maxn];

char cc(char x,int v);
int cmp(string x,string y);

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		cin>>a;
		for(int i=n;i<2*n;i++)
			a+=a[i-n];
		int pos=0;
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<n;j++)
			{
				string now="";
				for(int k=j;k<j+n;k++)
				{
					now+=cc(a[k],i);
				}
				b[pos++]=now;
			}
		}
		sort(b,b+pos,cmp);
		cout<<b[0]<<endl;
		
	}
	return 0;
}

int cmp(string x,string y)
{
	return x<y;
}

char cc(char x,int v)
{
	int y=x-'0';
	y+=v;
	y%=10;
	return '0'+y;
}
