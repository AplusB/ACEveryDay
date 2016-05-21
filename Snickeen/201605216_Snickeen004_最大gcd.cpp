/*
    n个数，从中选2个数做gcd（最大公约数）最大能是几？
    输入n（2<=n<=100000），接下来是n个数（1<=每个数<=100000）。
    输出任取两个能得到的最大公约数。
    
*/
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<queue>
#include<map>
using namespace std;
#define CC(a) memset(a,0,sizeof(a))
typedef long long LL;

int ff[100111],dd[100111],hh[100111],t,s,r,n,m,i,j,k,l,mmin,mmax,num,ans;

void check(int x){
    //int kk=(int)sqrt(x);
    for(j=1;j*j<x;j++){
        if(x%j==0){
            hh[j]++;hh[x/j]++;
        }
    }
    if(j*j==x)hh[j]++;
}

int main()
{
    while(~scanf("%d",&n)){
        ans=1;m=0;mmax=1;
        CC(ff);CC(dd);CC(hh);
        for(i=1;i<=n;i++){
            scanf("%d",&ff[i]);
            check(ff[i]);
            m=max(m,ff[i]);
        }
        for(i=m;i;i--){
            if(hh[i]>1){
                mmax=i;break;
            }
        }
        printf("%d\n",mmax);
    }
    return 0;
} 
