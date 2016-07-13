#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <string>
#include <set>

using namespace std;

class DistinguishableSetDiv2 {
public:
	int count(vector <string> answer) {
		set<string> s;
		int n = answer.size();
		int m = answer[0].length();
		int mm = 1 << m;
		int ret = 0;
		for(int i = 0; i < mm; i++) {
			s.clear();
			for(int j = 0; j < n; j++) {
				string tmp  = "";
				for(int k = 0; k < m; k++) {
					if((1 << k) & i) {
						tmp += answer[j][k];
					}
				}
				s.insert(tmp);
			}
			if(s.size() == n) ret++;
		}
		return ret;
	}
};
