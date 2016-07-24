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
ll n, m;
set<int> row, col;

//思路来自：http://codeforces.com/contest/701/submission/19334327 平移到角落，分块减
//http://codeforces.com/blog/entry/46195 vntshh
int main()
{
	FREAD();
	cin >> n >> m;
	ll left;
	int x, y;
	while(m--){
		cin >> x >> y;
		row.insert(x);
		col.insert(y);
		left = n*n;
		left -= sz(row)*(n-sz(col));
		left -= (n-sz(row))*sz(col);
		left -= sz(row)*sz(col);
		cout << left << " ";
	}
	return 0;
}
