#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define x first
#define y second

class FenwickTree {
public:
	FenwickTree(int n) : N(n), tree(n,0) {
	}

	void inc(int idx, int val) {
		do tree[idx] += val; while (idx && (idx += (idx & (-idx))) < N);
	}

	int sum(int idx) const {
		int s = tree[0];
		for ( ; idx > 0; idx &= idx-1) s += tree[idx];
		return s;
	}

private:
	int N; vi tree;
};

int main()
{
	int cases;
	cin >> cases;

	while (cases-- > 0)
	{
		int N, M;
		cin >> N >> M;
		int T = N + M;
#define REV(i) (T - (i) - 1)
		FenwickTree ft(T+1);
		for (int i = 0; i < N; ++i)
			ft.inc(REV(i), 1);

		vi mov(N);
		iota(mov.rbegin(), mov.rend(), 0);
		for (int i = 0, id = N; i < M; ++i, ++id)
		{
			int v; cin >> v; --v;

			printf("%d%c", ft.sum(REV(mov[v])) - 1, i+1==M ? '\n' : ' ');
			ft.inc(REV(mov[v]), -1);
			ft.inc(REV(id), 1);
			mov[v] = id;
		}
	}
	return 0;
}
