#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <assert.h>
#define FREAD() freopen("in.txt", "r", stdin)
#define RINT(vn) scanf("%d", &(vn))
#define PINT(vb) printf("%d", vb)
#define RSTR(vn) scanf("%s", (vn))
#define PSTR(vn) printf("%s", (vn))
#define CLEAR(A, X) memset(A, X, sizeof(A))
#define REP(N) for(int i=0; i<(N); i++)
#define REPE(N) for(int i=1; i<=(N); i++)
#define pb(X) push_back(X)
#define pn() printf("\n")
typedef __int64 ll;
#define sz(a) ll((a).size())
using namespace std;
const int MAX_N = 100005;

int n;
int a[MAX_N];
map<unsigned, unsigned> cnt;
unsigned power[32];

void initPower(){
	power[0] = 1;
	for(int i=1; i<32; i++){
		power[i] = power[i-1]<<1;
		//printf("%u\n", power[i]);
	}
}

ll com2(ll m){
	if(m < 2) return 0;
	return m*(m-1)/2;
}

int main()
{
	FREAD();
	initPower();
	RINT(n);
	REP(n){
		RINT(a[i]);
		cnt[a[i]]++;
	}
	map<unsigned, unsigned>::iterator iter = cnt.begin();
	ll ans = 0;
	for(; iter != cnt.end(); iter++){
		//printf("%u %u\n", iter->first, iter->second);
		for(int p = 0; p < 32; p++){
			unsigned dif = power[p] - iter->first;
			if(dif <= 0) continue;//另一项小于等于0
			if(dif == iter->first) ans += com2(iter->second);
			else if(dif > iter->first){
				if(cnt.find(dif) != cnt.end()){
					ans += cnt[dif]*iter->second;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
