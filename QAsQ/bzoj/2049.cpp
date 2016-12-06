#include<bits/stdc++.h>
using namespace std;

const int maxn = 212345;

int fa[maxn],fval[maxn];
void init(int n){
    for(int i = 0 ; i <= n ; i ++)
        fa[i] = i,fval[i] = 0;
}

int fnd(int x){
    while(x != fa[x]){ 
        x = fa[x];
    }
    return x;
}

stack<pair<int*,int> >S;
int join(int x,int y){
    x = fnd(x), y = fnd(y);
    if(x == y) return 0;
    int ret = 0;
    if(fval[x] <= fval[y]){
        S.push(make_pair(&fa[x],fa[x]));
        fa[x] = y;
        ret++;
        if(fval[x] == fval[y]){
            S.push(make_pair(&fval[y],fval[y]));
            fval[y]++;
            ret++;
        }
    }
    else{
        S.push(make_pair(&fa[y],fa[y]));
        fa[y] = x;
        ret++;
    }
    return ret;
}

void redo(){
    *S.top().first = S.top().second;
    S.pop();
}


#define root 1,1,m
#define lson o<<1,l,m
#define rson o<<1|1,m+1,r
#define Now int o,int l,int r
#define Mid int m = (l + r) / 2

vector<pair<int,int> > edge[maxn * 4];
void ins(Now,int il,int ir,pair<int,int> lik){
    if(il <= l && r <= ir){
        edge[o].push_back(lik);
        return;
    }
    Mid;
    if(il <= m) ins(lson,il,ir,lik);
    if(m+1<=ir) ins(rson,il,ir,lik);
}

int tim[maxn * 4];
bool wrk[maxn];
int ql[maxn],qr[maxn];

void dfs(Now,int n){
    tim[o] = 0;
    for(vector<pair<int,int> >::iterator it = edge[o].begin(); it != edge[o].end();it++){
        tim[o] += join(it->first,it->second);
    }
    if(l == r){
        if(wrk[l]) {
            puts(fnd(ql[l]) == fnd(qr[l]) ? "Yes":"No");
        }
    }
    else{
        Mid;
        dfs(lson,n);
        dfs(rson,n);
    }
    while(tim[o]--){ 
        redo();
    }
}

map<pair<int,int>,int> M;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    char ord[10];
    int x,y;
    for(int i = 1 ; i <= m ; i ++){
        scanf("%s %d %d",ord,&x,&y);
        if(*ord == 'Q'){
            wrk[i] = true;
            ql[i] = x,qr[i] = y;
        }
        else{
            wrk[i] = false;
            if(x > y) swap(x,y);
            int & tim = M[make_pair(x,y)];
            if(*ord == 'C'){
                tim = i;
            }
            else{
                ins(root,tim,i-1,make_pair(x,y));
                M.erase(make_pair(x,y));
            }
        }
    }
    for(map<pair<int,int>,int>::iterator it = M.begin();it != M.end();it++)
        ins(root,it->second,m,it->first);
    init(n);
    dfs(root,n);
    return 0;
}
