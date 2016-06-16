#include<vector>
#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
const int INF = 0x3f3f3f3f;

const int maxn = 105;

struct Dsu{
    int arr[maxn];
    void init(int n){
        for(int i=0;i<=n;i++){
            arr[i] = i;
        }
    }
    int fnd(int x){
        return arr[x]==x ? x : arr[x]=fnd(arr[x]);
    }
    void join(int x,int y){
        x = fnd(x);
        y = fnd(y);
        if(x != y)
            arr[x] = y;
    }
    bool check(int x,int y){
        return fnd(x)==fnd(y);
    }
}dsu[maxn];

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
        dsu[i].init(n);
    int u,v,c;
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&u,&v,&c);
        dsu[c].join(u,v);
    }
    int q;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&u,&v);
        int ans = 0;
        for(int i=1;i<=m;i++){
            ans += dsu[i].check(u,v);
        }
        printf("%d\n",ans);
    }
    return 0;
}
