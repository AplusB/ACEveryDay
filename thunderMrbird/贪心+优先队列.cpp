#include<iostream>
#include <stdio.h>
#include<queue>
#include<string>
#include<algorithm>
#include<map>
#include <string.h>
#include<queue>
#include<vector>
using namespace std;
priority_queue <int, vector<int>, greater<int> > q;
struct node
{
        int x, y;
} cow[3005], bot[3005];
bool cmp(node l, node r)
{
        return l.x < r.x;
}
int main()
{
        int l,c;
        scanf("%d %d", &c, &l);
        for (int i = 0; i < c; i++)
                scanf("%d %d", &cow[i].x, &cow[i].y);
        for (int i = 0; i < l; i++)
                scanf("%d %d", &bot[i].x, &bot[i].y);
        sort(cow, cow + c, cmp);
        sort(bot, bot + l, cmp);
        int j=0,sum=0;
        for (int i = 0; i < l; i++)
        {
                while (j < c && cow[j].x <= bot[i].x)
                {
                        q.push(cow[j].y);
                        j++;
                }
                while (!q.empty() && bot[i].y)
                {
                        int temp = q.top();
                        q.pop();
                        if (temp < bot[i].x) continue;
                        sum++;
                        bot[i].y--;
                }
        }
        printf("%d\n",sum);
        return 0;
}
