#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
//#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef double db;
typedef long double ldb;
#define rep(i,a,b) for(i=a;i<b;i++)
#define repu(i,a,b) for(i=a;i<=b;i++)
#define repd(i,a,b) for(i=a;i>=b;i--)
#define FIN freopen("input.in","r",stdin)
#define FOUT freopen("output.out","w",stdout)
#define CC(a) memset(a,0,sizeof(a))
#define PB push_back
#define all(x) (x).begin(),(x).end()

template<typename T>inline void gn(T &x){
	x=0;T f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
template<typename T>inline void gt(T x){
	if(!x)return;
	gt(x/10);putchar(x%10+'0');
}

int t,n,m,cas;
LL MOD=1e9+7;
char a[10000007];
int num[11];

int main()
{
//	FIN;FOUT;
    int i,j,k,l,tmp;
    scanf("%d",&cas);
    while(cas--){
        CC(num);CC(a);
        scanf("%s",&a);
        l=strlen(a);
        rep(i,0,l)num[a[i]-'0']++;
        n=0;
        repu(i,1,9)n+=num[i];
        repu(i,1,9)if(num[i]){tmp=i;num[i]--;break;}
        //repu(i,0,9)printf("%d %d \n",i,num[i]);
        if(n<2){
            puts("Uncertain");
        }
        else {
            n+=num[0];k=0;
            repd(i,9,0){
                repu(j,1,num[i])
                    a[++k]=i;
            }
            m=tmp;a[0]=0;
            //printf("%d %d %d %d\n",m,k,a[k-1],a[k]);
            repd(i,k,0){
                if(m==0)break;
                a[i]+=m;
                m=a[i]/10;
                a[i]%=10;
            }
            //repu(i,0,k)printf("%d %d %d\n",m,i,a[i]);
            repu(i,0,k)a[i]+='0';
            if(a[0]!='0')puts(a);
            else puts(a+1);
        }
    }

	return 0;
}
