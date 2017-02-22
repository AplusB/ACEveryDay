# include <cstdio>
# include <iostream>
# include <algorithm>
# include <cstring>
using namespace std;
# define MAX 123
int n,m;
int dir[8][2] = {{1,0},{0,1},{1,1},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
char map[MAX][MAX];
void dfs ( int x,int y ) 
{
	map[x][y] = '*';
	for ( int i = 0;i < 8;i++ ) {
		int next_x = x+dir[i][0];
		int next_y = y+dir[i][1];
		if ( next_x>=0&&next_x<n&&next_y>=0&&next_y<m ) {
			if ( map[next_x][next_y]=='@' ) {
				dfs(next_x,next_y);
			}
		}
	}
	return;
}
int main(void)
{
	while ( scanf("%d%d",&n,&m)!=EOF ) {
		if ( n==0 || m==0 ) break;
		for ( int i = 0;i < n;i++ ) {
			scanf("%s",&map[i]);
		}
		int res = 0;
		for ( int i = 0;i < n;i++ ) {
			for ( int j = 0;j < m;j++ ) {
				if ( map[i][j]=='@' ) {
					dfs(i,j);
					res++;
				}
			}
		}
		printf("%d\n",res);
	}


	return 0;
}
