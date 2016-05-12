#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

char dungeon[33][33][33]; 
int xx[]={1,-1,0,0,0,0};  
int yy[]={0,0,0,0,-1,1}; 
int zz[]={0,0,-1,1,0,0}; 
bool vis[33][33][33];
int l,c,r;

struct point {
    int x,y,z;
    int depth;
};

int bfs(point s)
{
    memset(vis, false, sizeof(vis));
    queue <point> q;
    q.push(s);
    vis[s.x][s.y][s.z] = true;
    
    while (!q.empty()) {
        point tmp = q.front();
        q.pop();
        
        if (dungeon[tmp.x][tmp.y][tmp.z] == 'E') {
            //cout << tmp.x << " " << tmp.y <<  " " << tmp.z << endl;
            return tmp.depth;
        }
        
        for (int i = 0; i < 6; ++i) {
            point d;
            d.x = tmp.x + xx[i];
            d.y = tmp.y + yy[i];
            d.z = tmp.z + zz[i];
            
            if (!vis[d.x][d.y][d.z] && (dungeon[d.x][d.y][d.z] == '.' || dungeon[d.x][d.y][d.z] == 'E') && 
                d.x >= 0 && d.x < l && d.y >= 0 && d.y < c && d.z >= 0 && d.z < r) {
                    vis[d.x][d.y][d.z] = true;
                    d.depth = tmp.depth + 1;
                    q.push(d);              
                }
        }
        
    }
    return 0;
}

int main()
{
    while (scanf("%d%d%d", &l, &c, &r) != EOF && l && c && r) {
        point s;
        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < c; ++j) {
                for (int k = 0; k < r; ++k) {
                    //scanf("%c", &dungeon[i][j][k]);
                    cin >> dungeon[i][j][k];
                    if (dungeon[i][j][k] == 'S') {
                        s.x = i;
                        s.y = j;
                        s.z = k;
                        s.depth = 0;
                    }
                }
            }
        }
        
        if (bfs(s)) printf("Escaped in %d minute(s).\n",bfs(s));  
        else printf("Trapped!\n");  

                
    }
    
    return 0;
}