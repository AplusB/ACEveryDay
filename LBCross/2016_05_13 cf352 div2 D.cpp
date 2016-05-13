#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include <ctime>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<iomanip>
#include<cmath>
#define mst(ss,b) memset((ss),(b),sizeof(ss))
#define maxn 0x3f3f3f3f
#define MAX 1000100
///#pragma comment(linker, "/STACK:102400000,102400000")
typedef long long ll;
typedef unsigned long long ull;
#define INF (1ll<<60)-1
using namespace std;
int n,k;
int a[500100];
ll solve1(int x){
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]<x) ans+=1LL*(x-a[i]);
    }
    return ans;
}
ll solve2(int x){
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]>x) ans+=1LL*(a[i]-x);
    }
    return ans;
}
int main(){
    scanf("%d%d",&n,&k);
    ll sum=0;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i];
    int l=1,r=1e9,mid,ans1=1,ans2=1;
    while(l<r){
        mid=(l+r)/2;
        if(solve1(mid)<=(ll)k) l=mid+1,ans1=mid;
        else r=mid;
    }
    l=1;r=1e9;
    while(l<r){
        mid=(l+r)/2;
        if(solve2(mid)<=(ll)k) r=mid,ans2=mid;
        else l=mid+1;
    }
    if(ans2-ans1>0) cout<<ans2-ans1<<endl;
    else printf("%d\n",sum%n==0?0:1);
    return 0;
}
