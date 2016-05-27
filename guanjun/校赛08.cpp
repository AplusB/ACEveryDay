/* ***********************************************
Author        :guanjun
Created Time  :2016/5/27 17:25:31
File Name     :1.cpp
************************************************ */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <list>
#include <deque>
#include <stack>
#define ull unsigned long long
#define ll long long
#define mod 90001
#define INF 0x3f3f3f3f
#define maxn 10010
#define cle(a) memset(a,0,sizeof(a))
const ull inf = 1LL << 61;
const double eps=1e-5;
using namespace std;
priority_queue<int,vector<int>,greater<int> >pq;
struct Node{
	int x,y;
};
struct cmp{
    bool operator()(Node a,Node b){
        if(a.x==b.x) return a.y> b.y;
        return a.x>b.x;
	}
};

bool cmp(int a,int b){
    return a>b;
}
int main()
{
    #ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int t;
	cin>>t;
	ll x,y,z;
	while(t--){
		cin>>x>>y>>z;
		ll tmp=y*(x-1);
		ll ans=(tmp<=z-1?0:tmp-(z-1));
		cout<<ans<<endl;
	}
    return 0;
}
/*
Problem Description
~~~xp巨巨是充满智慧的小精灵，集日月之精华。xp巨巨很会A题，当面对题目的时候永远只会说两种话“简单题”or“傻*题”。有一天xp巨巨，A题很嗨的时候，思考了人生，A题好不一定能够赢取白富美，但是有钱会。所以他将自己一直以来有的点子告诉了，zyc巨巨、gj巨巨，商讨开办一家公司。经过xp巨巨强大的游说能力，两大财主zyc巨巨，gj巨巨决定投资企业。
~~~有一天，wjb大财主决定让企业推向纳斯达克，她问CEO-xp,是否有好的点子让我投资你们公司？xp开始讲了，我们拥有很好喝的饮料:可口可悲，当然我们有更好的营销策略！如果你有x个空瓶子，你就可以换取一瓶新的“可口可悲”。wjb大财阀听到后，表示很满意，当即投资天文数字多的钱。 
~~~天气炎热，正在街边卖了一天烤红薯的cy，决定今天好好满足一下自己，他想喝到至少y瓶“可口可悲”，他仍保留着之前喝剩下的z个空瓶子，有时候他只能靠再捡瓶子去得到满足。聪明的你们可以帮他计算他需要捡多少个空瓶子？
Input
多组输入。第一行一个整数n代表数据组数，接下来的n行，每行由三个数组成x,y,z(1<x<10^9 0<=y,z<=10^18)。
Output
输出额外捡空瓶子的数量（保证答案范围[0,10^18]）。
Sample Input
3
3 4 9 
3 4 10
3 4 8
Sample Output
0
0
1 
*/
