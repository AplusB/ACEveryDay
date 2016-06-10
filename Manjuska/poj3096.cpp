#include<iostream>
#include<string>
#include<map>
using namespace std;
string str;
int main()
{
	
	while(cin>>str,str!="*")
	{
		
		bool flag=true;
		for(int i=0;i<str.length()&&flag;i++)
		{
			map<string,int> mp;
			for(int j=0;j+i+1<str.length()&&flag;j++)
			{
				char tmp[3]={str[j],str[j+i+1],'\0'};
				if(mp[tmp]>0)
				{
					cout<<str<<" is NOT surprising."<<endl;
					flag=false;
				}
				else
					mp[tmp]++;

			}
		}
		if(flag)
			cout<<str<<" is surprising."<<endl;
	}
	return 0;
}
