#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int S = 10;
ll fac[5];
int tot;

ll mult_mod(ll a,ll b,ll c){
	a %= c;
	b %= c;
	ll ret = 0;
	ll tmp = a;
	while(b){
		if(b&1){
			ret += tmp;
			if(ret > c) ret -= c;
		}
		tmp <<=1;
		if(tmp > c) tmp -= c;
		b>>=1;
	}
	return ret;
}

ll pow_mod(ll a,ll n, ll mod){
	ll ret = 1;
	ll tmp = a%mod;
	while(n){
		if(n&1) ret = mult_mod(ret,tmp,mod);
		tmp = mult_mod(tmp,tmp,mod);
		n>>=1;
	}
	return ret;
}
int cm(ll a,ll n,ll x,ll t){
	ll ret = pow_mod(a,x,n);
	ll last = ret;
	for(int i=1;i<=t;i++){
		ret = mult_mod(ret,ret,n);
		if(ret ==1 && last!=1 && last !=n-1) return 1;
		last = ret;
	} 
	if(ret != 1) return 1;
	else return 0;
}

int MR(ll n){
	if(n==2) return 1;
	if((n&1)==0||n==1) return 0;
	ll x = n-1;
	ll t = 0;
	while( (x&1) == 0) {x >>=1; t++;}
	srand(time(NULL));
	for(int i=0;i < S;i++){
		ll a = rand()%(n-1)+1;
		if(cm(a,n,x,t))
			return 0;
	}
	return 1;	 
}

ll gcd(ll a,ll b){
	ll t;
	while(b){
		t=a;
		a=b;
		b=t%b;
	}
	if(a>=0) return a;
	return -a;
}

ll PR(ll x,ll c)
{
	ll i=1,k=2;
	srand(time(NULL));
	ll x0 = rand()%(x-1)+1;
	ll y = x0;
	while(1){
		i++;
		x0 = (mult_mod(x0,x0,x) +c) %x;
		ll d = gcd(y-x0,x);
		if(d!=1 && d!=x) return d;
		if(y== x0) return x;
		if(i== k) {y=x0; k+=k;}
	}
}


void find(ll n,int k){
	if(n==1) return;
	if(MR(n)){
		fac[tot++]=n;
		return;
	}
	if(tot>3) return;
	ll p = n;
	int c=k;
	while(p>=n)
		p=PR(p,c--);
	find(p,k);
	find(n/p,k);
}

void check(ll n){
	tot=0;
	find(n,107);
	sort(fac,fac+tot);
	int t=0;
	for(int i=0;i<tot;i++) if(fac[i]!=fac[i-1]) t++;
	if(t==2&&tot==2)
		printf("%I64d %I64d %I64d\n",fac[0],fac[1],n);	
	else if(t==1&&tot==3)
		printf("%I64d %I64d %I64d\n",fac[0],fac[0]*fac[0],n);	
	else puts("is not a D_num");
}
int main()
{
	ll n;
	while(cin>>n) check(n);
	return 0;
}
