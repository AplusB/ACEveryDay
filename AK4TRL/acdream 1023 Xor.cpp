//要去湘潭了，叉姐专题一练
//找出x使A组数能通过异或变成B组数，B组数没有顺序= =
//找规律啥的。我们先看看A组的二进制->000  B组-> 001  x-> 010 或当 A{}=（0，1，2），B{}=(4,5,6)时 A->000  B->100 x->100
//                                   001        010                   x = 4                         001     101
//                                   011        011                                                 010     110
//可看出，当各位上的1数量相等时x的相应位为1，不相等时为0。因当1^0=1，0^0=0,1^1=0，因而当数量不等时意味着x此位为1
#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
ll a, b;
ll anum[35], bnum[35];
void cals(ll x, int tmp){
	ll cnt = 0;
	while(x > 0){
		if(tmp == 1)
			anum[cnt++] += (x % 2)? 1 : 0;
		else
			bnum[cnt++] += (x % 2)? 1 : 0;
		x >>= 1;
	}
}
int main(){
#ifdef _CONSOLE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n;
	while(~scanf("%d",&n)){
		for(int i = 0; i < n; ++i){
			scanf("%lld",&a);
			cals(a,1);
		}
		for(int i = 0; i < n; ++i){
			scanf("%lld",&b);
			cals(b,2);
		}

		ll ans = 0;
		bool flag = false;
		for(int i = 0; i < 32; ++i){
			if(anum[i] != bnum[i]){
				if(anum[i] + bnum[i] == n)
					ans += (1 << i);
				else
					flag = true;
			}
		}
		if(flag)
			puts("-1");
		else
			cout << ans << endl;
	}

	return 0;
}
