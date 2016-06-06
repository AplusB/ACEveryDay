#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
char a[100005];
int d[100005];
bool vis[100005];
int main(){
#ifdef _CONSOLE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n;
	while(~scanf("%d",&n)){
		scanf("%s",a);
		for(int i = 0; i < n; ++i)
			scanf("%d",&d[i]);

		int i = 0;
		bool ok = false;
		while((i >= 0) && (i < n)){
			if(vis[i]==1){
				ok = true;
				break;
			}
			vis[i] = 1;
			if(a[i] == '>')
				i += d[i];
			else
				i -= d[i];
		}
		puts(ok ? "INFINITE" : "FINITE");
	}

	return 0;
}
