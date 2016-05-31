/*
 * 也是很经典的题了，考虑每位的贡献即可。
 */
class Solution {
    /*
     * param k : As description.
     * param n : As description.
     * return: An integer denote the count of digit k in 1..n
     */
    public int digitCounts(int k, int n) {
        // write your code here
        if (n < 0) 
            return 0;
        if (n == 0 && k == 0)
            return 1;
        int pre = n / 10;
        int mid = n % 10;
        int last = 0, weigh = 1;


        int ans = 0;
        while (n != 0) {
            if (pre == 0 && k == 0)
                break;
            if (mid < k)
                ans += pre * weigh;
            else if (mid == k) {
                ans += pre * weigh + last + 1;
            }
            else 
                ans += (pre + 1) * weigh;
            last = n%10*weigh + last;
            n /= 10;
            mid = n % 10;
            pre = n / 10;
            weigh *= 10;
        }

        return ans;
    }
}
