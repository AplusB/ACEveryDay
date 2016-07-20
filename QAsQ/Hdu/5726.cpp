#include<bits/stdc++.h>
using namespace std;

#define LL long long 

const int maxn = 112345;

int arr[maxn];

map<int,LL> M;
map<int,int> seg,tseg;


void init(int n){
    M.clear();
    seg.clear(),tseg.clear();
    for(int st = n;st >= 1;st--){
        tseg.clear();
        for(auto x : seg){
            int gcd = x.first;
            tseg[__gcd(arr[st],gcd)]+=x.second;
        }
        seg = tseg;
        seg[arr[st]]++; 
        for(auto x : seg){
            M[x.first] += x.second;
        }
    }
}

int info[maxn*4];

#define root 1,1,n
#define lson o<<1,l,m
#define rson o<<1|1,m+1,r
#define Now int o,int l,int r
#define Mid int m = (l + r) / 2;

void init(Now){
    if(l == r){
        info[o] = arr[l];
        return;
    }
    Mid;
    init(lson),init(rson);
    info[o] = __gcd(info[o<<1],info[o<<1|1]);
}

int ql,qr,n;

int query(Now){
    if(ql <= l && r <= qr){
        return info[o];
    }
    Mid;
    int al = -1,ar = -1;
    if(ql <= m) al = query(lson);
    if(m+1<=qr) ar = query(rson);
    if(al == -1) return ar;
    if(ar == -1) return al;
    return __gcd(al,ar);
}

int query(int l,int r){
    ql = l,qr = r;
    return query(root);
}
int main(){
    int T,icase = 1;
    scanf("%d",&T);
    while(T-- && ~scanf("%d",&n)){
        for(int i=1;i<=n;i++){
            scanf("%d",&arr[i]);
        }
        init(n);
        init(root);
        int m,l,r;
        printf("Case #%d:",icase++);
        scanf("%d",&m);
        while(m--){
            scanf("%d %d",&l,&r);
            int ans = query(l,r);
            printf("%d %I64d\n",ans,M[ans]);
        }
    }
    return 0;
}

