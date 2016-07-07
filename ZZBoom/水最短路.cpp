    poj1502
    #include<iostream>
    #include<cstdio>
    #include<string.h>
    #include<algorithm>
    using namespace std;
    #define INF 0x3f3f3f3f
    #define N 110

    int ma[N][N];
    int n;
    int dis[N];
    bool vis[N];

    void init()
    {
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==j)
                    ma[i][j]=0;
                else
                    ma[i][j]=INF;
            }
        }
    }

    void dijs()
    {
        for(int i=1;i<=n;i++)
        {
            dis[i]=ma[1][i];
            vis[i]=0;
        }
        vis[1]=1;
        int k;
        for(int i=1;i<=n;i++)
        {
            k=-1;
            int mimi=INF;
            for(int j=1;j<=n;j++)
            {
                if(!vis[j]&&mimi>dis[j])
                {
                    k=j;
                    mimi=dis[j];
                }
            }
            if(k==-1)
            break;
            vis[k]=1;
            for(int j=1;j<=n;j++)
            {
                if(!vis[j]&&dis[j]>dis[k]+ma[k][j])
                    dis[j]=dis[k]+ma[k][j];
            }
        }
        int Tmax=-1;
        for(int i=2;i<=n;i++)
        {
            if(dis[i]!=INF&&Tmax<dis[i])
            {
                Tmax=dis[i];
            }
        }
        printf("%d\n",Tmax);
    }

    int main()
    {
        while(~scanf("%d",&n))
        {
            char s[10];
            init();
            for(int i=2;i<=n;i++)
            {
                for(int j=1;j<i;j++)
                {
                    scanf("%s",s);
                    if(s[0]!='x')
                    {
                        ma[i][j]=ma[j][i]=atoi(s);//这个atoi还是不常用..以前都是手打...
                    }
                }
            }
            dijs();
        }
        return 0;
    } 
