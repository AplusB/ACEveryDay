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

int n, cnt;
char flat[MAX_N];
int num[26*2];
map<char, int> M;

int main()
{
	FREAD();
	RINT(n);
	RSTR(flat);
	cnt = 0;
	REP(n){//计数，得下界
		if(isupper(flat[i])){
			if(num[flat[i] - 'A'] == 0) cnt++;
			num[flat[i]-'A']++;
		}else{
			if(num[flat[i] - 'a' + 26] == 0) cnt++;
			num[flat[i]-'a' + 26]++;
		}
	}
	// PINT(cnt);
	// pn();
	int s = 0;//第一个不重复的
	while(flat[s] == flat[0]) s++;
	s--;
	int e = s;
	for(int cntr = 0; cntr < cnt; e++){
		if(M.find(flat[e]) == M.end()){
			//printf("add new %c\n", flat[e]);
			M[flat[e]] = 1;
			cntr++;
		}else{
			//printf("add again %c\n", flat[e]);
			M[flat[e]]++;
		}
	}
	e--;
	//保证每个元素都已创建key-value对了

	// printf("%d %d\n", s, e);
	// for(int i=s; i<=e; i++){
	// 	printf("%c ", flat[i]);
	// }
	// bool flag = 1;
	// while(flag){
	// 	flag = 0;
	// 	while(M[flat[s]]>1){//这样会陷入局部最优出不来。。。
	// 		flag = 1;
	// 		M[flat[s]]--;
	// 		s++;
	// 	}
	// 	while(M[flat[e]] > 1){
	// 		flag = 1;
	// 		M[flat[e]]--;
	// 		e--;
	// 	}
	// }
	int ans = e - s + 1;
	for(; e < n; e++){
		while(M[flat[s]]>1){//s走到不能走为止，保证完整性
			M[flat[s]]--;
			s++;
		}
		ans = min(ans, e - s + 1);
		// printf("%d %d\n", s, e);
		// for(int i=s; i<=e; i++){
		// 	printf("%c ", flat[i]);
		// }
		// pn();
		M[flat[e]]++;//e向前拓展一步
	}
	printf("%d\n", ans);
	return 0;
}
