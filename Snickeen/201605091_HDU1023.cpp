/*
    //卡特兰数应用，出栈问题
	//h(n)=h(n-1)*(4*n-2)/(n+1)
    
	//向kuangbin学习，关于卡特兰数小总结 http://www.cnblogs.com/kuangbin/archive/2012/03/21/2410516.html
    //打表，倒着存，第n个存在a[n]中，a[n][0]是位数 
*/

#include<stdio.h>
int a[111][111],k,n;

void catalan()
{
    int i,j,t,yu,len;
    a[2][0]=a[1][0]=a[0][0]=1;
    a[2][1]=2;
    a[1][1]=a[0][1]=len=1;
    for(i=3;i<=105;i++){
        yu=0;
        for(j=1;j<=len;j++){
            t=a[i-1][j]*(4*i-2)+yu;
            yu=t/10;
            a[i][j]=t%10;
        }
        while(yu){
            a[i][++len]=yu%10;
            yu/=10;
        }
        for(j=len;j;j--){
            t=a[i][j]+yu*10;
            a[i][j]=t/(i+1);
            yu=t%(i+1);
        }
        while(!a[i][len])len--;
        a[i][0]=len;
    }
}

int main()
{
    catalan();
    while(~scanf("%d",&n)){
        for(k=a[n][0];k;k--)printf("%d",a[n][k]);
        puts("");
    }
    return 0;
}
