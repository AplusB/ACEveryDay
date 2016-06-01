#include <iostream>
using namespace std;

int n, k, a, b, st, ans;
string s;
int main(void) {
	cin >> n >> k >> s;
	for(char c: s) {
		if(c == 'a') a++;
		else b++;
		if(min(a, b) > k) {
			if(s[st] == 'a') a--;
			else b--;
			st++;
		} else ans=max(ans, a+b);
	}
	printf("%d\n", ans);
}
