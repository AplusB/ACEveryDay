#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i,a,b) for(i=a;i<b;i++)
#define repu(i,a,b) for(i=a;i<=b;i++)

const LL N=2505;
LL t,n,m,ans;
LL pr[N];
bitset<N> prime;
map<LL,LL> ma;

void getprime(){
	LL i,j,k,l;
//	cout<<pow(1e10,1.0/3.0)<<endl;
	for(i=2;i<N;i++){
		if(!prime[i]){
			pr[++pr[0]]=i;
			for(j=i+i;j<N;j+=i)prime[j]=1;
		}
	}
//	cout<<pr[0]<<endl;
	for(i=1;i<=pr[0];i++){
		pr[i]=pr[i]*pr[i]*pr[i];
	}
}
 
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	LL i,j,k,l,ca=0;
	getprime();
	cin>>n;
	repu(i,1,n){
		cin>>k;
		for(j=1;j<=pr[0]&&pr[j]<=k;j++){
			while(k%pr[j]==0)k/=pr[j];
		}
		ma[k]++;
	}
	for(auto &p:ma){
		if(p.first==1ll)ans+=min(1ll,p.second);
		else {
			k=1ll*p.first*p.first;
			for(i=1;i<=pr[0]&&pr[i]<=k;i++)while(k%pr[i]==0)k/=pr[i];
			ans+=max(p.second,ma[k]);
			p.second=ma[k]=0ll;
		}
	}
	cout<<ans<<endl;
	return 0;
}
