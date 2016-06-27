class Solution {
public:
    bool isPerfectSquare(int num) {
        if ( num==1 ) return true;
        if ( num < 1 ) return false;
        int lo = 1;
        int hi = num/2;
        long long mid;
        while ( lo <= hi ){
            mid = (lo+hi)>>1;
            if ( mid*mid == num ) return true;
            else if ( mid*mid < num) lo = mid+1;
            else hi = mid-1;
        }
        return false;
    }
};
