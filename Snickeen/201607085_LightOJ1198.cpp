/*
    田忌赛马，贪心。
*/
#include<stdio.h>
#include<algorithm>
using namespace std;

int t,ca=0,n;
int main()
{
    scanf("%d",&t);
    while(t--){
        int i,j,k,l,a[55]={0},b[55]={0},res=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        for(i=1;i<=n;i++)scanf("%d",&b[i]);
        sort(a+1,a+1+n);
        sort(b+1,b+1+n);
        for(i=1;i<=n;i++){
            for(j=n;j;j--){
                if(b[j]==-1)continue;
                if(a[i]>b[j])break;
            }
            if(j==0)continue;
            res+=2;
            a[i]=b[j]=-1;
        }
        for(i=1;i<=n;i++){
            if(a[i]==-1)continue;
            for(j=1;j<=n;j++){
                if(b[j]==-1)continue;
                if(a[i]==b[j]){
                    res++;
                    a[i]=b[j]=-1;
                }
            }
        }
        printf("Case %d: %d\n",++ca,res);
    }
    return 0;
 } 
