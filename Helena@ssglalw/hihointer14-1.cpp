#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <assert.h>
#define FREAD(fn) freopen((fn), "r", stdin)
#define RINT(vn) scanf("%d", &(vn))
#define PINT(vb) printf("%d", vb)
#define RSTR(vn) scanf("%s", (vn))
#define PSTR(vn) printf("%s", (vn))
#define CLEAR(A, X) memset(A, X, sizeof(A))
#define REP(N) for(int i=0; i<(N); i++)
#define REPE(N) for(int i=1; i<=(N); i++)
#define pb(X) push_back(X)
#define pn() printf("\n")
using namespace std;

struct LRU
{
	stack<string> s1, s2;
	map<string, int> ma;//存在哪个栈里
	string temp;
	int M;

	LRU(int m):M(m){}
	void push(string str){
		if(s1.size() + s2.size() == M){//已满，移除最旧的
			remove();
		}
		s2.push(str);
		ma.insert(pair<string, int>(str, 2));//插入2号栈
	}
	void remove(){
		if(s1.empty()){//s1中没有更旧的了，则从s2获取
			while(!s2.empty()){
				s1.push(s2.top());
				(ma.find(s2.top()))->second = 1;//转移到1号栈中
				s2.pop();
			}
		}
		ma.erase(s1.top());//删除最旧的
		s1.pop();
	}
	bool find(string str){
		if(ma.find(str) != ma.end()){//已存在，找到并把它调到2号栈的顶部
			map<string, int>::iterator iter = ma.find(str);
			int cnt;
			if(iter->second == 2){//在2号栈里
				cnt = 0;
				while(s2.top() != str){
					s1.push(s2.top());
					s2.pop();
					cnt++;
				}
				s2.pop();//str暂时出栈
				while(cnt--){
					s2.push(s1.top());
					s1.pop();//重新按原顺序放回s2
				}
				s2.push(str);//放在s2顶
			}else{//在1号栈里
				cnt = 0;
				while(s1.top() != str){
					s2.push(s1.top());
					s1.pop();
					cnt++;
				}
				s1.pop();
				while(cnt--){
					s1.push(s2.top());
					s2.pop();
				}
				s2.push(str);
				ma.find(str)->second = 2;//修改栈标
			}
			return true;
		}
		else{
			push(str);
			return false;
		}
	}
};

int main()
{
	FREAD("inter14-1.txt");
	int n, m;
	RINT(n); RINT(m);
	LRU lru(m);
	while(n--){
		string str;
		cin >> str;
		if(!lru.find(str)) printf("Internet\n");
		else printf("Cache\n");
	}
	return 0;
}
