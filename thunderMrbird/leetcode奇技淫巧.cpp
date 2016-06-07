#include<iostream>
#include <stdio.h>
#include<queue>
#include<string>
#include<algorithm>
#include<map>
#include <string.h>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
        int ones=0;
        int twos=0;
        int xthrees=0;
        int n,x;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
                scanf("%d",&x);
                twos ^= (ones&x);
                ones ^= x;
                xthrees = ~(ones&twos);
                twos &= xthrees;
                ones &=xthrees;
         }
        printf("%d\n",ones);
}
/*
1
3 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
*/
