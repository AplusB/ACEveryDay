#include<bits/stdc++.h>
using namespace std;

const int maxn = 212345;
#define LL long long 
LL INFF = 0x3f3f3f3f3f3f3f3fll;
LL v[maxn];
int tag[maxn], fa[maxn];
vector<pair<int,LL> > edge[maxn];
set<pair<LL,int> > S;

void dffs(int st,LL off){
    tag[fa[st]]++;
    S.insert(make_pair(-off,st));
    tag[S.upper_bound(make_pair(v[st] - off,maxn))->second]--;
    for(auto it : edge[st]) 
        dffs(it.first,it.second + off);
    S.erase(make_pair(-off,st));
}
void dfss(int st){
    for(auto it : edge[st]){
        dfss(it.first);
        tag[st] += tag[it.first];
    }
}
int main(){
    int n;
    int128_t o = 0;
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i ++) 
        scanf("%I64d",&v[i]);
    int p;
    LL l;
    fa[1] = 0;
    for(int i = 2; i <= n ; i ++){
        scanf("%d %I64d",&p,&l);
        edge[p].push_back(make_pair(i,l));
        fa[i] = p;
    }
    memset(tag,0,sizeof(tag));
    S.insert(make_pair(INFF,0));
    dffs(1,0); 
    dfss(1);
    for(int i = 1; i <= n; i ++) 
        printf(i<n?"%d ":"%d\n",tag[i]);
    return 0;
}
