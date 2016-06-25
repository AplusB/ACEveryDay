#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <iostream>
#define CLEAR(A, X) memset(A, X, sizeof(A))
#define FREAD(fn) freopen(fn, "r", stdin)
#define REP(N) for(int i=0; i<(N); i++)
#define REPE(N) for(int i=1; i<=(N); i++)
#define pb(X) push_back(X) 
using namespace std;
typedef long long ll;
const int MAX_N = 105;
int n;
int a[MAX_N];

int main()
{
	FREAD("686b.txt");
	while(~scanf("%d", &n)){
		REP(n) scanf("%d", &a[i]);
		int s = 0;
		while(1){
			s = 0;
			while(s < n-1 && a[s] <= a[s+1]) s++;
			if(s == n-1) break;
			printf("%d ", s+1);
			int cur = s+1;
			while(cur < n && a[cur] <= a[s]){
				swap(a[cur], a[s]);
				s += 2;
				cur = s + 1;
			}
			printf("%d\n", s);
		}
		printf("\n");
	}
	return 0;
}
