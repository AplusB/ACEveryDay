#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int INF=1e4+10;
const int N=1e2+10;
int ma[N][N];

int main()
{
    int n,m,sum;
    int tmin;
    int i,j;
    int x,y;
    while(~scanf("%d%d",&n,&m))
    {
        tmin=INF;
        sum=0;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                scanf("%d",&ma[i][j]);
                sum+=ma[i][j];
                if(m%2==0 && n%2==0)
                {
                    if(i%2==0 && j%2!=0)
                    {
                        if(ma[i][j]<tmin)
                        {
                            tmin=ma[i][j];
                            x=i;
                            y=j;
                        }
                    }
                    if(i%2!=0 && j%2==0)
                    {
                        if(ma[i][j]<tmin)
                        {
                            tmin=ma[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }
            }
        }
        if(n%2!=0)
        {
            printf("%d\n",sum);
            for(i=1; i<=n; i++)
            {
                if(i%2!=0)
                {
                    for(j=1; j<=m-1; j++)
                        printf("R");
                }
                if(i%2==0)
                {
                    for(j=1; j<=m-1; j++)
                        printf("L");
                }
                if(i==n && j==m)
                    break;
                else
                    printf("D");
            }
        }
        else if(m%2!=0)
        {
            printf("%d\n",sum);
            for(i=1; i<=m; i++)
            {
                if(i%2!=0)
                {
                    for(j=1; j<=n-1; j++)
                        printf("D");
                }
                if(i%2==0)
                {
                    for(j=1; j<=n-1; j++)
                        printf("U");
                }
                if(i==m && j==n)
                    break;
                else
                    printf("R");
            }
        }
        else
        {
            printf("%d\n",sum-tmin);

            for(i=1; i<=n; i+=2)
            {
                if(x==i || x==i+1)
                {
                    //上下
                    for(j=1; j<y; j++)
                    {
                        if(j%2!=0)
                            printf("D");
                        else
                            printf("U");

                        printf("R");
                    }

                    if(y<m)
                        printf("R");

                    //上下
                    for(j=y+1; j<=m; j++)
                    {
                        if(j%2!=0)
                            printf("U");
                        else
                            printf("D");
                        if(j<m)
                            printf("R");
                    }
                    if(i<n-1)
                        printf("D");
                }
                else if(x<i)//左下右
                {
                    for(j=1; j<m; j++)
                        printf("L");
                    printf("D");
                    for(j=1; j<m; j++)
                        printf("R");

                    if(i<n-1)
                        printf("D");
                }
                else//右下左
                {
                    for(j=1; j<m; j++)
                        printf("R");
                    printf("D");
                    for(j=1; j<m; j++)
                        printf("L");

                    printf("D");
                }
            }
        }
        printf("\n");
    }
    return 0;
}


/*



4 4
5 5 5 5
1 5 5 5
5 5 5 5
5 5 5 5

4 4
5 1 5 5
5 5 5 5
5 5 5 5
5 5 5 5


*/
