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

class CoinFlipsDiv2 {
public:
	int countCoins(string state) {
		int n = state.length();
		int ret = 0;
		if(n == 1) return ret;
		for(int i = 0; i < n; i++) {
			if(i == 0) {
				if(state[i] != state[i+1]) ret++;
				continue;
			}
			if(i == n - 1) {
				if(state[i] != state[i-1]) ret++;
				continue;
			}
			if(state[i] != state[i-1] || state[i] != state[i+1]) ret++;
		}
		return ret;
	}
};
