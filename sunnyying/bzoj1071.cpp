    #include <stdio.h>
    #include <string.h>
    #include <iostream>
    #include <algorithm>
    #include <vector>
    #include <queue>
    #include <set>
    #include <map>
    #include <string>
    #include <math.h>
    #include <stdlib.h>
    #define N 1250010
    #define INF 0x3f3f3f3f
    #define endl '\n'
    #define ll long long
    #define mod 1000000007
    using namespace std;
    struct node
    {
        ll h,v,s;
    }a[5010],b[5010];
    bool cmp1(node a,node b)
    {
        return a.h<b.h;
    }
    bool cmp2(node a,node b)
    {
        return a.s<b.s;
    }
    int mmax,mmin;
    int fl(int x)
    {
        return a[x].v>=mmin&&a[x].v<=mmax;
    }
    int fr(int x)
    {
        return b[x].v>=mmin&&b[x].v<=mmax;
    }
    int main()
    {
       // freopen("in.in","r",stdin);
       // freopen("out.out","w",stdout);
        ll A,B,C,n;
        scanf("%lld%lld%lld%lld",&n,&A,&B,&C);
        for(int i=0;i<n;i++)
        {
            scanf("%lld%lld",&a[i].h,&a[i].v);
            a[i].s=A*a[i].h+B*a[i].v;b[i]=a[i];
        }
        sort(a,a+n,cmp1);
        sort(b,b+n,cmp2);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            mmin=a[i].v,mmax=mmin+C/B;
            int sum=0,l=-1,r=-1;
            for(int j=0;j<n;j++)
            {
                while(r<n-1&&b[r+1].s<=mmin*B+a[j].h*A+C) r++,sum+=fr(r);
                while(l<n-1&&a[l+1].h<a[j].h) l++,sum-=fl(l);
                ans=max(ans,sum);
            }
        }
        cout<<ans<<endl;
        return 0;
    }
