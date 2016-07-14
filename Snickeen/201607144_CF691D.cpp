/*
    昨晚EDU CF 14 D题标程搞错，被cha爆
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef double db;
typedef long double ldb;
#define rep(i,a,b) for(i=a;i<b;i++)
#define repu(i,a,b) for(i=a;i<=b;i++)
#define repd(i,a,b) for(i=a;i>=b;i--)
#define FIN freopen("input.in","r",stdin)
#define FOUT freopen("output.out","w",stdout)
#define CC(a) memset(a,0,sizeof(a))
#define PB push_back
#define all(a) a.begin(),a.end()

template<typename T>inline void gn(T &x){
    x=0;T f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
    x*=f;
}
template<typename T>inline void gt(T x){
    if(!x)return;
    gt(x/10);putchar(x%10+'0');
}

const int N=1000005;
int t,n,m,cnt;
int MOD=1e9+7;
int a[N],f[N];
vector<int> G[N];

int find(int x){return f[x]==x ?x:f[x]=find(f[x]);}
void UN(int l,int r){int a=find(l),b=find(r);if(a!=b)f[a]=b;}

int main()
{
    //FIN;//FOUT;
    int i,j,k,l,r,x,y,z;
    rep(i,1,N)f[i]=i;
    gn(n);gn(m);
    repu(i,1,n)gn(a[i]); 
    repu(i,1,m){gn(l);gn(r);UN(l,r);}
    repu(i,1,n)G[find(i)].PB(a[i]);
    repu(i,1,n)sort(all(G[i]));
    repu(i,1,n){printf("%d ",G[f[i]].back()),G[f[i]].pop_back();}
    return 0;
}
