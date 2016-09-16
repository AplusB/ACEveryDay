#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
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
const int MAX_N = 15;
const int MOD = 100000000;

int m, n;
int b[MAX_N][MAX_N];
int a[MAX_N];//b的二进制形式

ll dp[(1<<12)+5][MAX_N];//st, line
ll dsum[MAX_N];//每行求和
ll cnt = 0;

bool ok(int x, int y, int row){
	//cout <<"enter ok " << x << " " << y << " " << a[row] << endl;
	if((y & a[row]) != y) return false;
	if((y & (y << 1)) != 0) return false;
	if((x & y) != 0) return false;
	// if((x & (y<<1)) != 0) return false;
	// if((x & (y>>1)) != 0) return false;
	return true;
}

int main()
{
	FREAD();
	RINT(m); RINT(n);
	REP(m){
		for(int j=0; j<n; j++){
			RINT(b[i][j]);
			a[i] <<= 1;
			a[i] |= b[i][j];
		}
	}
	for(int i=0; i<(1<<n); i++){
		if(ok(0, i, 0)){
			dp[i][0] = 1;
		}
	}
	//cout << cnt << endl;
	for(int i=1; i<=m; i++){//对于接下来的每行
		for(int j=0; j<(1<<n); j++){//枚举上一行的状态
			if((j & (j<<1)) != 0) continue; //自身不相容
			if((j & a[i]) != j) continue; //和原图不相容
			for(int k=0; k<(1<<n); k++){//枚举此行的状态
				if((k & j) != 0) continue;//与上一行不相容
				dp[j][i] += dp[k][i-1];
				dp[j][i] %= MOD;
			}
		}
	}
	REP(1<<m){
		cnt += dp[i][m];
		cnt %= MOD;
	}
	cout << cnt << endl;
	return 0;
}
