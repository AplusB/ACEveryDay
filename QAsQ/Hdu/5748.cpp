#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 112345;
int arr[maxn],ans[maxn];
int msp[maxn],mlen;

int geter(int x){
    return lower_bound(msp,msp+mlen,x) - msp;
}

int bit[maxn];
int lowbit(int x){
    return x & (-x);
}
int maxer(int x){
    int ret = bit[x];
    while(x){
        x -= lowbit(x);
        ret = max(ret,bit[x]);
    }
    return ret;
}
void upd(int x,int v){
    while(x < maxn){
        bit[x] = max(bit[x],v);
        x += lowbit(x);
    }
}
int main(){
    int T;
    scanf("%d",&T);
    int n;
    while(T-- && ~scanf("%d",&n)){
        mlen = 0;
        for(int i=1;i<=n;i++){
            scanf("%d",&arr[i]);
            msp[mlen++] = arr[i];
        }
        msp[mlen++] = 0;
        sort(msp,msp+mlen);
        mlen = unique(msp,msp+mlen)-msp;
        memset(bit,0,sizeof(bit));
        for(int i=1;i<=n;i++){
            int p = geter(arr[i]);
            ans[i] = maxer(p-1)+1;
            upd(p,ans[i]);
        }
        for(int i=1;i<=n;i++){
            printf(i<n?"%d ":"%d\n",ans[i]);
        }
    }
    return 0;
}
