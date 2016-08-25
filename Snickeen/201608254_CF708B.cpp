#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL N=1000000+5,M=1e5+5;
LL t,n,m,a,b,c,d,ans;
LL f[M],cnt[11],ct,num[11],tmp;
char s[N],ss[]={"Impossible"};

void solve(){
	LL i,j,k,l;
	if(a==0){
		if(d){
			if(b+c==cnt[4]){
				for(i=0;i<c;i++)s[ct++]='1';
				if(c||b)s[ct++]='0';
				for(i=0;i<b;i++)s[ct++]='1';
				cout<<s;
			}
			else if(b+c==0){
				for(i=0;i<cnt[4];i++)cout<<"1";
				cout<<endl;
			}
			else {
				cout<<ss;
			}
		}
		else if(b+c>1){
			cout<<ss;
		}
		else if(b==1) {
			cout<<"01";
		}
		else if(c==1){
			cout<<"10";
		}
		else {
			cout<<"0";
		}
	}
	else {
		
		if(b+c==cnt[1]){
			for(i=0;i<b;i++)s[ct++]='0';
			if(c||b)s[ct++]='1';
			for(i=0;i<c;i++)s[ct++]='0';
			cout<<s;
		}
		else if(b+c==0){
			for(i=0;i<cnt[1];i++)cout<<"0";
			cout<<endl;
		}
		else cout<<ss;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
//	cout<<(t=(40000*40000-40000)/2)<<endl;
//	cout<<t*t<<endl;
	LL i,j,k,l,flag=0;
	cin>>a>>b>>c>>d;
	for(i=2;i<M;i++){
		f[i]=(i*(i-1)/2);
	}
	for(i=1;i<M;i++){
		if(a==f[i]){
			cnt[1]=i;break;
		}
	}
	for(i=1;i<M;i++){
		if(d==f[i]){
			cnt[4]=i;break;
		}
	}
	
//	cout<<cnt[1]<<" "<<cnt[4]<<endl;
	if(cnt[1]==0||cnt[4]==0||cnt[1]+cnt[4]>1000000)return cout<<"Impossible"<<endl,0;
	if(a==0||d==0){
		solve();
		return 0;
	}
	if(cnt[1]*cnt[4]!=b+c)return cout<<"Impossible"<<endl,0;
	num[0]=b/cnt[4];
	num[2]=b%cnt[4];
	num[4]=cnt[1]-num[0]-(num[2]>0?1:0);
	for(i=0;i<num[0];i++)s[ct++]='0';
	for(i=0;i<cnt[4]-num[2];i++)s[ct++]='1';
	if(num[2]){s[ct++]='0';}
	for(i=0;i<num[2];i++)s[ct++]='1';
	for(i=0;i<num[4];i++)s[ct++]='0';
	cout<<s<<endl;
	return 0;
}
