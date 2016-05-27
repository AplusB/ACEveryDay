//http://codeforces.com/contest/676/problem/A
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <queue>
#include <fstream>
#include <math.h>
#include <iomanip>
#define read freopen("q.in","r",stdin)
#define write freopen("q.out","w",stdout)
using namespace std;
#define maxn 1006

int main()
{
    int n,i,a;
    while(~scanf("%d",&n))
    {
        int pos1=-1,pos2=-1;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            if(a==1 || a==n)
            {
                if(pos1==-1)
                {
                    pos1=i;
                }
                else pos2=i;
            }
        }
        printf("%d\n",max(pos1,n-1-pos2)+pos2-pos1);
    }
}
