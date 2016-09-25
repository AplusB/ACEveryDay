#include<bits/stdc++.h>
using namespace std;
#define LL long long 

const int N = 2;
const int mod = 1e9+7;

struct Martix{
    LL arr[N][N];
    Martix(int v = 0){
        memset(arr,0,sizeof(arr));
        arr[0][0] = arr[1][1] = v;
    }
};

Martix operator * (Martix L,Martix R){
    Martix ret;
    for(int i = 0;i < N;i++)
        for(int j = 0;j < N;j++)
            for(int k = 0;k < N;k++){
                (ret.arr[i][j] += L.arr[i][k] * R.arr[k][j]) %= mod;
            }
    return ret;
}

Martix operator + (Martix L,Martix R){
    Martix ret;
    for(int i = 0;i < N;i++)
        for(int j = 0;j < N;j++)
                (ret.arr[i][j] += L.arr[i][j] + R.arr[i][j]) %= mod;
    return ret;
}

bool operator == (Martix L,Martix R){
    for(int i = 0;i < N;i++)
        for(int j = 0;j < N;j++)
            if(L.arr[i][j] !=  R.arr[i][j]) return false; 
    return true;
}

Martix fir(){
    Martix ret;
    ret.arr[0][0] = 0,ret.arr[0][1] = 1;
    ret.arr[1][0] = 1,ret.arr[1][1] = 1;
    return ret;
}

Martix power(Martix x,LL n){
    Martix ret(1);
    while(n){
        if(n & 1) ret = ret * x;
        x = x * x;
        n >>= 1;
    }
    return ret;
}

#define root 1,1,n
#define lson o<<1,l,m
#define rson o<<1|1,m+1,r
#define Now int o,int l,int r
#define Mid int m = ( l + r ) >> 1

const int maxn = 112345;

Martix info[maxn * 4];
Martix lazy[maxn * 4];
int arr[maxn];

void segInit(Now){
    if(l == r){
        info[o] = power(fir(),arr[l]);
        return;
    }
    Mid;
    segInit(lson),segInit(rson);
    info[o] = info[o<<1] + info[o<<1|1];
    lazy[o] = Martix(1);
}

void seter(int o,Martix v){
    lazy[o] = lazy[o] * v;
    info[o] = info[o] * v;
}

void push_down(Now){
    if(l != r){
        seter(o<<1,lazy[o]);
        seter(o<<1|1,lazy[o]);
    }
    lazy[o] = Martix(1);
}

void update(Now,int ul,int ur,Martix x){
    if(ul <= l && r <= ur){
        seter(o,x);
        return;
    }
    Mid;
    if( !(lazy[o] == Martix(1)) ) push_down(o,l,r);
    if(ul <= m) update(lson,ul,ur,x);
    if(m+1<=ur) update(rson,ul,ur,x);
    info[o] = info[o<<1] + info[o<<1|1];
}

Martix query(Now,int ql,int qr){
    if(ql <= l && r <= qr){
        return info[o];
    }
    Mid;
    if( !(lazy[o] == Martix(1)) ) push_down(o,l,r);
    Martix ret;
    if(ql <= m) ret = ret + query(lson,ql,qr);
    if(m+1<=qr) ret = ret + query(rson,ql,qr);
    return ret;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    segInit(root);
    int ord,l,r,v;
    while(m--){
        scanf("%d %d %d",&ord,&l,&r);
        if(ord == 1){
            scanf("%d",&v);
            update(root,l,r,power(fir(),v));
        }
        else{
            printf("%I64d\n",query(root,l,r).arr[1][0] /*?*/);
        }
    }
    return 0;
}

            

