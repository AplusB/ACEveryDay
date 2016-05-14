/*
    题意：两个人捡瓶子到固定点。关键地方是找到两个人一开始捡哪两个或一个瓶子。
	
    一开始ans初始化为1e9+7，结果WA在45，然后改成1e22+7后AC。后来将cin/cout改为scanf/printf时用1e10+7也AC。 
	
    以前打CF基本上只用bits/stdc++.h，这次没用，原来setprecision(12)需要包含头文件iomanip，记笔记记笔记。 
	
    先用cin和cout：     1669 ms	2200 KB
    后用scanf和printf： 156 ms	2200 KB
    
*/

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<iomanip>
#include<algorithm> 
#include<stdlib.h>
#include<math.h> 
#include<queue>
#include<stack>
#include<map>
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
struct TT{
    int a,b,dir;
};TT tt[1];
LL ff[11],dd[11],n,m,i,j,k,l;db t,s,r,mmax,mmin,num,ans,sa,sb;
LL MOD=1e9+7;
char aa[111];

int main(){
//  FIN;FOUT;
    db ax,ay,bx,by,cx,cy,x,y,z;
//  cin>>ax>>ay>>bx>>by>>cx>>cy>>n;
    scanf("%lf %lf %lf %lf %lf %lf %d",&ax,&ay,&bx,&by,&cx,&cy,&n);
    ans=1e10+7;
    while(n--){
//      cin>>x>>y;
        scanf("%lf %lf",&x,&y);
        r=hypot(ax-x,ay-y);
        s=hypot(bx-x,by-y);
        t=hypot(cx-x,cy-y);
        r-=t;s-=t;
        num+=t*2;
        ans=min(ans,sa+s);
        ans=min(ans,sb+r);
        sa=min(sa,r);
        sb=min(sb,s);
    }
//  cout<<fixed<<setprecision(12);
//  cout<<num+ans;
    printf("%.12lf\n",num+ans);
    return 0;
}
