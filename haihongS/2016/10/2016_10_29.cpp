#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=203;

struct II
{
    int x,y;
};

int n,m;
char a[maxn][maxn];
int bb[maxn][maxn];
vector<II> aha;

int zz[4][2][2];

int deal(int v);

int main()
{
    zz[0][0][0]=0,zz[0][0][1]=1;
    zz[0][1][0]=-1,zz[0][1][1]=0;

    zz[1][0][0]=0,zz[1][0][1]=1;
    zz[1][1][0]=1,zz[1][1][1]=0;

    zz[2][0][0]=0,zz[2][0][1]=-1;
    zz[2][1][0]=1,zz[2][1][1]=0;

    zz[3][0][0]=-1,zz[3][0][1]=0;
    zz[3][1][0]=0,zz[3][1][1]=-1;

    while(~scanf("%d%d",&n,&m) && n+m)
    {
        for(int i=0;i<n;i++)
            scanf("%s",a[i]);
        aha.clear();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='.')
                {
                    II now;
                    now.x=i,now.y=j;
                    aha.push_back(now);
                }
            }
        }

        int len=aha.size();
        if(len==0)
        {
            printf("0\n");continue;
        }
        int go=-1;
        for(int i=0;i<len;i++)
        {
                II now=aha[i];
                int x=now.x,y=now.y;
                for(int k1=0;k1<4;k1++)
                {
                    memset(bb,0,sizeof(bb));
                    int tf=1;
                    for(int k2=0;k2<2;k2++)
                    {
                        int nx=zz[k1][k2][0]+x;
                        int ny=zz[k1][k2][1]+y;
                        if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
                        if(a[nx][ny]=='#') 
                        {
                            tf=-1;
                            break;
                        }
                        bb[nx][ny]=2;
                    }
                    bb[x][y]=2;

					if(tf!=-1){
                    	int ans=deal(i);
                    	if(ans!=-1){
	                    	if(go==-1) go=ans+1;
	    	                else go=min(go,ans+1);
						}
					}
                    bb[x][y]=0;
                    for(int k2=0;k2<2;k2++)
                    {
                        int nx=zz[k1][k2][0]+x;
                        int ny=zz[k1][k2][1]+y;
                        if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
                        if(bb[nx][ny]==2)
                            bb[nx][ny]=0;
                    }
                }
        }
        printf("%d\n",go);

    }
    return 0;
}


int deal(int v)
{
    int len=aha.size();
    int ans=-1;
    for(int i=0;i<(1<<len);i++)
    {
        if(((1<<v)&i)==0)
            continue;
        int flag=1,cnt=0;
        for(int j=0;j<len;j++)
        {
            if(j==v) continue;
            if((i&(1<<j))!=0)
            {
                II now=aha[j];
                int x=now.x,y=now.y;
                if(bb[x][y]==0)
                    bb[x][y]=1;
                if(y+1<m && a[x][y+1]=='#')
                {
                    flag=-1;break;
                }
                if(y+1<m && bb[x][y+1]==0)
                    bb[x][y+1]=1;
                if(x-1>=0 && a[x-1][y]=='#')
                {
                    flag=-1;break;
                }
                if(x-1>=0 && bb[x-1][y]==0)
                    bb[x-1][y]=1;
                cnt++;
            }
        }
        for(int j=0;j<len;j++)
        {
            II now=aha[j];
            int x=now.x,y=now.y;
            if(bb[x][y]==0)
            {
                flag=-1;break;
            }
        }
        if(flag!=-1){
        	if(ans==-1) ans=cnt;
	        else ans=min(ans,cnt);
		}

        for(int j=0;j<len;j++)
        {
            if(j==v) continue;
            if((i&(1<<j))!=0)
            {
                II now=aha[j];
                int x=now.x,y=now.y;
                if(bb[x][y]==1) bb[x][y]=0;
                if(y+1<m && bb[x][y+1]==1) bb[x][y+1]=0;
                if(x-1>=0 && bb[x-1][y]==1) bb[x-1][y]=0;
            }
        }
    }
    return ans;
}
