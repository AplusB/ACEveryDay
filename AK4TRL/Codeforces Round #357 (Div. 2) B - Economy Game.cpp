//
#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	int n;
	while(~scanf("%d", &n)) {
		const int X = 1234567, Y = 123456, Z = 1234;
		bool ans = false;
		for(int a = 0; a * X <= n; ++a) {
			int m = n - a * X;
			for(int b = 0; b * Y <= m; ++b) {
				if((m - b * Y) % Z == 0)
					ans = true;
			}
		}
		puts(ans ? "YES" : "NO");
	}
	return 0;
}
