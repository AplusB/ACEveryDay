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

class ExplodingRobots {
public:
	string canExplode(int x1, int y1, int x2, int y2, string instructions) {
		int vis[256];
		int n = instructions.length();
		x1 -= x2;
		y1 -= y2;
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < n; i++) vis[instructions[i]]++;
		if(abs(x1) <= vis['L'] + vis['R'] && abs(y1) <= vis['U'] + vis['D']) return "Explosion";
		return "Safe";
	}
};
