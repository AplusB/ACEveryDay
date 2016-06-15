#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	int n;
	while(~scanf("%d", &n)) {
		bool ans = false;
		for(int i = 0; i < n; ++i){
			int a, b; char buf[22];
			scanf("%s%d%d", buf, &a, &b);
			if(a >= 2400 && a < b)
				ans = true;
		}
		puts(ans ? "YES" : "NO");
	}
	return 0;
}
