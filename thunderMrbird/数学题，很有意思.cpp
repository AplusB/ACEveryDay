#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<queue>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
#define INF 1000000001
int main()
{
    int n,a,b,c,d;
    scanf("%d %d %d %d %d",&n,&a,&b,&c,&d);
    printf("%I64d\n",max((n-max(a,d)-max(c,b)+min(a,d)+min(c,b))*1LL*n,0LL));
    return 0;
}
