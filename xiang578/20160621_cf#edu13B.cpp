/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.com
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
const int N=2048;

int ok(int n) {
	if(n%100==0) {
		if(n%400==0) return 1;
		else return 0;
	} else if(n%4==0) return 1;
	else return 0;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	scanf("%d",&n);
	if(ok(n)) {
		int cnt=0;
		for(int i=0;; i++) {
			cnt+=365+ok(n+i);
			if(cnt%7==0&&ok(n+i+1)) {
				printf("%d\n",n+i+1);
				return 0;
			}
		}
	}
	else
	{
		int cnt=0;
		for(int i=0;;i++)
		{
			cnt+=365+ok(i+n);
			if(cnt%7==0&&ok(n+i+1)==0)
			{
				printf("%d\n",n+i+1);
				return 0;
			}
		}
	}
	return 0;
}
