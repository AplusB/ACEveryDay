/*
    一开始只加了math.h结果CE了，不是很懂怎么回事，后来加了个stdlib和algorithm才AC
    水题签到防踢，最近事情有点儿多:(
*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int t,n,m,i,j,k;

int main()
{
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d%d",&n,&m);
        k=abs(n-m)*4+3+5+3+4*n+3+5;
        printf("Case %d: %d\n",i,k);
    }
    return 0;
}
