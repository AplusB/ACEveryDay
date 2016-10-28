#include<bits/stdc++.h>
using namespace std;

typedef pair<int,pair<int,int> > sta;

struct Point{
    int x,y;
    void inp(){
        scanf("%d %d",&x,&y);
    }
    Point(int x=0,int y=0):x(x),y(y){}
    int len(){
        return x * x + y * y;
    }
};
Point operator + (Point a,Point b){return Point(a.x + b.x,a.y + b.y); }
Point operator * (int v,Point a){return Point(a.x * v,a.y * v); }
Point operator - (Point a,Point b){return -1*b+a;}
Point operator / (Point a,int v){return Point(a.x / v,a.y / v); }
#define sqr(x) ((x)*(x))
int dis(Point a,Point b){
    return (a-b).len();
}

sta getSta(Point a,Point b){
    int dx = a.x - b.x,dy = a.y - b.y;
    if(dy == 0) return make_pair(a.y,make_pair(0,0));
    if(dx == 0) return make_pair(a.x,make_pair(0,1));
    if(dx < 0){
        dx *= -1,dy *= -1;
    }
    int d = __gcd(abs(dx),abs(dy));
    dx /= d,dy /= d;
    int var = (a.y % dy + dy ) % dy;
    var = a.x + (var - a.y) / dy * dx;
    return make_pair(var,make_pair(dx,dy));
}
sta mimorSta(Point a,Point b){
    Point mid = (a + b) / 2,off = a - b;
    swap(off.x,off.y), off.x *= -1;
    return getSta(mid + off,mid - off);
}

map<sta,vector<pair<int,int>>>M;
map<sta,vector<int>>anw;

int getAns(sta s,int v){
    if(M.find(s) == M.end()) return 0; 
    vector<pair<int,int> > & use = M[s];
    int st = upper_bound(use.begin(),use.end(),make_pair(v,1)) - use.begin(); // 1?
    int ret = 0;
    return anw[s][st];
}

const int maxn = 2123;
Point ctr[maxn];
int r[maxn];

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    Point a,b;
    while(n--){
        a.inp(),b.inp();
        a = 2 * a,b = 2 * b;
        if(a.x != b.x){
            M[getSta(a,b)].push_back(make_pair(min(a.x,b.x),1));
            M[getSta(a,b)].push_back(make_pair(max(a.x,b.x)+1,-1));
        }
        else{
            M[getSta(a,b)].push_back(make_pair(min(a.y,b.y),1));
            M[getSta(a,b)].push_back(make_pair(max(a.y,b.y)+1,-1));
        }
    }
    for(auto & it : M){
        sort(it.second.begin(),it.second.end());
        vector<int> & ver = anw[it.first];
        int x = 0;
        ver.push_back(x);
        for(auto d : it.second){
            x += d.second;
            ver.push_back(x); // cal ?
        }
    }
    for(int i = 0;i<m;i++){
        ctr[i].inp();
        scanf("%d",&r[i]);
        ctr[i] = 2 * ctr[i];
        r[i] <<= 1;
    }
    int ans = 0;
    for(int i = 0;i<m;i++){
        for(int j = i + 1;j<m;j++){
            if(r[i] == r[j] && dis(ctr[i],ctr[j]) > sqr(r[i]+r[j])){
                int mid;
                if(ctr[i].y == ctr[j].y) mid = ctr[i].y ;
                else mid = (ctr[i].x+ctr[j].x) >> 1;
                ans += getAns(mimorSta(ctr[i],ctr[j]),mid);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}


