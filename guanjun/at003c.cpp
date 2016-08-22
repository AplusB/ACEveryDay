#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
 
 
int N;
int A[101010];
//-----------------------------------------------------------------
int main() {
	cin >> N;
	rep(i, 0, N) scanf("%d", &A[i]);
 
	map<int, int> cnt;
	rep(i, 0, N) if (i % 2 == 0) cnt[A[i]]++;
 
	sort(A, A + N);
	map<int, int> cnt2;
	rep(i, 0, N) if (i % 2 == 0) cnt2[A[i]]++;
 
	int ans = 0;
	for (auto p : cnt) {
		ans += abs(cnt2[p.first] - p.second);
	}
 
	cout << ans << endl;
}
