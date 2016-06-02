#include <iostream>
#include<stdio.h>
using namespace std;

const int MAXN = 30001; /*结点数目上限*/

int pa[MAXN];  /*p[x]表示x的父节点*/
int rank[MAXN];/*rank[x]是x的高度的一个上界*/
int num[MAXN]; /*num[]存储该集合中元素个数，并在集合合并时更新num[]即可*/

/*创建一个单元集*/
void make_set(int x)
{
    pa[x] = x;
    rank[x] = 0;
    num[x] = 1;
}

/*带路径压缩的查找*/
int find_set(int x)
{
    /*保存待查找的数*/
    int r=x;
    int temp;

    /*找到根节点*/
    while(pa[r] != r)
		r = pa[r];

    //递归写法
    if(x != pa[x])
        pa[x] = find_set(pa[x]);
    return pa[x];
    //迭代写法
    /*while(x != r)
    {
        temp = pa[x];
        pa[x] = r;
        x = temp;
    }
    return x;*/
}

/*按秩合并x，y所在的集合*/
void union_set(int x, int y)
{
    x = find_set(x);
    y = find_set(y);
    if(x == y)return ;
    if(rank[x] > rank[y])/*让rank比较高的作为父结点*/
    {
        pa[y] = x;
        num[x] += num[y];
    }
    else
    {
        pa[x] = y;
        if(rank[x] == rank[y])
            rank[y]++;
        num[y] += num[x];
    }
}

int main()
{
    int n, m, x, y, i, t, j;
    while(cin>>n>>m,(m+n))
    {
        if(m == 0)
        {
            cout << "1\n"; continue;
        }
        for(i = 0; i < n; i++)
            make_set(i);
        for(i = 0; i < m; i++)
        {
            scanf("%d", &t);
            scanf("%d", &x);
            for(j = 1; j < t; j++)
			{
                scanf("%d", &y);
                union_set(x, y);
                x = y;
            }
        }
        x = find_set(0);/*找到0所在的树的树根*/
        cout << num[x] << endl;
    }
    return 0;
}
