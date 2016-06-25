#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
ll dp[105][105][55];
int dx[]={0, -1, -1, -1, 0, 1, 1, 1, 
		 -1, -2, -2, -1, 1, 2, 2, 1}, 
	dy[]={1, 1, 0, -1, -1, -1, 0, 1,
		 2, 1, -1, -2, -2, -1, 1, 2};

class ChessMetric{
public:
	int size;
	bool in(int x, int y){
		if(x < 0 || x >= size || y<0 || y>=size) return false;
		return true;
	}
	ll howMany(int size, vector<int> start, vector<int> end, int numMoves){
		this->size = size;
		memset(dp, 0, sizeof(dp));
		dp[start[0]][start[1]][0] = 1;
		for(int k=0; k<numMoves; k++){
			for(int x=0; x<size; x++){
				for(int y=0; y<size; y++){
					for(int m=0; m<16; m++){
						int nx = x + dx[m];
						int ny = y + dy[m];
						if(in(nx, ny)){
							dp[x][y][k+1] += dp[nx][ny][k];
						}
					}
				}
			}
		}
		return dp[end[0]][end[1]][numMoves];
	}
};
