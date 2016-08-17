#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;
const int N=10000+10;
const int M=1e5+10;
const int inf=1e9;
int to[M],w[M],to2[M],ne[M],ne2[M],h[N],h2[N],in[N],now[N],dis[N],dp[N];

int main()
{
    int _,u,v,c,cnt,t,n,m;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        memset(h,0xff,sizeof(h));
        memset(h2,0xff,sizeof(h2));
        memset(in,0,sizeof(in));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&c);
            to[i]=v;w[i]=c;ne[i]=h[u];h[u]=i;
            to2[i]=u;ne2[i]=h2[v];h2[v]=i;
            in[u]++;
        }
        queue<int>q;
        cnt=0;
        for(int i=0;i<n;i++)
        {
            if(in[i]==0) q.push(i);
        }
        while(!q.empty())
        {

            t=q.front();
            q.pop();
            now[cnt]=t;
            cnt++;
            for(int i=h2[t];i!=-1;i=ne2[i])
            {
                in[to2[i]]--;
                if(in[to2[i]]==0) q.push(to2[i]);
            }
        }
        for(int i=0;i<n;i++)
        {
            dp[i]=dis[i]=inf;
        }
        dis[n-1]=0;
        dp[n-1]=0;
        for(int i=0;i<n;i++)
        {
            u=now[i];
            int tmp1,tmp2,tmp3,tmp;
            tmp1=tmp2=tmp3=inf;
            tmp=inf;
            for(int j=h[u];j!=-1;j=ne[j])
            {
                v=to[j];
                c=w[j];
                tmp=min(tmp,dis[v]+c);
                tmp1=min(tmp1,dp[v]+c);
                if(tmp2>dis[v]+c)
                {
                    tmp3=tmp2;
                    tmp2=dis[v]+c;
                }
                else if(tmp3>dis[v]+c)
                {
                    tmp3=dis[v]+c;
                }
                /*
                tmp1=min(tmp1,dis[v]+c);
                if(tmp2>dp[v]+c)
                {
                    tmp3=tmp2;
                    tmp2=dp[v]+c;
                }
                else if(tmp3>dp[v]+c)
                {
                    tmp3=dp[v]+c;
                }
                */
            }
            dis[u]=min(dis[u],tmp);
            dp[u]=max(tmp1,tmp3);
            if(u==n-1) dp[u]=0;
            //printf("%d %d %d %d %d\n",u,dis[u],dp[u],tmp1,tmp3);
        }
        if(dp[0]==inf) dp[0]=-1;
        printf("%d\n",dp[0]);
    }
    return 0;
}
