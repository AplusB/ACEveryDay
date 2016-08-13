#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define eps 1e-8
typedef __int64 LL;
int main()
{
    int n;
    scanf("%d",&n);
    printf("%I64d",(1LL<<(n+1))-2);
    return 0;
}
