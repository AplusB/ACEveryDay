#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long LL;
const int maxn = 200005;
#define lowbit(x) (x&(-x))
struct BIT{
	int sum[maxn], n;

	void init(int n){
		this->n = n;
		memset(sum, 0, sizeof sum);
	}

	void update(int x, int val){
		for(int i = x; i <= n; i += lowbit(i)){
			sum[i] += val;
		}
	}

	int query(int l, int r){
		int s = 0;
		for(int i = r; i; i -= lowbit(i)){
			s += sum[i];
		}
		for(int i = l - 1; i; i -= lowbit(i)){
			s -= sum[i];
		}
		return s;
	}

}gao1, gao2;
struct Point{
	int x, y;
	void read(){
		scanf("%d%d", &x, &y);
	}
}p[maxn];
vector < int > X;
vector < int > Y;
vector < int > px[maxn];
vector < int > ans[maxn];

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		if(!n) break;
		for(int i = 0; i < maxn; i++){
			px[i].clear();
			ans[i].clear();
		}
		X.clear();
		Y.clear();
		for(int i = 1; i <= n; i++){
			p[i].read();
			X.push_back(p[i].x);
			Y.push_back(p[i].y);
		}
		sort(X.begin(), X.end());
		sort(Y.begin(), Y.end());
		X.erase(unique(X.begin(), X.end()), X.end());
		Y.erase(unique(Y.begin(), Y.end()), Y.end());
		gao1.init(Y.size());
		gao2.init(Y.size());
		for(int i = 1; i <= n; i++){
			p[i].x = lower_bound(X.begin(), X.end(), p[i].x) - X.begin() + 1;
			p[i].y = lower_bound(Y.begin(), Y.end(), p[i].y) - Y.begin() + 1;
			px[p[i].x].push_back(p[i].y);
			gao2.update(p[i].y, 1);
		}
		int Stan = 0, Ollie = 0, res1, res2, tmp;
		for(int i = 1; i <= X.size(); i++){
			for(int j = 0; j < px[i].size(); j++){
				gao2.update(px[i][j], -1);
			}
			res1 = res2 = -1;
			for(int j = 0; j < px[i].size(); j++){
				tmp = gao1.query(px[i][j] + 1, Y.size()) + gao2.query(1, px[i][j] - 1);
				if(tmp > res2){
					res2 = tmp;
					res1 = gao1.query(1, px[i][j] - 1) + gao2.query(px[i][j] + 1, Y.size());
				}
			}
			ans[res1].push_back(res2);
			for(int j = 0; j < px[i].size(); j++){
				gao1.update(px[i][j], 1);
			}
		}
		for(int i = maxn - 1; i >= 0; i--){
			if(ans[i].size()){
				sort(ans[i].begin(), ans[i].end());
				ans[i].erase(unique(ans[i].begin(), ans[i].end()), ans[i].end());
				printf("Stan: %d; Ollie:", i);
				for(int j = 0; j < ans[i].size(); j++){
					printf(" %d", ans[i][j]);
				}
				puts(";");
				break;
			}
		}
	}
	return 0;
}
