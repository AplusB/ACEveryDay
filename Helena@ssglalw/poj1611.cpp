#include <cstdio>
#include <cstring>
using namespace std;
const int MAX_N = 30005;

int parent[MAX_N];
int num[MAX_N];

void init(){
	memset(parent, -1, sizeof(parent));
	for(int i=0; i<MAX_N; i++){
		num[i] = 1;
	}
}

int find(int x){
	if(parent[x] == -1)
		return x;
	return parent[x] = find(parent[x]);
}

void unite(int x, int y){
	int rx = find(x);
	int ry = find(y);
	if(rx == ry) return ;
	num[rx] += num[ry];
	parent[ry] = rx;
}

int n, m;

int main()
{
	freopen("1611.txt", "r", stdin);
	while(~scanf("%d%d", &n, &m)){
		if(n==0 && m==0) break;
		init();
		for(int i=0; i<m; i++){
			int k;
			int a, b;
			scanf("%d", &k);
			scanf("%d", &a);
			for(int j=1; j<k; j++){
				scanf("%d", &b);
				unite(a, b);
			}
		}
		printf("%d\n", num[find(0)]);
	}
	return 0;
}
