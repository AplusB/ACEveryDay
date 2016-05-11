#include <cstdio>
using namespace std;

int T;
int n, a, b;

int gcd(int x, int y){
	if(y == 0) return x;
	return gcd(y, x%y);
}

void swap(int& x, int& y){
	int tmp = x;
	x = y;
	y = tmp;
}

int main()
{
	freopen("5512.txt", "r", stdin);
	scanf("%d", &T);
	for(int ca=1; ca<=T; ca++){
		scanf("%d%d%d", &n, &a, &b);
		if(a<b) swap(a, b);
		printf("Case #%d: %s\n", ca, (n/gcd(a,b)-2)&1 ? "Yuwgna" : "Iaka");
	}
	return 0;
}