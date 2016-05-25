/*************************************************************************
 > File Name: 18-d.cpp
 > Author: Baiyan
 > 题意：
 > Created Time: 2016年05月18日 星期三 13时09分14秒
 **********************************************************************/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[1005];
char ans[1005];
char s1[3][1005];
int main()
{
	gets(s);
	int n = strlen(s);
	int cnt=0,num=0;
	int x[3]={0};
	for(int i=0;i<n;i++)
	{
		if(s[i]=='{')
		{
			int j = i+1;
			while(j<n && s[j]!='}')
				s1[0][x[0]++] = s[j++];
			s[x[0]] = '\0';
			i=j;
		}
		else if(s[i]=='(')
		{
			int j = i+1;
			while(j<n && s[j]!=')')
				s1[1][x[1]++] = s[j++];
			s1[1][x[1]] = '\0';
			i=j;
		}
		else if(s[i]=='[')
		{
			int j = i+1;
			while(j<n && s[j]!=']')
				s1[2][x[2]++] = s[j++];
			s1[2][x[2]] = '\0';
			i=j;
		}
		else if(s[i]==',') 
		{
			for(int j=0;j<3;j++)
			{
				for(int z=0;z<x[j];z++)
					ans[cnt++] = s1[j][z];
				if(j!=2)
					ans[cnt++] = ' ';
				x[j]=0;
			}
			ans[cnt++]=',';
		}
		else
			ans[cnt++]=s[i];
	}
	for(int j=0;j<3;j++)
	{
		for(int z=0;z<x[j];z++)
			ans[cnt++] = s1[j][z];
		if(j!=2)
			ans[cnt++] =' ';
	}
	if(s[n-1]!='}'  && s[n-1]!=')' && s[n-1]!=']')
		ans[cnt++]=s[n-1];
	ans[cnt] = '\0';
	n = strlen(ans);
//	printf("%s\n",ans);
	char t[1005];
	cnt =0;
	int i=0;
	while(i<n && ans[i]==' ')
		i++;
	if(ans[i]<='z' && ans[i]>='a')
		t[cnt++] = ans[i]-32;
	else
		t[cnt++] = ans[i];
	i++;
	for(;i<n;i++)
	{
		if(ans[i-1]==' ' && ans[i]==' ')
			continue;
		if(ans[i]<='z' && ans[i]>='a')
			t[cnt++] = ans[i];
		else if(ans[i]<='Z' && ans[i]>='A')
			t[cnt++] = ans[i]+32;
		else
			t[cnt++] = ans[i];
	}
//	printf("%s\n",ans);
//	cout<<cnt<<endl;
	t[cnt] = '\0';
	printf("%s\n",t);
	return 0;
}
