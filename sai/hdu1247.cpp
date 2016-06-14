#include<map>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
int main()
{
	vector<string> v;
	map<string, int> m;

	string str, s1, s2;

	while(cin>> str)
	{
		v.push_back(str);
		m[str]++;
	}

	for(int i = 0; i < v.size(); i++ )
	{
		str = v[i];
		s1 = "";
	//看字符串str能否分为字典里存在的两个字符串
		for(int j = 0; j + 1 < str.size(); j++ )
		{
			s1 += str[j];
			s2 = str.substr(j + 1);
			if(m[s1] && m[s2])
			{
				cout<< str<< endl;
				break;
			}
		}
	}
    return 0;
}
