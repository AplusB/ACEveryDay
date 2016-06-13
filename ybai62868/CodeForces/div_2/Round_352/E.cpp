# include <stdio.h>
# include <string.h>
# include <algorithm>
# include <math.h>
# include <vector>
using namespace std;
typedef long long LL;
const int N = 2e5+5;
int mat[N],n,mx,tmp,lz[N<<2],a[N<<2];
LL c[N<<2],sum,h[N];
vector<int>v[N];
void build(int rt,int l,int r){
    if(l==r){
        a[rt]=c[rt]=1ll*l;
        return;
    }
    int m=(l+r)>>1;
    build(rt<<1,l,m);
    build(rt<<1|1,m+1,r);
    c[rt]=c[rt<<1]+c[rt<<1|1];
    a[rt]=min(a[rt<<1],a[rt<<1|1]);
}
void down(int rt,int l,int r){
   if(!lz[rt])return;
   int m=(l+r)>>1;
   c[rt<<1]=1ll*lz[rt]*(m-l+1);
   c[rt<<1|1]=1ll*lz[rt]*(r-m);
   a[rt<<1]=a[rt<<1|1]=a[rt];
   lz[rt<<1]=lz[rt<<1|1]=lz[rt];
   lz[rt]=0; 
}
void modify(int rt,int l,int r,int x,int y){
   if(x<=l&&r<=y){
     c[rt]=1ll*tmp*(r-l+1);
     a[rt]=lz[rt]=tmp;
     return;
   }
   down(rt,l,r);
   int m=(l+r)>>1;
   if(x<=m)modify(rt<<1,l,m,x,y);
   if(y>m)modify(rt<<1|1,m+1,r,x,y);
   c[rt]=c[rt<<1]+c[rt<<1|1];
   a[rt]=min(a[rt<<1],a[rt<<1|1]); 
}
int ask(int rt,int l,int r,int k){
    if(l==r)return l;
    int m=(l+r)>>1;
    if(a[rt<<1|1]<k)ask(rt<<1|1,m+1,r,k);
    else ask(rt<<1,l,m,k);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
      int x;scanf("%d",&x);
      mat[x]=i;mx=max(mx,x);
    }
    for(int i=1;i<=mx;++i){
      for(int j=i;j<=mx;j+=i)
        if(mat[j])
        v[i].push_back(mat[j]);  
    }
    for(int i=1;i<=mx;++i)
    if(v[i].size())sort(v[i].begin(),v[i].end());
    build(1,1,n);
    sum=1ll*n*(n+1);
    for(int i=mx;i>=0;--i){
      h[i]=sum-c[1];

      int k=v[i].size();
      if(k<2)continue;
      tmp=n+1;
      if(v[i][1]+1<=n){
          modify(1,1,n,v[i][1]+1,n);
      }
      tmp=v[i][k-1];
      if(a[1]<tmp){
        int pos=ask(1,1,n,tmp);
        pos=min(pos,v[i][1]);
        if(pos>v[i][0])
        modify(1,1,n,v[i][0]+1,pos);
      }
      tmp=v[i][k-2];
      if(a[1]<tmp){
        int pos=ask(1,1,n,tmp);
        pos=min(pos,v[i][0]);
        if(pos>0)
        modify(1,1,n,1,pos);
      }
    }
    LL ans=0;
    for(int i=1;i<=mx;++i)
        ans+=1ll*i*(h[i]-h[i-1]);
    printf("%I64d\n",ans);
    return 0;
}
