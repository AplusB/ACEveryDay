#include<bits/stdc++.h>
using namespace std;
double b[1024],x;
int t;
int main()
{
    int k1,k2;
    for(int i=0;i<1024;i++)
        b[i]=0;
    scanf("%d",&k1);
    for(int i=0;i<k1;i++)
    {
        scanf("%d%lf",&t,&x);
        b[t]+=x;
    }
    scanf("%d",&k1);
    for(int i=0;i<k1;i++)
    {
        scanf("%d%lf",&t,&x);
        b[t]+=x;
    }
    k2=0;
    for(int i=0;i<1024;i++)
        if(b[i]!=0) k2++;
    cout<<k2;
    for(int i=1000;i>=0;i--)
    {

        if(b[i]!=0)
        printf(" %d %.1f",i,b[i]);
    }
    printf("\n");
    return 0;
}
