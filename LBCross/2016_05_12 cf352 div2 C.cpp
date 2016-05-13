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
struct point{
    long double x,y,dis;
    int id;
}s[100100],p[100100];
int vis[100100];
const long double eps=1e-8;
int dcmp(long double x){
    if(fabs(x)<=eps) return 0;
    return x<0?-1:1;
}
long double disn(point a,point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool cmp(point a,point b){
    return dcmp(a.dis-b.dis)>0;
}
int n;
int main(){
    point A,B,C;
    cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) cin>>s[i].x>>s[i].y;
    long double ans1=0,ans2=0,ans3=0,mx1=-INF*1.0,mx2=mx1,ans=0,mx_1=mx1,mx_2=mx1;
    for(int i=1;i<=n;i++) ans+=disn(s[i],C)*2;
    int tmp1=-1,tmp2=-1;
    for(int i=1;i<=n;i++){
        long double d1=disn(A,s[i]);
        long double d2=disn(C,s[i]);
        long double d3=d2-d1;
        if(dcmp(d3-mx1)>=0){
            if(dcmp(mx1-mx_1)>=0) mx_1=mx1;
            mx1=d3;
            tmp1=i;
        } else if(dcmp(d3-mx_1)>=0){
            mx_1=d3;
        }
    }
    ans1=ans-mx1;
    for(int i=1;i<=n;i++){
        long double d1=disn(B,s[i]);
        long double d2=disn(C,s[i]);
        long double d3=d2-d1;
        if(dcmp(d3-mx2)>=0){
            if(dcmp(mx2-mx_2)>=0) mx_2=mx2;
            mx2=d3;
            tmp2=i;
        } else if(dcmp(d3-mx_2)>=0){
            mx_2=d3;
        }
    }
    ans2=ans-mx2;
    /*cout<<tmp1<<" "<<tmp2<<endl;
    cout<<setprecision(20)<<ans<<endl;
    cout<<setprecision(20)<<ans1<<endl;
    cout<<setprecision(20)<<ans2<<endl;
    cout<<setprecision(20)<<mx1<<endl;
    cout<<setprecision(20)<<mx_1<<endl;
    cout<<setprecision(20)<<mx2<<endl;
    cout<<setprecision(20)<<mx_2<<endl;*/
    if(tmp1!=tmp2) ans3=ans-mx1-mx2;
    else {
        if(dcmp(mx1+mx_2-mx2-mx_1)>=0){
            ans3=ans-mx1-mx_2;
        } else ans3=ans-mx_1-mx2;
    }
    long double anw=INF*1.0;
    anw=min(anw,ans1);
    anw=min(anw,ans2);
    anw=min(anw,ans3);
    cout<<setprecision(20)<<anw<<endl;
    return 0;
}
/*
0 2
2 1
1 1
1
1 0
*/
