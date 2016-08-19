/* ***********************************************
Author        :guanjun
Created Time  :2016/8/19 12:58:15
File Name     :1001.cpp
************************************************ */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int>v;
vector<int>a;
vector<int>b;
void dfs(int x){
	if(x==n){
		for(int i=0;i<a.size();i++)
			cout<<a[i]<<" ";
		for(int i=b.size()-1;i>=0;i--)
			cout<<b[i]<<" ";
		cout<<endl;
		return ;
	}
	b.push_back(v[x]);
	dfs(x+1);
	b.pop_back();

	if(!b.empty()){
		a.push_back(b.back());
		b.pop_back();
		dfs(x);
		b.push_back(a[a.size()-1]);
		a.pop_back();
	}
}
int main()
{

    while(cin>>n){
		v.clear();
		int x;
		for(int i=1;i<=n;i++){
			cin>>x;
			v.push_back(x);
		}
		dfs(0);
	}
    return 0;
}
