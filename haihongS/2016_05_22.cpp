#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
typedef long long LL;
const int maxn=9000;

int num[maxn];
int m[maxn];
int f1[maxn*2],f2[maxn*2];
int r[maxn],l[maxn];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
            scanf("%d",&num[i]);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;
                if(num[j]<num[i]) m[j]=-1;
                else m[j]=1;
            }
            memset(f1,0,sizeof(f1));
            memset(f2,0,sizeof(f2));
            r[i]=0;
            for(int j=i+1;j<n;j++)
            {
                r[j]=r[j-1]+m[j];
                f1[r[j]+maxn]+=1;
            }
            l[i]=0;
            for(int j=i-1;j>=0;j--)
            {
                l[j]=l[j+1]+m[j];
                f2[l[j]+maxn]+=1;
            }
            int ans=0;
            ans+=1;
            ans+=f1[maxn]+f2[maxn];

            for(int j=0;j<maxn;j++)
                ans+=f1[j]*f2[2*maxn-j];
            for(int j=maxn+1;j<2*maxn;j++)
                ans+=f1[j]*f2[2*maxn-j];
            ans+=f1[maxn]*f2[maxn];

            if(i==0)
                printf("%d",ans);
            else
                printf(" %d",ans);
        }
        printf("\n");
    }
    return 0;
}
