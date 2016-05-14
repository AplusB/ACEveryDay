/* ***********************************************
Author        :xdlove
Created Time  :2016年05月14日 星期六 13时12分41秒
File Name     :D.cpp
************************************************ */

#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
map<string,int>mp;
char s[50];

void solve()
{
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        scanf("%s",s);
        sort(s,s + strlen(s));
        int ans = mp[s];
        printf("%d\n",ans);
        mp[s]++;
    }
}


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve(); 
    return 0;
}
