#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <string>
#include <set>

using namespace std;


typedef struct P {
	int t, c;
}P;

bool cmp(P a, P b) {
	if(a.c == b.c) return a.t > b.t;
	return a.c < b.c;
}

class FarmvilleDiv2 {
public:
	int minTime(vector <int> tt, vector <int> cc, int budget) {
		const int maxn = 100010;
		int n = tt.size();
		P p[maxn];
		for(int i = 0; i < n; i++) {
			p[i].t = tt[i];
			p[i].c = cc[i];
		}
		sort(p, p+n, cmp);
		int ret = 0;
		for(int i = 0; i < n; i++) {
			while(budget >= p[i].c && p[i].t) {
				budget -= p[i].c;
				p[i].t--;
			}
		}
		for(int i = 0; i < n; i++) {
			ret += p[i].t;
		}
		return ret;
	}
};
