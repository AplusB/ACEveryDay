/*
 * 递推丑数，找出最小的一个增加一个因子。
 */
class Solution {
    /**
     * @param n an integer
     * @return the nth prime number as description.
     */
    public int nthUglyNumber(int n) {
        // Write your code here
        int pos2 = 1, pos3 = 1, pos5 = 1;
        int num2 = 2, num3 = 3, num5 = 5;
        List<Integer> arr = new ArrayList<>();
        arr.add(1);
        while (arr.size() < n) {
            int currentNumber = Math.min(num2, Math.min(num3, num5));
            arr.add(currentNumber);
            if (num2 == currentNumber)
                num2 = 2 * arr.get(pos2++);
            if (num3 == currentNumber)
                num3 = 3 * arr.get(pos3++);
            if (num5 == currentNumber)
                num5 = 5 * arr.get(pos5++);
        }
        return arr.get(arr.size() - 1);
    }
};

