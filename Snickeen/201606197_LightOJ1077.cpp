#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL gcd(LL a,LL b){return b==0?a:gcd(b,a%b);}
int main()
{
    	LL t,cas=0,a,b,c,d;
    	scanf("%lld",&t);
    	while(t--){
        		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        		printf("Case %lld: %lld\n",++cas,(LL)__gcd(abs(c-a),abs(d-b))+1LL);
    	}
    	return 0;
}
