#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#define CLEAR(A, X) memset(A, X, sizeof(A))
#define REP(N) for(int i=0; i<(N); i++)
#define REPE(N) for(int i=1; i<=(N); i++)
#define FREAD(FN) freopen((FN), "r", stdin)
#define pb(a) push_back(a)
#define pf() pop_front()
using namespace std;

const int MAX_N = 55;
const int MAX_P = 12;
const int INF = 1<<29;

int in[MAX_N][MAX_P];
int cap[MAX_N][MAX_N], flow[MAX_N][MAX_N];
int n;
queue<int> que;
int pre[MAX_N], a[MAX_N];

int EK(int s, int t){
	int f = 0;
	CLEAR(pre, 0);
	CLEAR(flow, 0);
	while(!que.empty()) que.pop();

	while(1){
		CLEAR(a, 0);
		a[s] = INF;
		que.push(s);
		while(!que.empty()){
			int u = que.front(); que.pop();
			REP(n){
				if(!a[i] && cap[u][i] > flow[u][i]){
					pre[i] = u;
					que.push(i);
					a[i] = min(a[u], cap[u][i] - flow[u][i]);//路径上最小的流量
				}
			}
		}
		if(a[t] == 0) break;//未找到增广路
		for(int u=t; u!=s; u = pre[u]){
			flow[pre[u]][u] += a[t];
			flow[u][pre[u]] -= a[t];
		}
		f += a[t];
	}
	return f;
}

struct Factory
{
	int cap;
	int in[MAX_P], out[MAX_P];
}fac[MAX_N];

int main()
{
	FREAD("3436.txt");
	int p;
	while(~scanf("%d%d", &p, &n)){
		CLEAR(cap, 0);
		CLEAR(fac, 0);
		REPE(n){//[1, n]
			scanf("%d", &fac[i].cap);
			for(int j=1; j<=p; j++)
				scanf("%d", &fac[i].in[j]);
			for(int j=1; j<=p; j++)
				scanf("%d", &fac[i].out[j]);
		}

		n += 2;//增加源点、汇点
		int s = 0, t = n-1;//0为源点, n-1为汇点
		REPE(p){//源点到所有点可达，所有点到汇点可达
			fac[0].in[i] = 0;
			fac[n-1].in[i] = 1;
			fac[n-1].out[i] = 1;
		}
		

		REP(n){
			for(int j=0; j<n; j++){
				if(i == j) continue;
				int flag = 1;
				//printf("i j %d %d\n", i, j );
				for(int k=1; k<=p; k++){
					//printf("%d %d %d\n", fac[j].in[k], fac[i].out[k], fac[j].in[k]);
					if(!((fac[j].in[k] == 2) || (fac[i].out[k] == fac[j].in[k]))) {//i->j不可达
						flag = 0;//i->j
					}
				}
				if(!flag) continue;
				if(i == s) cap[i][j] = fac[j].cap;//
				else if(j == t){
					cap[i][j] = fac[i].cap;
					//printf("add cap %d %d\n", i, fac[i].cap);
				}
				else cap[i][j] += min(fac[i].cap, fac[j].cap);
			}
		}

		// REP(n){
		// 	for(int j=0; j<=n+1; j++)
		// 		printf("%d ", cap[i][j]);
		// 	printf("\n");
		// }

		printf("%d ", EK(s, t));

		int cnt = 0;
		REPE(t-1){//不算源、汇点
			for(int j=s+1; j<=t-1; j++){
				if(flow[i][j] > 0) cnt++;
			}
		}
		printf("%d\n", cnt);

		REPE(t-1){
			for(int j=s+1; j<=t-1; j++){
				//printf("flow %d \n", flow[i][j]);
				if(flow[i][j] > 0){
					printf("%d %d %d\n", i, j, flow[i][j]);
				}
			}
		}
	}
	return 0;
}
