#include<bits/stdc++.h>
using namespace std;
const int N=200000+10;
int n,a[N],b[N],da[N][20],db[N][20];

void rmq_init()
{
    for(int i=0;i<=n;i++) da[i][0]=a[i];
    for(int j=1;(1<<j)<=n+1;j++)
        for(int i=0;i+(1<<j)-1<=n;i++)
            da[i][j]=max(da[i][j-1],da[i+(1<<(j-1))][j-1]);

    for(int i=0;i<=n;i++) db[i][0]=b[i];
    for(int j=1;(1<<j)<=n+1;j++)
        for(int i=0;i+(1<<j)-1<=n;i++)
            db[i][j]=min(db[i][j-1],db[i+(1<<(j-1))][j-1]);
}

int rmq_max(int L,int R)
{
    int k=0;
    while((1<<(k+1)) <=R-L+1) k++;
    return max(da[L][k],da[R-(1<<k)+1][k]);
}

int rmq_min(int L,int R)
{
    int k=0;
    while((1<<(k+1)) <=R-L+1) k++;
    return min(db[L][k],db[R-(1<<k)+1][k]);
}

int main()
{
    int L,R,M,t1,t2;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int j=0;j<n;j++)
        scanf("%d",b+j);
    a[n]=2e9;
    b[n]=-2e9;
    rmq_init();
    long long ans=0;
    /*
    printf("%d %d\n",rmq_max(3,4),rmq_min(3,4));
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
            printf("%d,%d:%d %d\n",i+1,j+1,rmq_min(i,j),rmq_max(i,j));
    */
    for(int i=0;i<n;i++)
    {
        if(a[i]>b[i]) continue;
        L=i;
        R=n;
        t1=-1;
        while(L<=R)
        {
            M=(R+L)/2;
            int mi=rmq_min(i,M);
            int mx=rmq_max(i,M);
            if(mi<mx)
            {
                t1=M;
                R=M-1;
            }
            else
            {
                L=M+1;
            }
        }

        L=i;
        R=n;
        t2=-1;
        while(L<=R)
        {
            M=(R+L)/2;
            int mi=rmq_min(i,M);
            int mx=rmq_max(i,M);
            if(mi<=mx)
            {
                t2=M;
                R=M-1;
            }
            else
            {
                L=M+1;
            }
        }
        //printf("%d %d %d\n",i,t1,t2);
        if(t1!=-1&&t2!=-1)
            ans+=t1-t2;
    }
    printf("%lld\n",ans);
    return 0;
}
