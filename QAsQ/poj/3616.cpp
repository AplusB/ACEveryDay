#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<stack>
using namespace std;
#define LL long long

const int maxn = 1123;

int msp[maxn*2];
int dp[maxn*2];

struct Seg{
    int l,r,v;
};
Seg seg[maxn];
bool cmp(Seg a,Seg b){
    return a.r < b.r;
}

int main(){
    int n,m,r;
    while(~scanf("%d %d %d",&n,&m,&r)){
        int mlen = 0;
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&seg[i].l,&seg[i].r,&seg[i].v);
            msp[mlen++] = seg[i].l,msp[mlen++] = seg[i].r;
        }
        sort(msp,msp+mlen);
        mlen = unique(msp,msp+mlen) - msp;
        sort(seg,seg+m,cmp);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<m;i++){
            int lo = lower_bound(msp,msp+mlen,seg[i].r)-msp;
            int bef = 0;
            for(int j=0;msp[j]+r<=seg[i].l && j < mlen;j++){
                bef = max(bef,dp[j]);
            }
            dp[lo] = max(dp[lo],bef + seg[i].v);
        }
        printf("%d\n",*max_element(dp,dp+mlen));
    }
    return 0;
}
