#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll long long
int s1[3000000],s2[3000000];
struct node
{
    int l,r;
}a[1000000],b[1000000];
bool cmp(node a,node b)
{
    if(a.l==b.l) return a.r<b.r;
    return a.l<b.l;
}
int rr[3001000],cc[3001000],mark[3000000];
int main()
{
    int n;
    int t,cas=1;
    int sum1,sum2,x,y,z,zz,sum;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        sum1=sum2=sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d%d",&x,&y,&z,&zz);
            x+=1100001;
            y+=1100001;
            if(x+z<y-z) continue;
            if(zz==1) a[sum1].l=y-z,a[sum1++].r=x+z;
            else b[sum2].l=y-z,b[sum2++].r=x+z;
            mark[sum++]=y-z,mark[sum++]=x+z;
        }
        sort(mark,mark+sum);
        sum=unique(mark,mark+sum)-mark;
        printf("Case #%d:\n",cas++);
        sort(a,a+sum1,cmp);
        sort(b,b+sum2,cmp);
        for(int i=0;i<sum;i++)
        {
            int x=mark[i];
            rr[x]=0,cc[x]=0;
        }
        for(int i=0;i<sum1;i++)
        {
            rr[a[i].l]++;
            cc[a[i].r]++;
        }
        int res=0;
        for(int i=0;i<sum;i++)
        {
            int x=mark[i];
            res+=rr[x];
            s1[x]=res;
            res-=cc[x];
        }
        for(int i=0;i<sum;i++)
        {
            int x=mark[i];
            rr[x]=0,cc[x]=0;
        }
        for(int i=0;i<sum2;i++)
        {
            rr[b[i].l]++;
            cc[b[i].r]++;
        }
        res=0;
        for(int i=0;i<sum;i++)
        {
            int x=mark[i];
            res+=rr[x];
            s2[x]=res;
            res-=cc[x];
        }
        int ans=0;
        for(int i=sum-1;i>=0;i--)
        {
            int x=mark[i];
            if(i==sum-1) continue;
            s2[x]=max(s2[mark[i+1]],s2[x]);
        }
        for(int i=0;i<sum;i++)
        {
            int x=mark[i];
            ans=max(ans,s1[x]+s2[x]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
