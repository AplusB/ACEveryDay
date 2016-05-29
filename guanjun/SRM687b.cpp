#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;
#define maxn 30000
class Quacking {
    public:
    int quack(string s) {
		int n=s.size();
		int vis[maxn]={0};
		if(s[0]!='q')return -1;
		string t="quack";
		int mark=0;
		int ans=0;
		int k;
		for(;;){
			k=0;
			mark=0;
			for(int i=0;i<n;i++){
				if(!vis[i]){
					if(s[i]==t[k]){
						vis[i]=1;
						k++;
						if(k==5){
							mark=1;k=0;
						}
					}
				}
			}
			if(k!=0)return -1;
			if(mark==0)break;
			ans++;
		}
		for(int i=0;i<n;i++)if(!vis[i])return -1;
        return ans;
    }
};
