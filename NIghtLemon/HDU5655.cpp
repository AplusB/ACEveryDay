#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
	int T;
	ll a[4];
	cin>>T;
	while(T--){
		cin>>a[0]>>a[1]>>a[2]>>a[3];
		sort(a,a+4);
		if(a[0] && (a[2]>(a[3]-a[0]) || a[2]>((a[3]-a[0])-a[1])))
			cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
