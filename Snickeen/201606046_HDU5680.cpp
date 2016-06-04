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
int ff[11],dd[11],n,m,i,j,k,l,t,s,r,mmax,mmin,num,ans;
LL MOD=1e9+7;
char aa[111];
int main(){
//    FIN;FOUT;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&m);k=0;
        while(m--)scanf("%d",&j),k=max(k,j);
        printf("%d\n",k);
    }
    return 0;
}
