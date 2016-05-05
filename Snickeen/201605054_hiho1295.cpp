//练习一下欧拉线性筛质数
#include<stdio.h>
#define N 1000000+3
int n,i,j;
int pri[N],pn[N/10];
int main(){
    for(i=2;i<N;i++){
        if(!pri[i]) pn[++pn[0]]=i;
        for(j=1;(j<=pn[0])&&(pn[j]*i<=N);j++){
            pri[pn[j]*i]=1;
            if(i%pn[j]==0)break;
        }
	}
	pri[0]=pri[1]=1;
	for(i=2;i<N;i++)pri[i]=pri[i]+pri[i-1];
	scanf("%d",&n);
	printf("%d\n",n-pri[n]);
    return 0;
}
