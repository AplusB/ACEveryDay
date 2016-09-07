#include<bits/stdc++.h>
using namespace std;

const int maxn = 512345,mlen = 26;
#define LL long long 

LL ans;
LL dp[maxn*2],siz[maxn*2];
vector<pair<int,int> >edge[maxn*2];
void Link(int st,int ed,int v){
    edge[st].push_back(make_pair(ed,v));
    edge[ed].push_back(make_pair(st,v));
}

struct Sam{
    int len[maxn*2],fa[maxn*2],nex[maxn*2][mlen];
    int val[maxn*2];
    int _cnt,root,omg;
    int newNode(int L = 0){
        len[_cnt] = L;
        memset(nex[_cnt],fa[_cnt] = -1,sizeof(nex[_cnt]));
        return _cnt++;
    }
    void init(){
        _cnt = 0;
        memset(val,0,sizeof(val));
        root = omg = newNode();
    }
    void extend(int x){
        int ox = newNode(len[omg]+1);
        val[ox]++;
        while(omg != -1 && nex[omg][x] == -1){
            nex[omg][x] = ox;
            omg = fa[omg];
        }
        if(omg == -1) fa[ox] = root;
        else{
            int omgx = nex[omg][x];
            if(len[omgx] == len[omg]+1) fa[ox] = omgx;
            else{
                int mgx = newNode(len[omg]+1);
                for(int i=0;i<mlen;i++)
                    nex[mgx][i] = nex[omgx][i];
                fa[mgx] = fa[omgx];
                fa[omgx] = fa[ox] = mgx;
                while(omg != -1 && nex[omg][x] == omgx)
                    nex[omg][x] = mgx,omg = fa[omg];
            }
        }
        omg = ox;
    }
    void build(char *arr){
        init();
        for(int i=0;arr[i];i++){
            extend(arr[i] - 'a');
        }
    }
    void treeBuild(){
        for(int i=0;i<_cnt;i++){
            edge[i].clear();
            dp[i] = 0 , siz[i] = val[i];
        }
        for(int i=0;i<_cnt;i++){
            if(fa[i] != -1){
                Link(i,fa[i],len[i] - len[fa[i]]);
            }
        }
    }
}SAM;

char arr[maxn];

void dfs(int st,int fa = -1){
    for(vector<pair<int,int> >::iterator it = edge[st].begin();it != edge[st].end();it++){
        pair<int,int> x = *it;
        if(x.first == fa) continue;
        dfs(x.first,st);
        ans += dp[st] * siz[x.first] + (dp[x.first] + siz[x.first] * x.second) * siz[st];
        dp[st] += dp[x.first] + siz[x.first] * x.second; 
        siz[st] += siz[x.first];
    }
}

int main(){
    scanf("%s",arr);
    int len = strlen(arr);
    reverse(arr,arr+len);
    SAM.build(arr);
    SAM.treeBuild();
    ans = 0;
    dfs(SAM.root);
    printf("%lld\n",ans);
    return 0;
}

