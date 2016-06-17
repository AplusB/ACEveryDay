class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if ( n==0 ) return 1;
        vector<int>res(n);
        res[0] = 9;
        for ( int i = 1;i < n;i++ )
        {
            res[i] = res[i-1]*(10-i);
        }
        long long sum = 0;
        for( int i = 0;i < n;i++ )
        {
            sum+=res[i];
        }
        sum++;
        return sum;
    }
};
