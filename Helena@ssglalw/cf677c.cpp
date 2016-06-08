#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cctype>
#include <assert.h>
#include <queue>
#include <map>
#define CLEAR(A, X) memset(A, X, sizeof(A))
#define REP(N) for(int i=0; i<(N); i++)
#define REPE(N) for(int i=1; i<=(N); i++)
#define FREAD(FN) freopen((FN), "r", stdin)
#define pb(a) push_back(a)
#define pf() pop_front()
using namespace std;
typedef long long ll;
const int MAX_N = 100005;
const int MOD = 1000000007;
char s[MAX_N];
char num[65];
map<char, int> m;

int main()
{
	int cnt = 0;
	REP(10){
		num[cnt] = '0' + i;
		m['0'+i] = cnt;
		cnt++;
	}
	REP(26){
		num[cnt] = 'A' + i;
		m['A'+i] = cnt;
		cnt++;
	}
	REP(26){
		num[cnt] = 'a' + i;
		m['a'+i] = cnt;
		cnt++;
	}
	num[cnt] = '-'; m['-'] = cnt++;
	num[cnt] = '_'; m['_'] = cnt++;
	assert(cnt == 64);
	scanf("%s", s);
	int n = strlen(s);
	ll ans = 1;
	REP(n){
		ll x = m[s[i]];
		for(int j=0; j<6; j++)
			if((x&(1<<j)) == 0)
				ans = (ans*3) % MOD;
	}
	printf("%I64d\n", ans);
	return 0;
}
