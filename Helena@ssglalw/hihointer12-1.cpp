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
#define FREAD(fn) freopen((fn), "r", stdin)
#define RINT(vn) scanf("%d", &(vn))
#define PINT(vb) printf("%d", vb)
#define RSTR(vn) scanf("%s", (vn))
#define PSTR(vn) printf("%s", (vn))
#define CLEAR(A, X) memset(A, X, sizeof(A))
#define REP(N) for(i=0; i<(N); i++)
#define REPE(N) for(i=1; i<=(N); i++)
#define pb(X) push_back(X)
#define pn() printf("\n")
using namespace std;
const int MAX_N = 45;
int i, j;

int n;

struct Word
{
	string word;
	string alphabeta;
	int code;
	int cnt;
}w[MAX_N];
bool cmp(Word w1, Word w2){
	if(w1.cnt == w2.cnt){
		return w1.code > w2.code;//字典序靠前的
	}
	return w1.cnt < w2.cnt;//短的
}


int main()
{
	FREAD("inter12-1.txt");
	RINT(n);
	getchar();
	REP(n){
		cin >> w[i].word;

		//cout << w[i].word << endl;
		for(int c = 0; c < w[i].word.length(); c++){
			int num = w[i].word[c] - 'a';
			num = 25 - num;
			if((w[i].code & (1<<num))==0){
				w[i].code |= (1<<num);
				w[i].cnt++;
			}
		}
	}
	int ans = 0;
	int cnt = 0;
	int cur = 0;
	sort(w, w+n, cmp);
	for(j=0; j<n; j++){
		ans = 1;
		cur = w[j].code;
		for(i=0; i<n; i++){
			// char bin[30];
			// itoa(w[i].code, bin, 2);
			// cout << w[i].word;
			// PSTR(bin);
			// pn();
			if(i == j) continue;
			if((cur & w[i].code) == 0){//&处加括号！因为==优先级比&高
				cur |= w[i].code;
				ans++;
			}
		}
		cnt = max(cnt, ans);
	}
	
	PINT(cnt);
	return 0;
}
