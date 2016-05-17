#include <bits/stdc++.h>
using namespace std;
int T;
const int MAXN = 5000010;
unsigned long long num[MAXN];
void init() {
	for(int i=1; i<=5000000; i++)
		num[i] = i;
	for(int i=2; i<=5000000; i++) {
		if(num[i] == i)
		for(int j=i; j<=5000000; j+=i)
				num[j] = num[j] - num[j]/i;
	}
	num[1] = 1;
	num[2] = 1;
	for(int i=2; i<=5000000; i++)
		num[i] *= num[i], num[i] = num[i-1] + num[i];
}
int main() {
	cin>>T;
	init();
	int a, b;
	for(int icase = 1; icase <= T; icase++) {
		scanf("%d %d", &a, &b);	
		printf("Case %d: %llu\n", icase, num[b] - num[a-1]);
	}
	return 0;
}