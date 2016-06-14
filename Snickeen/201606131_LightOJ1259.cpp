/*
    题意：每个大于2的数都可以表示成两个素数和，给定n询问有多少种表示方式
	
	题解：筛素数，暴力枚举素数进行验证 
	
	关键点：筛素数卡内存，全用int会MLE，用bool可以，bitset自然也行；
	        枚举2-n/2会TLE，2s时限恰好卡住，读入优化都不行
			枚举筛出来的素数，判断差是否为素数，AC，不用读入优化也行
	
	github上，本code弱在201606131commit过，但是201606142发现cpp文件没有了，于是重新补交一份 
*/
#include<stdio.h>
#include<bitset>
using namespace std;
typedef long long LL;
 
template<typename T>inline void gn(T &x){
    x=0;T f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
    x*=f;
}
 
struct TT{
    int a,b;
};TT tt[11];
int ff[1000007],n,m,i,j,k,l,t,s,r,mmax,mmin,num,ans;
bitset<10000007> ch;
 
int main(){
   
    ch[1]=ch[0]=1;
    for(i=2;i<10000002;i++){
        if(!ch[i]){
            ff[++ff[0]]=i;
        }
        for(j=1;j<=ff[0]&&(i*ff[j]<10000002);j++){
            ch[ff[j]*i]=1;
            if(i%ff[j]==0)break;
        }
    }
   
    gn(t);int cas=0;
    while(t--){
        gn(n);ans=0;
        s=n/2;
        for(i=1;i<=ff[0]&&ff[i]<=s;i+=1){
            if((!ch[n-ff[i]]))ans++;
        }
        if(n==4)ans=1;
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}
