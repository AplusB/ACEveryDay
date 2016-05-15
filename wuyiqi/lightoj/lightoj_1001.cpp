#include <cstdio>

int main() {
	int T, n;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		printf("%d %d\n", n/2, n-n/2);
	}
	return 0;
}