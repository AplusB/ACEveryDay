#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int MAX_N = 1005;

int parent[MAX_N];

void init(){
	memset(parent, -1, sizeof(parent));
}
int find(int x){
	if(parent[x] == -1)
		return x;
	return parent[x] = find(parent[x]);
}
void unite(int x, int y){
	int rx = find(x);
	int ry = find(y);
	if(rx == ry) return ; //注意加这句，因为自反是用-1而不是自身表示 
	parent[ry] = rx;
}
bool same(int x, int y){
	return find(x) == find(y);
}

struct Point
{
	double x, y;
}com[MAX_N];

double dis(Point p1, Point p2){
	return sqrt(pow(p1.x-p2.x, 2) + pow(p1.y-p2.y, 2));
}

int N, d;
double distance[MAX_N][MAX_N];
bool repaired[MAX_N];

int main()
{
	freopen("2236.txt", "r", stdin);
	memset(repaired, 0, sizeof(repaired));
	scanf("%d%d", &N, &d);
	for(int i=1; i<=N; i++){
		scanf("%lf%lf", &com[i].x, &com[i].y);
	}

	for(int i=1; i<=N; i++){
		for(int j=1; j<i; j++){
			distance[i][j] = distance[j][i] = dis(com[i], com[j]);
		}
		distance[i][i] = 0;
	}
	
	init();
	getchar();
	char op;
	while((op=getchar())!=EOF){
		//printf("%c", op);
		switch(op){
			case 'O':
				int n;
				scanf("%d", &n);
				repaired[n] = 1;
				//printf(" %d\n", n);
				for(int i=1; i<=N; i++){
					if(i==n) continue;//注意加这句 
					if(repaired[i] && distance[i][n] <= d)
						unite(n, i);
				}
				break;
			case 'S':
				int x, y;
				scanf("%d%d", &x, &y);
				//printf("S %d %d\n", x, y);
				printf("%s\n", same(x, y) ? "SUCCESS" : "FAIL");
				
		}
		getchar();
	}
	return 0;
}
