public class Solution {
    /**
     * @param nums: a list of integers
     * @return: find a  majority number
     */
    public int majorityNumber(ArrayList<Integer> nums) {
        int cnt = 1, curNum = nums.get(0);
        for (int num : nums) {
            if (num == curNum)
                ++cnt;
            else 
                --cnt;
            if (cnt == 0) {
                curNum = num;
                cnt = 1;
            }
        }
        return curNum;
    }
}
