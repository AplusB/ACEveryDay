#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 222222

int lrec[MAXN],rrec[MAXN];

int tree[MAXN<<2],N,x,y;
void update(int i,int j,int k){
    if(i==j){
        tree[k]=y;
        return;
    }
    int mid=i+j>>1;
    if(x<=mid) update(i,mid,k<<1);
    else update(mid+1,j,k<<1|1);
    tree[k]=max(tree[k<<1],tree[k<<1|1]);
}
int query(int i,int j,int k){
    if(x>y) return 0;
    if(x<=i && j<=y){
        return tree[k];
    }
    int mid=i+j>>1,res=0;
    if(x<=mid) res=max(res,query(i,mid,k<<1));
    if(y>mid) res=max(res,query(mid+1,j,k<<1|1));
    return res;
}

int seq[MAXN];
int main(){
    int n,q,a,b;
    while(~scanf("%d",&n) && n){
        scanf("%d",&q);
        for(int i=1; i<=n; ++i){
            scanf("%d",seq+i);
        }
        seq[n+1]=111111;

        int rn=0;
        lrec[0]=1;
        for(int i=1; i<=n+1; ++i){
            if(seq[i]!=seq[i+1]){
                rrec[rn]=i;
                rn++;
                lrec[rn]=i+1;
            }
        }

        memset(tree,0,sizeof(tree));
        for(N=1; N<rn; N<<=1);
        for(int i=0; i<rn; ++i){
            x=i; y=rrec[i]-lrec[i]+1;
            update(0,N-1,1);
        }

        int i,j,res;
        while(q--){
            scanf("%d%d",&a,&b);
            i=lower_bound(rrec,rrec+rn,a)-rrec;
            j=upper_bound(lrec,lrec+rn,b)-lrec-1;
            if(rrec[i]>=b){
                printf("%d\n",b-a+1);
                continue;
            }
            res=max(rrec[i]-a+1,b-lrec[j]+1);
            x=i+1; y=j-1;
            res=max(res,query(0,N-1,1));
            printf("%d\n",res);
        }
    }
    return 0;
}
