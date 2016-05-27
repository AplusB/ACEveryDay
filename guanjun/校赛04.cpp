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
#define maxn 100010
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
int n,m;
int in[maxn];
vector<int>v[maxn];
ll a[maxn];
ll b[maxn];
ll topsort(){
    ll ans=0;
    queue<int>q;
    for(int i=1;i<=n;i++)if(in[i]==0)q.push(i);
    while(!q.empty()){
        int tmp=q.front();q.pop();
        ans=max(ans,a[tmp]+b[tmp]);
        for(int i=0;i<v[tmp].size();i++){
            int u=v[tmp][i];
            in[u]--;
            b[u]=max(b[u],b[tmp]+a[tmp]);
            if(in[u]==0)q.push(u);
        }
    }
    return ans;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        cle(in);cle(b);
        for(int i=0;i<=n;i++)v[i].clear();

        for(int i=1;i<=n;i++)scanf("%I64d",&a[i]);
        int x,y;
        for(int i=1;i<=m;i++){
            scanf("%d %d",&x,&y);
            in[y]++;
            v[x].push_back(y);
        }
        printf("%I64d\n",topsort());
    }
    return 0;
}
/*
Problem Description
ACM-ICPC世界总决赛刚刚在不久前的19号结束于普吉岛，全程围观的axp观看了各路神牛秒题后内心十分excited。从此他有了一个愿望，那就是躺在WF的舞台上，为此他决定学习一些奇怪的算法来提高自己的姿势水平。这些算法有一部分是需要其他算法来作为基础的，只有学习完了一个算法的所有基础算法后，才能学习这个算法。为了更高效的学习，axp对自己的智商进行了并行优化，使得自己可以同时学习多个算法。现在请你帮助他计算一下，他还多久才能完成这些算法的学习。
Input
第一行一个整数T，接下来T组数据。
对于每组数据，第一行两个整数n和m（1<=n<=100000，0<=m<=100000)，第二行n个正整数（不超过1e9），分别代表这n个算法需要的学习时间。
接下来m行，每行两个整数x，y（1<=x<y<=n），表示x是y的基础算法。
输入保证不会出现相同的一对x，y。
Output
一个整数，表示完成学习计划的最短时间。
Sample Input
3
3 0
1 2 4
3 2
1 2 4
1 2
2 3
6 2
1 2 4 1 2 4
1 2
2 3
Sample Output
4
7
7
*/

