#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define rep(i,a,b) for(i=a;i<b;i++)
#define repu(i,a,b) for(i=a;i<=b;i++)
#define repd(i,a,b) for(i=a;i>=b;i--)
#define db double
#define ld long double
#define FIN  freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)
#define CC(a) memset(a,0,sizeof(a))

template<typename T>inline void gn(T &xx){
    xx=0;T xf=1;char xch=getchar();
    while(!isdigit(xch)){if(xch=='-')xf=-1;xch=getchar();}
    while(isdigit(xch)){xx=xx*10+xch-'0';xch=getchar();}
    xx*=xf;
}

struct TT{
    int a,b;
};TT tt[5],ss,rr;
int n,m,t,s,r,l,mmax,mmin,num,ans;
LL MOD=1e9+7,mod;
int n7[66],m7[66],nm[66],vis[11],bo[11];
queue<TT> q;

int get(int x){
    int i,j,k;
    repu(i,1,n7[0]){
        k=x%7;
        if(vis[k])return 0;
        else vis[k]=1;
        x/=7;
    }
    return 1;
}
int check(int x){
    CC(bo);int i,j,k;
    repu(i,1,m7[0]){
        k=x%7;
        if(vis[k]||bo[k])return 0;
        else bo[k]=1;
        x/=7;
    }
    return 1;
}

int main(){
    int i,j,k;
    scanf("%d %d",&n,&m);
    n--;m--;
    if(n<7){n7[++n7[0]]=n;}
    else while(n){
        n7[++n7[0]]=n%7;
        n/=7;
    }
    if(m<7){m7[++m7[0]]=m;}
    else while(m){
        m7[++m7[0]]=m%7;
        m/=7;
    }
    if(n7[0]+m7[0]>7)return 0*puts("0");
    repd(i,n7[0],1)r=r*7+n7[i];
    repd(i,m7[0],1)s=s*7+m7[i];
    repu(i,0,r){
        CC(vis);
        k=get(i);
        if(k==0)continue;
        repu(j,0,s){
            if(j==i)continue;
            k=check(j);
            ans+=k;
        }
    }
    printf("%d\n",ans);
    return 0;
}
