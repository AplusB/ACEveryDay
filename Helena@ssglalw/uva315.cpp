#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
const int MAX_N = 105;
struct Edge{
    int u, v;
};

int n;
int clock;
int cnt;
vector<int> G[MAX_N+1];
int pre[MAX_N];
int is_cut[MAX_N];
stack<Edge> S;

void init(){
	cnt = 0;
	clock = 0;
	for(int i=0; i<=MAX_N; i++) G[i].clear();
	memset(pre, 0, sizeof(pre));
	memset(is_cut, 0, sizeof(is_cut));
	while(!S.empty()) S.pop();

}

int bcc(int u, int p){
    int lowu = pre[u] = ++clock;
    int child = 0;
    for(int i=0; i<G[u].size(); i++){
        int v = G[u][i];
        Edge e = (Edge){u, v};
        if(!pre[v]){//dis->undis，树边
            S.push(e);//把树边u->v推入栈
            child++;
            int lowv = bcc(v, u);
            lowu = min(lowu, lowv);
            if(lowv >= pre[u]){//v子树不存在后向边
                is_cut[u] = 1;//u为关节点
                //printf("%d\n", u);
               	for(; ;){
               		Edge x = S.top();
					S.pop();
					if(x.u == u && x.v == v) break;
				}
            }
        }else if(pre[v] < pre[u] && v!=p){//dis->dis，后向边
            S.push(e);
            lowu = min(lowu, pre[v]);
        }
    }
    if(p==0 && child == 1) is_cut[u] = 0;
    return lowu;
}

int main()
{
    freopen("315.txt", "r", stdin);
	while(~scanf("%d", &n) && n){
        init();
        int u, v;
        char c;
        while(~scanf("%d", &u) && u){
            while(~scanf("%d%c", &v, &c)){
                G[u].push_back(v);
				G[v].push_back(u);
				if(c == '\n') break;
            }
        }
/*
		for(int i=1; i<=n; i++){
            printf("%d: ", i);
            for(int j=0; j<G[i].size(); j++){
                printf("%d ", G[i][j]);
            }
            printf("\n");
		}
*/
		for(int i=1; i<=n; i++){
            if(!pre[i]){
                //printf("start %d\n", i);
                bcc(i, 0);
            }
		}
		int cnt = 0;
		for(int i=1; i<=n; i++){
            //printf("%d\n", is_cut[i]);
			if(is_cut[i]) cnt++;
		}
		printf("%d\n", cnt);

	}
	return 0;
}
