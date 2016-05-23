//年份从1989年开始
//每个后缀数量从1到9，每个位数所含有的数量分别为10,100,1000,10000,100000,1000000,10000000....
//因而从1989年开始，1989+10 = 1位后缀的最后年份，1位最后年份+100 = 2位后缀的最后年份，2位最后年份+1000 = 3位最后年份.....
//先打表，然后判断
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<set>
using namespace std;
typedef long long ll;
ll flag[20];
char a[20];
ll fun(int x){
	ll tmp = 1;
	for(int i = 1; i <= x; ++i)
		tmp *= 10;
	return tmp;
}
void init(){
	flag[0] = 1989;
	ll temp = 1;
	for(int i = 1; i <= 12; ++i){
		temp *= 10;
		flag[i] = flag[i-1] + temp;
	}
}
int main(){
#ifdef _CONSOLE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
  init();
	int t;
	while(~scanf("%d",&t)){
		for(int i = 0; i < t; ++i){
			scanf("%s",a);
			int len = strlen(a);
			ll s = 0;
			for(int i = 4; i < len; ++i){
				s *= 10;
				s += a[i] - '0';
			}
			for(int i = 0; i <= 200; ++i){
				ll num = s + (ll)i * fun(len - 4);
				if(num >= flag[len-5] && num < flag[len - 4]){
					cout << num << endl;
					break;
				}
			}
		}
	}

	return 0;
}
