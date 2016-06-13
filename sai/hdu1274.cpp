#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include<stdio.h>
using namespace std;

string s;

int fun(int ith)
{
	int k,e;
	char c;
	/***************递归结束的条件是字符串结束或遇到右括号*/
	for(c=s[ith++] ; ith<s.size()&&c!=')' ; c=s[ith++])//
	{
		//计算并统一系数k（视无系数为系数1）*****很巧妙
		for(k=0 ; isdigit(c) ; c=s[ith++])
			k=k*10+(c-'0');
		if(k==0)
			k=1;

		//k是括号前的系数
		if(c=='(')
		{
			//对每个括号递归
			while(k--)
				e=fun(ith);
			//因为读取字符串是用ith遍历的，所以处理完括号直接跳到括号的下一个字符
			//重置ith的值，到下层递归结束的位置
			ith=e;
		}
		//k是字符前的系数
		else
		{
			while(k--)
				putchar(c);
		}
	}
	//返回本次读到结尾的位置
	if(c==')')
		return ith;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		s.clear();
		cin>>s;
		fun(0);
		cout<<endl;
	}
	return 0;
}
