#include<cstring>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 1123;

vector<int> edge[maxn];

void init(){
    for(int i=0;i<maxn;i++){
        edge[i].clear();
    }
}

int suc[maxn],fai[maxn],siz[maxn];
bool hav[maxn];

bool cmper(int x,int y){
    return (fai[x] + 2) * siz[y] < (fai[y] + 2) * siz[x];
}

void dfs(int st){
    siz[st] = edge[st].size()==0;
    for(vector<int>::iterator it = edge[st].begin();it != edge[st].end();it++){
        int x = *it;
        dfs(x);
        siz[st] += siz[x];
    }
    sort(edge[st].begin(),edge[st].end(),cmper);
    suc[st] = fai[st] = 0;
    for(vector<int>::iterator it = edge[st].begin();it != edge[st].end();it++){
        int x = *it;
        suc[st] += (fai[st]+1)*siz[x] + suc[x];
        fai[st] += fai[x] + 2;
    }
    if(hav[st]) fai[st] = 0;
}

int main(){
    int n;
    while(~scanf("%d",&n) && n){
        char in[3];
        int fa;
        init();
        for(int i=1;i<=n;i++){
            scanf("%d %s",&fa,in);
            if(fa != -1) edge[fa].push_back(i);
            hav[i] = *in == 'Y';
        }
        dfs(1);
        printf("%.4f\n",suc[1]*1.0/siz[1]);
    }
    return 0;
}

