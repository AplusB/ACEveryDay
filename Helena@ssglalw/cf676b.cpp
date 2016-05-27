#include <cstdio>
#include <cmath>
using namespace std;
const int MAX_N = 10;

int t, n;
int num;
int v[MAX_N*(MAX_N+1)/2 + 1];
int volume;
int cnt;

void add(int cur, int i, int l){
	if(l > n) return ;
	if(cur + v[i] <= volume){//最多加满当前的，不会溢出 
		v[i] += cur;
		return ;
	}
	int surplus = cur - (volume - v[i]);//有溢出 
	v[i] = volume;
	add(surplus/2, i+l, l+1);
	add(surplus/2, i+l+1, l+1);
}

int main()
{
	scanf("%d%d", &n, &t);
	num = n*(n+1)/2;
	volume = pow(2, n);
	int cur = volume * t;
	cnt = 0;
	add(cur, 1, 1);
	 for(int i=1; i<=num; i++){
	 	//printf("%d %d\n", i, v[i]);
	 	if(v[i] == volume) cnt++;
	 }
	printf("%d\n", cnt);
	return 0;
}
