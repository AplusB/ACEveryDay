#include <bits/stdc++.h>
using namespace std;
const int maxn = 33;
struct Point{
    int x, y;
    void read(){ scanf("%d%d", &x, &y); }
}p[maxn];
vector < Point > X[233], Y[233];
int mp[233][233];
struct Rect{
    int x, y, w, h;
    Rect(){}
    Rect(int _x, int _y, int _w, int _h): x(_x), y(_y), w(_w), h(_h) {}
};
vector < Rect > rec;

bool Inner(const Rect& A, const Rect& B){
    if(A.x > B.x && A.y > B.y && A.x + A.w < B.x + B.w && A.y + A.h < B.y + B.h)
        return true;
    if(B.x > A.x && B.y > A.y && B.x + B.w < A.x + A.w && B.y + B.h < A.y + A.h)
        return true;
    return false;
}

bool CrossOrTouch(const Rect& A, const Rect& B){
    if(A.x >= B.x && A.x <= B.x + B.w && A.y >= B.y && A.y <= B.y + B.h)
        return true;
    if(A.x + A.w >= B.x && A.x + A.w <= B.x + B.w && A.y >= B.y && A.y <= B.y + B.h)
        return true;
    if(A.x >= B.x && A.x <= B.x + B.w && A.y + A.h >= B.y && A.y + A.h <= B.y + B.h)
        return true;
    if(A.x + A.w >= B.x && A.x + A.w <= B.x + B.w && A.y + A.h >= B.y && A.y + A.h <= B.y + B.h)
        return true;
    return false;
}

int Area(const Rect& A, const Rect& B){
    if(Inner(A, B))
        return max(A.h * A.w, B.h * B.w);
    if(CrossOrTouch(A, B) || CrossOrTouch(B, A))
        return -1;
    return A.h * A.w + B.h * B.w;
}

int main(){
    int n;
    while(scanf("%d", &n) && n){
        for(int i = 0; i < 233; i++){
            X[i].clear();
            Y[i].clear();
        }
        memset(mp, 0, sizeof mp);
        rec.clear();
        for(int i = 1; i <= n; i++){
            p[i].read();
            X[p[i].x].push_back(p[i]);
            Y[p[i].y].push_back(p[i]);
            mp[p[i].x][p[i].y] = 1;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < X[p[i].x].size(); j++) if(X[p[i].x][j].y > p[i].y){
                int h = X[p[i].x][j].y - p[i].y;
                for(int k = 0; k < Y[p[i].y].size(); k++) if(Y[p[i].y][k].x > p[i].x){
                    int w = Y[p[i].y][k].x - p[i].x;
                    if(mp[p[i].x + w][p[i].y + h])
                        rec.push_back(Rect(p[i].x, p[i].y, w, h));
                }
            }
        }
        int ans = -1;
        for(int i = 0; i < rec.size(); i++){
            for(int j = i + 1; j < rec.size(); j++){
                ans = max(ans, Area(rec[i], rec[j]));
            }
        }
        if(ans == -1) puts("imp");
        else printf("%d\n", ans);
    }
    return 0;
}
