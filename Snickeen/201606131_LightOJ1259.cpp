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
