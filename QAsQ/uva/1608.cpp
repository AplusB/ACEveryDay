#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define LL long long

const int maxn = 212345;

struct Node{
    int v,id;
    void init(int i){
        id = i;
        scanf("%d",&v);
    }
}node[maxn];

bool cmp(Node a,Node b){
    if(a.v != b.v)
        return a.v < b.v;
    return a.id < b.id;
}
int l[maxn],r[maxn];

inline bool in(int st,int ed,int id){
    return l[id]<st && ed<r[id];
}

bool judge(int st,int ed){
    if(st >= ed)
        return true;
    for(int i=0;i<=(ed-st)/2;i++){
        if(in(st,ed,st+i))
            return judge(st,st+i-1) && judge(st+i+1,ed);
        if(in(st,ed,ed-i))
            return judge(st,ed-i-1) && judge(ed-i+1,ed);
    }
    return false;
}

int main(){
    int T;
    scanf("%d",&T);
    int n;
    while(T-- && ~scanf("%d",&n)){
        for(int i=1;i<=n;i++){
            node[i-1].init(i);
        }
        sort(node,node+n,cmp);
        for(int i=0;i<n;i++){
            if(i==0 || node[i-1].v != node[i].v) l[node[i].id] = 0;
            else l[node[i].id] = node[i-1].id;
            if(i==n-1 || node[i].v != node[i+1].v) r[node[i].id] = n+1;
            else r[node[i].id] = node[i+1].id;
        }

        puts(judge(1,n)?"non-boring":"boring");
    }
    return 0;
}
