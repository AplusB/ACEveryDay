#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>

using namespace std;

typedef long long LL;
LL a, b;

int main() {
	// freopen("in", "r", stdin);
	int T, _ = 1;
	cin >> T;
	while(T--) {
		cin >> a >> b;
		LL ret = 0;
		for(LL i = a; i <= b; i++) {
			ret += i * i * i;
		}
		cout << "Case #" << _++ << ": " << ret << endl;
	}
	return 0;
}
