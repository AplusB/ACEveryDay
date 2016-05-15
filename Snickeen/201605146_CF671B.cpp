/*
    想了好久才有二分的思路，结果还没写出来，还是太弱
	
    学习，换个思路翻转两次，solve掉 
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
LL ff[500011],n,m,i,j,k,l,t,s,r,mmax,mmin,num,ans;
LL MOD=1e9+7;

/*
int bs(LL ak,LL left,LL right){
    LL sum;
    while(left<right){
        LL mid=left+(right-left)/2;
        sum=0;
        repu(i,1,n)sum+=max(0LL,mid-ff[i]);
        if(sum>ak)right=mid;
        else left=mid+1;
    }
//  mmin=sum;
//  printf("%I64d %I64d-\n",left,right);
    return right;
}
int bs2(LL ak,LL left,LL right){
    LL sum;
    while(left<right){
        LL mid=left+(right-left)/2;
        sum=0;
        repu(i,1,n)sum+=max(0LL,ff[i]-mid);
        if(sum>ak)left=mid+1;
        else right=mid;
    }
//  mmax=sum;
//  printf("%I64d %I64d--\n",left,right);
    return right;
}

void bssolve(){
    r=bs(k,1,1e9+7);
    s=bs2(k,r,1e9+7);
//  printf("%I64d %I64d %I64d %I64d\n",r,s,mmin,mmax);
    ans=s-r;
    if(r==s&&num%n)ans++;
}
*/

void solve(){
    sort(ff+1,ff+n+1);t=k;m=ff[1];
    repu(i,2,n){
        r=(ff[i]-m)*(i-1);
        if(r<=t)t-=r;
        else break;
        m=ff[i];
    }
    j=i-1;
    r=t/j;s=t%j;
    repu(i,1,j)ff[i]=m+r+(i<=s);
    repu(i,1,n)ff[i]=-ff[i];
}

int main(){
//  FIN;FOUT;
    scanf("%I64d%I64d",&n,&k);
    repu(i,1,n)scanf("%I64d",&ff[i]),num+=ff[i];
    solve();solve();
    sort(ff+1,ff+n+1);ans=ff[n]-ff[1];
//  bssolve();//二分写搓WA 
    printf("%I64d\n",ans);
    return 0;
}

