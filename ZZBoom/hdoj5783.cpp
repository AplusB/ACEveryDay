#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
#define INF 0x3f3f3f
#define pi acos(-1.0)
#define MAX 1000010
#define mod 9973
#define ll long long
int n,m;
int a[MAX],b[MAX];
int v[MAX];
int main()
{
    int t,i,j;
    while(~scanf("%d",&n))
    {
        int cont=0;
        ll sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
            b[i]=sum;
        }
        for(i=n-1;i>=0;i--)
        {
            if(a[i]<0)
            {
                sum=a[i];
                while(i--)
                {
                    sum+=a[i];
                    if(sum>=0)
                        break;
                }
                cont++;
            }
            else
                cont++;
        }
        printf("%d\n",cont);
    }
    return 0;
}
/*
6
1 2 3 4 5 6
4
1 2 -3 0
5
0 0 0 0 0
9
1 2 1 -3 3 1 2 1 -3

*/
