/* ***********************************************
Author        :xdlove
Created Time  :2016年05月12日 星期四 08时14分28秒
File Name     :CF352/2016_05_12_A.cpp
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

void solve()
{
    int n;
    string s;
    cin >> n;
    for(int i = 1; i <= 1000; ++i)
    {
        s += to_string(i);
    }
    cout << s[n - 1] << endl; 
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();    
    return 0;
}
