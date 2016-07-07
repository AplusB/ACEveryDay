#include<bits/stdc++.h>
using namespace std;
int g[100][100],a[1024],b[1024];
char s[100];
int dx[]={-3,-2,-1,0,1,2,3};
int dy[]={-3,-2,-1,0,1,2,3};
int ok(int x,int y)
{
    if(x<0||y<0) return 0;
    if(g[x][y]==-1) return 0;
    return 1;
}

void init()
{
    memset(g,0xff,sizeof(g));
    g[0][0]=1;g[0][1]=2;g[0][2]=3;
    g[1][0]=4;g[1][1]=5;g[1][2]=6;
    g[2][0]=7;g[2][1]=8;g[2][2]=9;
    g[3][1]=0;
}

int getx(int k)
{
    if(k==0) return 3;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(g[i][j]==k)
                return i;
        }
    }
}

int gety(int k)
{
    if(k==0) return 1;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(g[i][j]==k)
                return j;
        }
    }
}

int main()
{
    int n,x,y;
    scanf("%d",&n);
    scanf("%s",s);
    init();
    for(int i=0;i<n;i++)
    {
        int k=s[i]-'0';
        a[i]=getx(k);
        b[i]=gety(k);
        //printf("%d %d\n",a[i],b[i]);
    }
    int f=0;
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<7;j++)
        {
            if(dx[i]==0&&dy[j]==0) continue;
            int k;
            for(k=0;k<n;k++)
            {
                x=a[k]+dx[i];
                y=b[k]+dy[j];
                if(ok(x,y)==0) break;
            }
            if(k==n)
            {
                //printf("%d %d\n",dx[i],dy[j]);
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    return 0;
}
