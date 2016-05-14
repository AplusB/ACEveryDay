#include<cstdio>
#include<cstring>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<bitset>
#include<set>
#include<queue>
#include<stack>
#include<map>
#include<cstdlib>
#include<cmath>
#define PI 2*asin(1.0)
#define LL long long
#define pb push_back
#define pa pair<int,int>
#define clr(a,b) memset(a,b,sizeof(a))
#define lson lr<<1,l,mid
#define rson lr<<1|1,mid+1,r
#define bug(x) printf("%d++++++++++++++++++++%d\n",x,x)
#define key_value ch[ch[root][1]][0]C:\Program Files\Git\bin
const LL  MOD = 1000000007;
const LL N = 1e5+15;
const int maxn = 1e6+15;
const int letter = 130;
const LL INF = 1e18;
const double pi=acos(-1.0);
const double eps=1e-10;
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int ax,ay,bx,by,tx,ty,n;
int x[N],y[N];
int vis[N];
long double ok(int x1,int y1,int x2,int y2){
    return sqrt(1.0*(x1-x2)*(x1-x2)+1.0*(y1-y2)*(y1-y2));
}
struct node{
    long double val;
    int id;
    bool operator <(const node &p)const{
        return val<p.val;
    }
}a[N],b[N];
int main(){
    scanf("%d%d%d%d%d%d",&ax,&ay,&bx,&by,&tx,&ty);
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d",x+i,y+i);
    for(int i=0;i<n;i++){
        a[i].val=ok(ax,ay,x[i],y[i])-ok(x[i],y[i],tx,ty);
        b[i].val=ok(bx,by,x[i],y[i])-ok(x[i],y[i],tx,ty);
        a[i].id=i;
        b[i].id=i;
    }
    sort(a,a+n);
    sort(b,b+n);
    long double sum=0;
    long double min1=INF;
        if(a[0].id!=b[0].id){
            vis[a[0].id]=vis[b[0].id]=1;
            sum=a[0].val+b[0].val;
        for(int i=0;i<n;i++){
                sum+=2.0*ok(x[i],y[i],tx,ty);
        }
        vis[a[0].id]=vis[b[0].id]=0;
        min1=sum;
        }
        if(a[1].id!=b[0].id){
        vis[a[1].id]=vis[b[0].id]=1;
        sum=a[1].val+b[0].val;
        for(int i=0;i<n;i++){
                sum+=2.0*ok(x[i],y[i],tx,ty);
        }
        vis[a[1].id]=vis[b[0].id]=0;
        min1=min(min1,sum);
        }
        if(a[0].id!=b[1].id){
        vis[a[0].id]=vis[b[1].id]=1;
        sum=a[0].val+b[1].val;
        for(int i=0;i<n;i++){
                sum+=2.0*ok(x[i],y[i],tx,ty);
        }
        vis[a[0].id]=vis[b[1].id]=0;
        min1=min(min1,sum);
        }
        if(a[1].id!=b[1].id){
        vis[a[1].id]=vis[b[1].id]=1;
        sum=a[1].val+b[1].val;
        for(int i=0;i<n;i++){
                sum+=2.0*ok(x[i],y[i],tx,ty);
        }
        vis[a[1].id]=vis[b[1].id]=0;
        min1=min(min1,sum);
        }
        sum=a[0].val;
        vis[a[0].id]=1;
        for(int i=0;i<n;i++){
            sum+=2.0*ok(x[i],y[i],tx,ty);
        }
        vis[a[0].id]=0;
        min1=min(min1,sum);
        sum=b[0].val;
        vis[b[0].id]=1;
        for(int i=0;i<n;i++){
            sum+=2.0*ok(x[i],y[i],tx,ty);
        }
        vis[b[0].id]=0;
        min1=min(min1,sum);
    printf("%.15f\n",(double)min1);
    return 0;
}
