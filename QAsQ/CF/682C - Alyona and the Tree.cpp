#include<cstdio>
#include<set>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
#define LL long long 

const int maxn = 112345;

vector<pair<int,LL> >edge[maxn];

void Link(int st,int ed,LL v){
    edge[st].push_back(make_pair(ed,v));
}

LL val[maxn];
multiset<LL> S;
bool vis[maxn];

void outS(){
    for(auto v : S){
        cout<<v<<" ";
    }
    cout<<endl;
}

void dffs(int st,LL offset){
    if(st!=1 && *S.rbegin()+offset > val[st]){
        vis[st] = true;
        return;
    }
    S.insert(-offset);
    for(auto x: edge[st]){
        dffs(x.first,x.second+offset);
    }
    S.erase(S.find(-offset));
}

int cnt(int st){
    if(vis[st]) return 0;
    int ret = 1;
    for(auto x:edge[st]){
        ret += cnt(x.first);
    }
    return ret;
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    int x;
    LL v;
    for(int i=2;i<=n;i++){
        cin>>x>>v;
        Link(x,i,v);
    }
    memset(vis,0,sizeof(vis)); 
    dffs(1,0);
    cout<<n-cnt(1)<<endl;
    return 0;
} 
