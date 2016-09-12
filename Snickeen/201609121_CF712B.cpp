#include<bits/stdc++.h> 
using namespace std;
typedef long long LL;
typedef double db;
#define rep(i,a,b) for(i=a;i<b;i++)
const int maxn = 100000+10;
const LL MOD=1e9+7;
const double PI = acos(-1.0);
LL t,n,m,ans,f[maxn];
string s;

int main()
{
	LL i,j,k,l,r;
	cin>>s;
	l=s.size();
	if(l&1)return cout<<"-1",0;
	rep(i,0,l){
		if(s[i]=='R')n++;
		else if(s[i]=='L')n--;
		else if(s[i]=='U')m++;
		else if(s[i]=='D')m--;
	}
	n=abs(n);m=abs(m);
	ans=(n+m)/2;
	cout<<ans<<endl;
	return 0;
}
