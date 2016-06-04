public class Solution {
    /**
     * @param nums: A list of integers
     * @return: The majority number that occurs more than 1/3
     */
    public int majorityNumber(ArrayList<Integer> nums) {

        if (nums.size() == 1) return nums.get(0);

        int firstNum = 0, secondNum = 0;
        int firstCnt = 0, secondCnt = 0;

        for (int i = 0; i < nums.size(); ++i) {
            int u = nums.get(i);
            if (firstCnt == 0) {
                firstNum = u;
            }
            if (secondCnt == 0 && firstNum != u) {
                secondNum = u;
            }

            if (u != firstNum && u != secondNum && secondCnt != 0) {
                --firstCnt;
                --secondCnt;
            }

            if (u == firstNum)
                ++firstCnt;
            if (u == secondNum)
                ++secondCnt;
        }
        int cnt = 0;
        for (int u : nums) if (u == firstNum)
            ++cnt;
        return cnt > nums.size() / 3 ? firstNum : secondNum;
    }
}

