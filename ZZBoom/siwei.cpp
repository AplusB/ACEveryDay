//hdoj2796

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const double eps=1e-6;
const double pi=acos(-1.0);
const int mod=998244353;
const int INF=0x3f3f3f3f;

const int N=55;

int a[N];
bool vis[N];

int main()
{
    int n,i,xx,sum,flag,num,flat;
    while(~scanf("%d",&n))
    {
        memset(vis,0,sizeof(vis));
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        sum=0;
        xx=1;
        flag=0;
        while(1)
        {
            flat=0;
            num=0;
            for(i=0; i<n; i++)
            {
                if(!vis[i])
                {
                    if(num+1==xx)
                    {
                        if(a[i]>flag)
                        {
                            flag=a[i];
                            vis[i]=1;
                            num++;
                            flat=1;

                            sum++;
                            break;
                        }
                    }
                    else if(num+1<xx)
                    {
                        flag=max(flag,a[i]);
                        vis[i]=1;
                        num++;
                        flat=1;
                    }
                }
            }
            if(!flat)
                break;
            else{
                xx++;
            }
        }
        cout<<sum<<endl;
    }

}


