#include <iostream>
#include <fstream>
 
using namespace std;
 
int main()
{
    ifstream fin("ttwo.in");
    ofstream fout("ttwo.out");
 
    int cx,cy,fx,fy,dat[11][11],dc=0,df=0,go[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    memset(dat,0,sizeof(dat));
 
    for (int i=1;i<=10;i++)
    {
        for (int j=1;j<=10;j++)
        {
            char c;
            fin>>c;
            if (c=='*') dat[i][j]=1;
            if (c=='F') 
            {
                        fx=i;
                        fy=j;
                        }
            if (c=='C')
            {
                       cx=i;
                       cy=j;
                       }
        }
    }
 
    int time=0,x,y;
    for (;;)
    {
        if((fx==cx)&&(fy==cy)) break;
        x=fx+go[df][0];
        y=fy+go[df][1];
        if ((dat[x][y]==1)||(x<1)||(x>10)||(y<1)||(y>10)) df=(df+1)%4;
        else {
             fx=x;
             fy=y;
             }
        x=cx+go[dc][0];
        y=cy+go[dc][1];
        if ((dat[x][y]==1)||(x<1)||(x>10)||(y<1)||(y>10)) dc=(dc+1)%4;
        else {
             cx=x;
             cy=y;
             }
        time++;
        if (time>10000000) break;
    }
 
    if (time<=10000000) fout<<time<<endl;
    else fout<<0<<endl;
 
    return 0;
 
}
