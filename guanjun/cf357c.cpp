/* ***********************************************
Author        :guanjun
Created Time  :2016/8/9 9:47:21
File Name     :cf357c.cpp
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
#define INF 1<<30
#define maxn 100010
#define cle(a) memset(a,0,sizeof(a))
const ull inf = 1LL << 61;
const double eps=1e-5;
using namespace std;
priority_queue<int,vector<int>,greater<int> >pq;
string s;
struct node{
	string s;
	int x;
};
vector<node>v;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int n,x;
	while(cin>>n){
		v.clear();
		while(!pq.empty())pq.pop();
		for(int i=1;i<=n;i++){
			cin>>s;
			if(s[0]=='i'){
				scanf("%d",&x);
				pq.push(x);
				v.push_back({s,x});
			}
			else if(s[0]=='g'){
				scanf("%d",&x);
				if(pq.empty()){
					v.push_back({"insert",x});
					pq.push(x);
				}
				else
				while(!pq.empty()){
					int y=pq.top();
					if(y==x)break;
					else if(y>x){
						v.push_back({"insert",x});
						pq.push(x);
						break;
					}
					else{
						pq.pop();
						v.push_back({"removeMin",INF});
						if(pq.empty()){
							pq.push(x);
							v.push_back({"insert",x});
						}
					}
				}
				v.push_back({s,x});
			}
			else if(s[0]=='r'){
				if(pq.empty())v.push_back({"insert",0});
				else pq.pop();
				v.push_back({"removeMin",INF});
			}
		}
		cout<<v.size()<<endl;
		for(int i=0;i<v.size();i++){
			cout<<v[i].s;
			if(v[i].x!=INF){
				cout<<" "<<v[i].x;
			}
			cout<<endl;
		}
	}
    return 0;
}
