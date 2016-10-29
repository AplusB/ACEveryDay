#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define N 100010
int t[2*N], n;
vector<double> ans;

void calc() {
	double cur_sum = 0.0;
	int before = 0;
	for (int i = 2*n-1; i >= 0; i--) {
		if (t[i] < 0) {
			before++;
			double mult = 1.0 / before;
			cur_sum = mult * (-t[i]) + (1.0 - mult) * cur_sum;
		} else {
			before--;
			ans.push_back(cur_sum - t[i]);
		}
	}
	reverse(ans.begin(), ans.end());
	//cerr << ans.size() << endl;
	
}

int main() {
	scanf("%d", &n);
	for (int i=0; i<2*n; i++) {
		char s[10];
		scanf("%s%d", s, t+i);
		if (s[0] == '-') t[i] = -t[i];
	}
	calc();
	for (double i: ans) printf("%.6lf\n", i);
	return 0;
}
