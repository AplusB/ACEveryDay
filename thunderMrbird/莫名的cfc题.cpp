#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
	ll a,n,m,i,j,k,l1,l2,ans=0;
	cin >> n >> m;
	l1 = l2 = 1;
	for(i=7;i<n;i*=7)
		l1++;
	for(i=7;i<m;i*=7)
		l2++;
	if(l1+l2<=7)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				vector<ll>used(7,0);
				for(a=i,k=0;k<l1;k++,a/=7)
					used[a%7]++;
				for(a=j,k=0;k<l2;k++,a/=7)
					used[a%7]++;
			if(*max_element(used.begin(),used.end())<=1)
				ans++;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
