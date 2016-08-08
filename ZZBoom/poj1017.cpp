#include <iostream>
#include <cstdio>
#include<vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef __int64 LL;

/*
题意：
有6种面积的格子，给出这些格子的数量，然后有6*6的格子去容纳这6种面基，问最少需要几个6*6格子，使得所有类型的小格子被容纳。
思路：
按照面积的从大到小放。
一开始还是太天真，还要用各种1去补，wa了一发…

*/
int a[10];

int main()
{
    while(1)
    {
        bool flag=false;
        for(int i=1;i<=6;i++)
        {
            scanf("%d",&a[i]);
            if(a[i])
                flag=true;
        }
        if(!flag)
            break;
        int ans=0;
        ans+=a[6];

        if(a[5])
        {
            ans+=a[5];              //5 只能一个
            if(a[1]<=11*a[5])       //用 1 去填
                a[1]=0;
            else
                a[1]-=11*a[5];
        }

        if(a[4])
        {
            ans+=a[4];
            if(a[2]<=5*a[4])        //如果在那么里面，2 填完，上 1
            {
                int x=a[4]*36-16*a[4]-a[2]*4;  //剩下的 1 的数量
                if(a[1]<=x)
                    a[1]=0;
                else
                    a[1]-=x;
                a[2]=0;
            }
            else                    //这里填了 4 后剩下的区域都是 2 填
                a[2]-=5*a[4];
        }
        if(a[3])
        {
            ans+=a[3]/4;        //4个3正好填满
            int x=a[3]%4;
            if(x==1)            //剩一个3
            {
                ans+=1;
                if(a[2])
                {
                    if(a[2]<=5) //一个3以后最多填5个2，这里是 2 不够了
                    {
                        int y=36-9-a[2]*4;
                        if(a[1]<=y)
                            a[1]=0;
                        else
                            a[1]-=y;
                        a[2]=0;
                    }
                    else
                    {
                        a[2]-=5;  //这里是2够的，只能+11 个 1
                        if(a[1]<=11)
                            a[1]=0;
                        else
                            a[1]-=11;
                    }
                }
            }
            else if(x==2)
            {
                ans+=1;
                if(a[2]<=3)     //两个3以后最多天3个2，这里是不够
                {
                    int y=36-18-a[2]*4;     //用1补
                    if(a[1]<=y)
                        a[1]=0;
                    else
                        a[1]-=y;
                    a[2]=0;
                }
                else        //2够的话，最多填6个1
                {
                    if(a[1]<=6)
                        a[1]=0;
                    else
                        a[1]-=6;
                    a[2]-=3;
                }
            }
            else if(x==3)
            {
                ans+=1;
                if(a[2]<=1)     //最多只能填1个 2 ，不够
                {
                    int y=9-a[2]*4;
                    if(a[1]<=y) //用1补
                        a[1]=0;
                    else
                        a[1]-=y;
                    a[2]=0;
                }
                else
                {
                    if(a[1]<=5) //2够的话，只能上5个 1
                        a[1]=0;
                    else
                        a[1]-=5;
                    a[2]-=1;
                }
            }
        }
        if(a[2])
        {
            ans+=a[2]/9;    //9个2正好填满
            int x=a[2]%9;
            if(x)           //2*2还有的多
            {
                ans+=1;
                int y=36-x*4;  //用1补
                if(a[1]<=y)
                    a[1]=0;
                else
                    a[1]-=y;
            }
        }
        if(a[1])
        {
            ans+=a[1]/36;       //36个1*1正好填满
            int x=a[1]%36;
            if(x)           //不够补。
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}




