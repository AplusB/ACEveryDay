//hdoj1207

#include<stdio.h>
#include<math.h>
#define    M 99999999
typedef long long LL;
int f[66];
#define M 99999999
//F(n)=min(2*F(n-r)+2^r-1)，（1≤r≤n）。
//r=(sqrt(8*n+1)-1)/2
//F(n)=(n-(r^2-r+2)/2)*2^r+1
int main()
{
    int n;
    f[1]=1;
    f[2]=3;
    for(int i=3;i<=65;i++)
    {
        int min=M;
        for(int x=1;x<i;x++)  
            if(2*f[x]+pow(2,i-x)-1<min)
                min=2*f[x]+(int)pow(2,i-x)-1;  
            f[i]=min;
    }
    while(scanf("%d",&n)!=EOF)
        printf("%d\n",f[n]); 
    return 0; 
}
