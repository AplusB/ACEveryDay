//CF#351 (VK Cup 2016 Round 3, Div. 2 Edition)
//A - Bear and Game
#include <bits/stdc++.h>
using namespace std;
#define LL long long
int a[100];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	a[0]=0;
	a[n+1]=90;
	int ans=0;
	for(int i=0;i<=n;i++){
		if(a[i]+15>=a[i+1]) ans=a[i+1];
		else break;
	}
	cout<<(min(ans+15,90))<<endl;
	return 0;
}
//B - Problems for Round
#include <bits/stdc++.h>
using namespace std;
#define LL long long
int main()
{
	int n,m,a,b;
	cin>>n>>m;
	int l=1,r=n;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		if(a>b) swap(a,b);
		l=max(l,a);
		r=min(r,b); 
	}
	if(l<r) cout<<r-l<<endl;
	else puts("0");
	return 0;
}
//C - Bear and Colors
#include <bits/stdc++.h>
using namespace std;
#define LL long long
int a[5010],v[5010],ans[5010];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		memset(v,0,sizeof v);
		int mx=0,mm=5000;
		for(int j=i;j<n;j++){
			v[a[j]]++;
			if(v[a[j]]>mx){
				mx=v[a[j]];
				mm=a[j];
			}
			else if(v[a[j]]==mx){
				mm=min(a[j],mm);
			}
			ans[mm]++;
		}
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	return 0;
}
//D - Bear and Two Paths
#include <bits/stdc++.h>
using namespace std;
#define LL long long
int main()
{
	int n,m,a,b,c,d;
	cin>>n>>m;
	cin>>a>>b>>c>>d;
	if(n>=m||n==4){
		puts("-1");
		return 0;
	}
	cout<<a<<" "<<c<<" ";
	for(int i=1;i<=n;i++){
		if(i!=a&&i!=b&&i!=c&&i!=d) cout<<i<<" ";
	}
	cout<<d<<" "<<b<<endl;
	cout<<c<<" "<<a<<" ";
	for(int i=n;i>=1;i--){
		if(i!=a&&i!=b&&i!=c&&i!=d) cout<<i<<" ";
	}
	cout<<b<<" "<<d<<endl;
	return 0;
}
