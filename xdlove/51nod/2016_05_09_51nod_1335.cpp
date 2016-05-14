/* ***********************************************
Author        :xdlove
Created Time  :2016年05月09日 星期一 19时02分23秒
File Name     :2016_05_09_51nod_1335.cpp
 ************************************************ */

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
const int N = 3000;
string s;

vector<int> returnVec(vector<int> &vec, int pos)
{
    vector<int> ans;
    int tp = pos;
    for(int i = 0; i < vec.size(); ++i)
    {
        if(s[vec[i]] > s[pos]) continue;
        if(s[vec[i]] < s[pos])
        {
            pos = vec[i];
            ans.clear();
        }
        if(tp != pos) ans.push_back(vec[i]);
    }
    return ans;
}


void solve()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> s;
        vector<int> vec;
        int l = 0;
        while(true)
        {
            if(l >= s.length()) break;
            for(int i = l + 1; i < s.length(); ++i) vec.push_back(i);
            vec = returnVec(vec, l);
            if(vec.size() > 0) break;
            l++;
        }
        int r = 0;
        if(vec.size() > 0)
        {
            string c = s;
            for(int i = 0; i < vec.size(); ++i)
            {
                string tp = s;
                reverse(tp.begin() + l,tp.begin() + vec[i] + 1);
                if(tp < c)
                {
                    r = vec[i];
                    c = tp;
                }
            }
        }
        else l = 0;
        printf("%d %d\n",l,r);
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();    
    return 0;
}
