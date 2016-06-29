public class Solution {
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1 + 1, index2 + 1] (index1 < index2)
     */
    public int[] twoSum(int[] numbers, int target) {
        Map<Integer, Integer> mp = new HashMap<>();

        for (int i = 0; i < numbers.length; ++i) {
            int num = numbers[i];
            if (mp.containsKey(target - num)) {
                return new int[]{mp.get(target - num), i+1};
            }
            mp.put(num, i + 1);
        }
        return null;
    }
}
