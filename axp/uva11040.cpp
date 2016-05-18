/* ***********************************************
Author        :axp
Created Time  :2016/5/17 18:50:23
TASK		  :11040.cpp
LANG          :C++
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 15;
int T;
int ar[N][N];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=9;i+=2)
			for(int j=1;j<=i;j+=2)
				scanf("%d",&ar[i][j]);
		for(int i=1;i<=7;i+=2)
			for(int j=1;j<=i;j+=2)
			{
				ar[i+2][j+1]=(ar[i][j]-ar[i+2][j]-ar[i+2][j+2])/2;
				ar[i+1][j]=ar[i+2][j]+ar[i+2][j+1];
				ar[i+1][j+1]=ar[i+2][j+1]+ar[i+2][j+2];
			}
		for(int i=1;i<=9;i++)
			for(int j=1;j<=i;j++)
				printf("%d%c",ar[i][j],j==i?10:' ');
	}
    return 0;
}
