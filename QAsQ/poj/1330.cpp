#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 112345,maxm = 112345,max_log = 17;
const int ROOT = 1;
int deep[maxn],fa[maxn][max_log];
int nofa[maxn];

struct Edge{
    struct Node{
        int nex,to;
        Node(int nex=0,int to=0):nex(nex),to(to){};
    };
    Node node[maxm];
    int head[maxn],top;
    void init(){
        memset(head,-1,sizeof(head));
        top = 0;
    }
    void Link(int st,int ed){
        node[top] = Node(head[st],ed);
        head[st] = top++;
    }
    int Start(int st){ return head[st]; }
    void Next(int &st){ st = node[st].nex; }
    int To(int st){ return node[st].to; }
}edge;

int getroot(int n){
    for(int i=1;i<=n;i++){
        if(nofa[i] == -1) return i;
    }
    return -1;
}

void dfs(int st,int Fa,int Deep=1){
    for(int i=1;i<max_log;i++)
        fa[st][i] = -1;
    fa[st][0] = Fa,deep[st] = Deep;
    for(int i = edge.Start(st);i != -1;edge.Next(i)){ 
        if(edge.To(i) == Fa) continue;
        dfs(edge.To(i),st,Deep+1);
    }
}
void init(int n){
    memset(fa,-1,sizeof(fa));
    dfs(getroot(n),-1);
	for (int j = 1;j < max_log;j++){
		for (int i = 1;i <= n;i++){
			if (fa[i][j-1] != -1){
				fa[i][j] = fa[fa[i][j-1]][j-1];
			}
        }
    }
}

int lca(int x,int y){
	if (deep[x] < deep[y]) swap(x,y);
	for (int i = max_log-1;i >= 0;i--){
		if (deep[fa[x][i]] >= deep[y]){
			x = fa[x][i];
		}
    }
	if (x == y) return x; 
	for (int i = max_log-1;i >= 0;i--){
		if (fa[x][i] != fa[y][i]){
            x = fa[x][i]; 
            y = fa[y][i];
		}
    }
	return fa[x][0];
}

int main(){
    int T;
    scanf("%d",&T);
    int n;
    while(T-- && ~scanf("%d",&n)){
        edge.init();
        int u,v;
        memset(nofa,-1,sizeof(nofa));
        for(int i=1;i<n;i++){
            scanf("%d %d",&u,&v);
            edge.Link(u,v);
            edge.Link(v,u);
            nofa[v] = 0;
        }
        init(n);
        scanf("%d %d",&u,&v);
        printf("%d\n",lca(u,v));
    }
    return 0;
}

