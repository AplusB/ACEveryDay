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
const LL N = 3e5+15;
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
int n,a[N],ps[N],cnt=0,w[N];
vector<int>pp;
struct node{
    int l,r;
    bool operator <(const node &p)const{
        return r<p.r;
    }
}e[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i),ps[++cnt]=a[i];
    sort(ps+1,ps+cnt+1);
    cnt=unique(ps+1,ps+cnt+1)-(ps+1);
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(ps+1,ps+cnt+1,a[i])-ps;
    int num=0;
    for(int i=1;i<=n;i++){
        if(w[a[i]]) e[++num].l=w[a[i]],e[num].r=i;
        w[a[i]]=i;
    }
    sort(e+1,e+num+1);
    int vs=0,max1=0;
    for(int i=1;i<=num;i++){
        if(e[i].l>max1){
            vs++;
            pp.pb(i);
            max1=e[i].r;
        }
    }
    if(!vs) puts("-1");
    else {
        for(int i=0;i<pp.size();i++){
            if(i==0) e[pp[i]].l=1;
            if(i==pp.size()-1) e[pp[i]].r=n;

        }
        printf("%d\n",vs);
        for(int i=0;i<pp.size();i++){
            if(i==0) printf("%d %d\n",1,e[pp[i]].r);
            else printf("%d %d\n",e[pp[i-1]].r+1,e[pp[i]].r);
        }
    }
    return 0;
}
