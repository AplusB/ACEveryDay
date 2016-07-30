/* ***********************************************
Author        :guanjun
Created Time  :2016/7/30 13:10:44
File Name     :hdu5768.cpp
************************************************ */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <list>
#include <deque>
#include <stack>
#define ull unsigned long long
#define ll long long
#define mod 90001
#define INF 0x3f3f3f3f
#define maxn 10010
#define cle(a) memset(a,0,sizeof(a))
const ull inf = 1LL << 61;
const double eps=1e-5;
using namespace std;

ll a[20],m[20];
void ex_gcd(ll a,ll b,ll &d,ll &x,ll &y){
	if(!b){d=a;x=1LL;y=0LL;}
	else {ex_gcd(b,a%b,d,y,x);y-=x*(a/b);}
}
ll mult(ll a,ll k,ll m){
	ll res=0;
	while(k){
		if(k&1LL)res=(res+a)%m;
		k>>=1;
		a=(a<<1)%m;
	}
	return res;
}
ll china(int n,ll *a,ll *m){
	ll M=1,d,y,x=0;
	for(int i=0;i<n;i++)M*=m[i];
	for(int i=0;i<n;i++){
		ll w=M/m[i];
		ex_gcd(m[i],w,d,d,y);
		x=(x+mult(y,mult(w,a[i],M),M))%M;
	}
	return (x+M)%M;
}
ll p[20],yu[20];
int n;
ll get_ans(ll x){
	if(x==0)return 0;
	ll ans=0;
	int st=(1<<n);
	for(int i=1;i<st;i++){
		int cnt=0;
		ll cur=1;
		m[cnt]=7;a[cnt]=0;
		cur*=7;cnt++;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				m[cnt]=p[j];
				a[cnt]=yu[j];
				cnt++;
				cur*=p[j];
			}
		}
		ll tmp=china(cnt,a,m);
		if(tmp>x)continue;
		if(cnt&1)ans+=(x-tmp)/cur+1;
		else ans-=(x-tmp)/cur+1;
	}
	//cout<<ans<<endl;
	return ans+x/7;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int T,t;
	ll l,r;
	cin>>T;
	for(int t=1;t<=T;t++){
		scanf("%d %I64d %I64d",&n,&l,&r);
		for(int i=0;i<n;i++)
			scanf("%I64d %I64d",&p[i],&yu[i]);
		printf("Case #%d: %I64d\n",t,get_ans(r)-get_ans(l-1));
	}
    return 0;
}
