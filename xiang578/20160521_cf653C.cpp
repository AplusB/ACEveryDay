/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.top
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=1024;
vector<int>v;
int a[150000+10],u[150000+10],n;

int get(int x) {
	if(x%2==1) {
		if(x+1<n&&a[x]<=a[x+1]) return 0;
		if(x-1>=0&&a[x-1]>=a[x]) return 0;
	} else {
		if(x+1<n&&a[x]>=a[x+1]) return 0;
		if(x-1>=0&&a[x-1]<=a[x]) return 0;
	}
	return 1;
}

int check(int x) {
	if(get(x)==0) return 0;
	for(int i=0; i<v.size(); i++) {
		if(get(v[i])==0) return 0;
	}
	return 1;
}

int main() {
	long long ans=0;
	while(~scanf("%d",&n)) {

		for(int i=0; i<n; i++)
			scanf("%d",a+i);
		v.clear();
		memset(u,0,sizeof(u));
		for(int i=0; i<n; i++) {
			if(i%2==0&&i+1<n) {
				if(a[i]>=a[i+1]) {
					if(u[i]==0)v.push_back(i);
					if(u[i+1]==0)v.push_back(i+1);
					u[i]=1;
					u[i+1]=1;
				}
			}
			if(i%2==1&&i+1<n) {
				if(a[i]<=a[i+1]) {
					if(u[i]==0)v.push_back(i);
					if(u[i+1]==0)v.push_back(i+1);
					u[i]=1;
					u[i+1]=1;
				}
			}
		}
		ans=0;
		if(v.size()<=10) {
			for(int i=0; i<n; i++) {
				for(int k=0; k<v.size(); k++) {
					int j=v[k];
					if(i==j) continue;
					if(u[i]&&j>i) continue;
					swap(a[i],a[j]);
					if(check(i)) ans++;
					swap(a[i],a[j]);
				}
			}
		} /*else {
			for(int i=0; i<n; i++) {
				for(int j=i+1; j<n; j++) {
					swap(a[i],a[j]);
					if(get(i)==1&&get(j)==1) ans++;
					swap(a[i],a[j]);
				}
			}
		}
		*/
		printf("%lld\n",ans);
	}
	return 0;
}
