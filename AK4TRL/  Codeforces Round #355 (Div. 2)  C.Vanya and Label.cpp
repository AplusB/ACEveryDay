#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
typedef long long ll;
const ll mod = (ll)1e9 + 7;
ll ans = 1;
char s[100005];
int getNum(char c)
{
	if ('0' <= c && c <= '9') return c - '0';//panding num
	if ('A' <= c && c <= 'Z') return 10 + c - 'A';//panding A-Z
	if ('a' <= c && c <= 'z') return 36 + c - 'a';//panding a-z
	if (c == '-') return 62;
	if (c == '_') return 63;
}
int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%s", s);
	int n = strlen(s);
	for (int i = 0; i < n; ++i){
		int x = getNum(s[i]);
		for (int k = 0; k < 6; k++)
			if (((x >> k) & 1) == 0)
				ans = (ans * 3) % mod;
	}
	printf("%I64d\n", ans);

	return 0;
}
