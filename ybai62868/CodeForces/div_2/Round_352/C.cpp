# include <cstdio>
# include <iostream>
# include <cmath>
using namespace std;
# define MAX 112345
# define inf 1e19
double disa[MAX],disb[MAX],dis[MAX];
double cal( double x1,double y1, double x2, double y2 )
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main(void)
{
    double a,b,c,d,e,f,n; cin>>a>>b>>c>>d>>e>>f>>n;
    double sum = 0;
    for ( int i = 0;i < n;i++ )
    {
        double x,y; cin>>x>>y;
        disa[i] = cal(a,b,x,y);
        disb[i] = cal(c,d,x,y);
        dis[i] = cal(x,y,e,f);
        sum+=dis[i];
    }
    sum*=2.0;
    double ans = 0.0;
    double ans1, ans2;
    ans1 = ans2 = inf;
    for ( int i = 0;i < n;i++ )
    {
        ans1 = min(ans1,disa[i]-dis[i]);
        ans2 = min(ans2,disb[i]-dis[i]);
    }
    ans = min(ans1,ans2)+sum;
    int pos1 = -1, pos2 = -1;
    ans1 = ans2 = inf;
    for ( int i = 0;i < n;i++ )
    {
        if ( disa[i]-dis[i] < ans1 )
        {
            ans1 = disa[i]-dis[i];
            pos1 = i;
        }
    }
    for ( int i = 0;i < n;i++ )
    {
        if ( (disb[i]-dis[i] < ans2)&&(i!=pos1) )
        {
            ans2 = disb[i]-dis[i];
            pos2 = i;
        }
    }
    ans = min(ans,sum+ans1+ans2);
    ans1 = ans2 = inf;
    pos1 = pos2 = -1;
    for ( int i = 0;i < n;i++ )
    {
        if ( disb[i]-dis[i] < ans1 )
        {
            ans1 = disb[i]-dis[i];
            pos1 = i;
        }
    }
    for ( int i = 0;i < n;i++ )
    {
        if ( (disa[i]-dis[i] < ans2)&&(i!=pos1) )
        {
            ans2 = disa[i]-dis[i];
            pos2 = i;
        }
    }
    ans = min(ans,sum+ans1+ans2);
    printf("%.12lf\n",ans);
    return 0;
}
