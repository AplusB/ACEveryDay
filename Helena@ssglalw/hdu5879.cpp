#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>
#define RINT(V) scanf("%d", &(V))
#define FREAD() freopen("in.txt", "r", stdin)
#define REP(N) for(int i=0; i<(N); i++)
#define REPE(N) for(int i=1; i<=(N); i++)
#define PINT(N) printf("%d", (N))
#define PSTR(S) printf("%s", S)
#define RSTR(S) scanf("%s", S)
#define pn() printf("\n")
#define pb(V) push_back(V)
using namespace std;
typedef long long ll;
const int MAX_N = 2000005;

char s[MAX_N];
double t[MAX_N];
int n;


int main()
{
	FREAD();
	t[0] = 0; t[1] = 1;
	for(ll i=2; i<MAX_N; i++){
		t[i] = t[i-1] + (double)1.0/(ll)(i*i);
	}
	while(~RSTR(s)){
		int len = strlen(s);
		if(len >= 7) puts("1.64493");
		else{
			sscanf(s, "%d", &n);
			if(n >= MAX_N) puts("1.64493");
			else printf("%.5lf\n", t[n]);
		}
	}
	return 0;
}
