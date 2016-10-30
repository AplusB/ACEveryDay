#define sta pair<int,pair<int,int> >
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
