#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long

const int maxn = 11234;

struct node{
    int pos,oper;
    void init(int P,int O){
        pos = P;
        oper = O;
    }
};

bool cmp(node a,node b){
    if(a.pos != b.pos)
        return a.pos < b.pos;
    return a.oper > b.oper;
}

node arr[maxn*2],brr[maxn*2];
int av[maxn*2],bv[maxn];
int ama[maxn*2],bma[maxn*2];
int apos[maxn*2],bpos[maxn*2];

int caler(node *rr,int *ma,int *pos,int *v,int n){
    sort(rr,rr+n,cmp);
    int tem = 0,len = 1;
    ma[0] = 0;
    pos[0] = rr[0].pos-1;
    for(int i=0;i<n;i++){
        if(i!=0 && rr[i].pos != rr[i-1].pos){
            v[len] = tem;
            pos[len] = rr[i].pos;
            len++;
        }
        tem+=rr[i].oper;
    }
    if(n){
        v[len] = tem;
        pos[len] = rr[n-1].pos;
        len++;
    }
    for(int i=1;i<len;i++){
        ma[i] = max(ma[i-1],v[i]);
    }
    return len;
}

void out(int *s,int n   ){
    for(int i=0;i<n;i++)
        printf(i<n-1?"%d ":"%d\n",s[i]);
}

int main(){
    int n;
    int icase = 1;
    int T;
    scanf("%d",&T);
    while(T-- && ~scanf("%d",&n)){
        int alen = 0,blen = 0;
        int x,y,z,d;
        while(n--){
            scanf("%d %d %d %d",&x,&y,&z,&d);
            int r = x+z,l = y-z;
            if(d==1){
                if(l<=r){
                    arr[alen++].init(l,1);
                    arr[alen++].init(r+1,-1);
                }
            }
            else{
                if(l<=r){
                    brr[blen++].init(l,1);
                    brr[blen++].init(r+1,-1);
                }
            }
        }
        int an = caler(arr,ama,apos,av,alen);
        int bn = caler(brr,bma,bpos,bv,blen);
        int ans = max(ama[an-1],bma[bn-1]);
        for(int i=1;i<bn;i++){
            int st = upper_bound(apos,apos+an,bpos[i])-apos-1;
            if(st == -1) continue;
            ans = max(ans,bv[i]+ama[st]);
        }
        printf("Case #%d:\n%d\n",icase++,ans);
    }
    return 0;
}
