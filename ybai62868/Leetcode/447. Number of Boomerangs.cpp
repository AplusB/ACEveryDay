class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int len = points.size();
        int res = 0;
        for ( int i = 0;i < len;i++ ) {
            map<int,int>MP;
            for ( int j = 0;j < len;j++ ) {
                int dx = points[i].first - points[j].first;
                int dy = points[i].second - points[j].second;
                ++MP[dx*dx+dy*dy];
            }
            for ( auto it = MP.begin();it!=MP.end();it++ ) {
                res += it->second*(it->second-1);
            }
        }
        return res;
    }
};
