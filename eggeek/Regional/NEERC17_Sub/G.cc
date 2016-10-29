#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int graph[128][128];
vi tour;

void find_tour(int u, int n) {
	for (int v = 0; v < n; ++v)
		while (graph[u][v]) {
			graph[u][v]--;
			find_tour(v, n);
		}
	tour.push_back(u);
}

int main() {
	int n;
	cin >> n;
	memset(+graph, 0, sizeof(graph));
	for (int i = 0; i < n; ++i)
	for (int j = 0; j < n; ++j)
		if (i != j)
			graph[i][j]++;
	
	find_tour(0, n);
	printf("1 1 0\n");
	int prev = 1;
	for (int i = 1; i < (int)tour.size()-1; ++i) {
		int p = tour[i] + 1;
		printf("%d %d %d\n", p, p, prev);
		prev = p;
	}
	printf("0 1 %d\n", prev);
	return 0;
}
