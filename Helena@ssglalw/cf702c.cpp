#include <cstdio>
#include <set>
#include <algorithm>
#define REP(N) for(int i=0; i<(N); i++)
#define RINT(A) scanf("%d", &(A))
#define PINT(A) printf("%d", A)
#define FREAD() freopen("in.txt", "r", stdin)
#define pn() printf("\n")
using namespace std;
const int MAX_N = 100005, MAX_M = 100005;
const int INF = 0x7fffffff;

int n, m;
int a[MAX_N], b[MAX_M];
set<int> towers;

int main()
{
	FREAD();
	RINT(n); RINT(m);
	REP(n) RINT(a[i]);
	REP(m){
		RINT(b[i]);
		towers.insert(b[i]);
	}
	int ans = 0;
	set<int>::iterator iter = towers.begin();
	REP(n){
		int r = INF;
		iter = towers.lower_bound(a[i]);
		//if(iter != towers.end()) printf("iter %d\n", *iter);
		if(iter == towers.end()) r = a[i] - *(--iter);//a[i]超过最右的基站, 只考虑右侧
		else if(*iter == a[i]) r = 0;//命中基站
		else{//未命中，且右侧存在基站
			r = min(r, *(iter)-a[i]);//考虑右侧
			if(iter != towers.begin()){
				--iter;
				r = min(r, a[i] - *iter);//若左侧存在，考虑左侧
			}
		}
		ans = max(ans, r);
	}
	PINT(ans);
	return 0;
}
