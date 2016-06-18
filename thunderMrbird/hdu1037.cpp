#include<iostream>
#include <cstdio>
#include<queue>
#include<string>
#include<algorithm>
#include<map>
#include <cstring>
#include<queue>
#include<vector>
#include<cmath>
#include<set>
using namespace std;
typedef long long ll;
const int maxn=405;
int a[10005];
int main()
{
    bool flag=0;
    for(int i=0;i<3;i++)
    {
    scanf("%d",a+i);
    if(a[i]<=168) {printf("CRASH %d\n",a[i]); flag=1;}
    }
    if(!flag) printf("NO CRASH\n");
    return 0;
}
