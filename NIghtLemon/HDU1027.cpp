#include<bits/stdc++.h>
using namespace std;
int a,b,i,j,cnt,s;
int c[1007];
int d[10];
int main()
{
    while(scanf("%d%d",&a,&b)!=EOF){
        b--;
        c[a]=c[a+1]=1;
        for(i=a-1;c[i+1]<b;i--) c[i]=c[i+1]*(a-i+1);
        s=i+1;
        for(i=1;i<s;i++) printf("%d ",i);
        for(i=s;i<=a;i++) d[i-s]=i;
        for(i=s;i<=a;i++){
            int ith=b/c[i+1];
            j=0;
            while(ith){
                if(d[j]!=0) ith--;
                j++;
            }
            while(d[j]==0) j++;
            printf("%d",d[j]);
            if(i!=a) printf(" ");
            d[j]=0;
            b%=c[i+1];
        }
        printf("\n");
    }
    return 0;
}
