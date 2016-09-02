考虑到每一个线段只有一次进入答案的机会和离开答案的机会

用线段树求得每个线段进入答案和离开答案的时间

暴力计算即可

时间复杂度 $O(m \times log(n) + max(n,m))$

```cpp
#include<bits/stdc++.h>
using namespace std;

const int maxn = 212345;

int arr[maxn * 4];

#define root 1,1,n
#define lson o<<1,l,m
#define rson o<<1|1,m+1,r
#define Now int o,int l,int r
#define Mid int m = (l + r) >> 1;

void update(Now,int ul,int ur,int v){
    if(ul <= l && r <= ur){
        arr[o] = v;
        return;
    }
    Mid;
    if(arr[o] != -1){
        arr[o<<1] = arr[o<<1|1] = arr[o];
        arr[o] = -1;
    }
    if(ul <= m) update(lson,ul,ur,v);
    if(m+1<=ur) update(rson,ul,ur,v);
}

int query(Now,int pos){
    if(l == r){
        return arr[o];
    }
    if(arr[o] != -1) return arr[o];
    Mid;
    if(pos <= m) return query(lson,pos);
    else return query(rson,pos);
}

vector<int> in[maxn],out[maxn];
int L[maxn],R[maxn];
int v[maxn];

int main(){
    int n,m;
    while(~scanf("%d %d",&n,&m)){
        for(int i=0;i<=m+1;i++){
            in[i].clear();
            out[i].clear();
        }
        for(int i=1;i<n;i++) scanf("%d",&v[i]);
        for(int i=1;i<=m;i++){
            scanf("%d %d",&L[i],&R[i]);
            if(L[i] > R[i])
                swap(L[i],R[i]);
        }

        memset(arr,-1,sizeof(arr));
        for(int i=m;i>=1;i--){
            update(root,L[i],R[i]-1,i);
        }
        for(int i=1;i<n;i++){
            int tim = query(root,i);
            if(tim != -1){
                in[tim].push_back(i);
            }
        }

        memset(arr,-1,sizeof(arr));
        for(int i=1;i<=m;i++){
            update(root,L[i],R[i]-1,i);
        }
        for(int i=1;i<n;i++){
            int tim = query(root,i);
            if(tim != -1){
                out[tim].push_back(i);
            }
        }
        int ans = 0;
        for(int i=1;i<=m;i++){
            for(auto x : in[i])
                ans += v[x];
            printf("%d\n",ans);
            for(auto x : out[i])
                ans -= v[x];
        }
    }
    return 0;
}
```

