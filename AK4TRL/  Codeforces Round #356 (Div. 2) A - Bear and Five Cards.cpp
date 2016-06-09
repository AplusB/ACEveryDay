//5个数，除去一种数量大于1的数后剩下数总和最小多少
//容器计算一下数量，取总和最小的
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
map<int,int>num;
int main(){
#ifdef _CONSOLE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int t, sum = 0;
    for(int i = 0; i < 5; ++i){
        scanf("%d",&t);
        num[t]++;
        sum += t;
    }
    int res = sum;
    for(map<int,int>::iterator it =num.begin(); it != num.end(); it++)
        if(it->second > 1)
            res = min(res, sum-it->first * min(3 , it->second));
    cout << res << endl;
    return 0;
}
