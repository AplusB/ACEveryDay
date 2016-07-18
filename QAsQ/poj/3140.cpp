#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

#define LL long long 
const int maxn = 112345;
vector<int> edge[maxn];

void init(int n){
    for(int i=0;i<=n;i++){
        edge[i].clear();
    }
}

LL Abs(LL x){
    return x < 0 ? -x : x;
}
LL val[maxn];
LL sval[maxn];

LL all;

LL dfs(int st,int fa){
    sval[st] = val[st];
    LL ret = all;
    for(vector<int>::iterator it = edge[st].begin();it != edge[st].end();it++){
        int x = *it;
        if(x == fa) continue;
        ret = min(dfs(x,st),ret);
        sval[st] += sval[x];
        ret = min(ret,Abs(all-2*sval[x]));
    }
    return ret;
}

int main(){
    int n,m;
    int icase = 1;
    while(~scanf("%d %d",&n,&m) && (n||m)){
        init(n);
        int l,r;
        all = 0;
        for(int i=1;i<=n;i++){
            scanf("%lld",&val[i]);
            all += val[i];
        }
        while(m--){
            scanf("%d %d",&l,&r);
            edge[r].push_back(l);
            edge[l].push_back(r);
        }
        printf("Case %d: %lld\n",icase++,dfs(1,0));
    }
    return 0;
}
