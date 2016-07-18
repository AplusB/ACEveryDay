public class Solution {
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target : An integer
     * @return : return the sum of the three integers, the sum closest target.
     */
    public int threeSumClosest(int[] numbers, int target) {
        int ans = 0;
        int diff = Integer.MAX_VALUE;
        Arrays.sort(numbers);

        for (int i = 2; i < numbers.length; ++i) {
            int realTar = target - numbers[i];
            int l = 0, r = i - 1;

            while (l < r) {
                if (numbers[l] + numbers[r] >= realTar) {
                    if (Math.abs(numbers[l] + numbers[r] - realTar) < diff) {
                        diff = Math.abs(numbers[l] + numbers[r] - realTar);
                        ans = numbers[l] + numbers[r] + numbers[i];
                    }
                    --r;
                }
                else {
                    if (Math.abs(numbers[l] + numbers[r] - realTar) < diff) {
                        diff = Math.abs(numbers[l] + numbers[r] - realTar);
                        ans = numbers[l] + numbers[r] + numbers[i];
                    }
                    ++l;
                }
            }
        }
        return ans;
    }
}

