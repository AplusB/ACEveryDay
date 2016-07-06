#include <cstdio>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <math.h>
#include <stdlib.h>
#define N 1010
#define INF 0x3f3f3f3f
#define endl '\n'
#define ll long long
using namespace std;
char c[20];
int a[20];
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",c);
    int x,flag=0;
    for(int i=0;i<n;i++)
    {
         x=c[i]-'0';
         a[x]++;
    }
    if(a[0])
    {
        if(!a[1]&&!a[2]&&!a[3]) flag=1;
    }
    else
    {
        if(!a[1]&&!a[2]&&!a[3]) flag=1;
        if(!a[7]&&!a[9]) flag=1;
        if(!a[7]&&!a[4]&&!a[1]) flag=1;
        if(!a[3]&&!a[6]&&!a[9]) flag=1;
    }
    if(!flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
