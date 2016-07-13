public class Solution {
    /**
     * @param numbers : Give an array numbersbers of n integer
     * @param target : you need to find four elements that's sum of target
     * @return : Find all unique quadruplets in the array which gives the sum of
     *           zero.
     */
    public ArrayList<ArrayList<Integer>> fourSum(int[] numbers, int target) {
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();

        Arrays.sort(numbers);
        if (numbers.length == 0)
            return ans;
        for (int i = 0; i < numbers.length; ++i) {
            if (i != 0 && numbers[i] == numbers[i - 1])
                continue;
            for (int j = i+1; j < numbers.length; ++j) {
                if (j != i + 1 && numbers[j] == numbers[j - 1])
                    continue;
                int left = j + 1, right = numbers.length - 1;
                int currentTarget = target - numbers[i] - numbers[j];

                while (left < right) {
                    if (numbers[left] + numbers[right] == currentTarget) {
                        ArrayList<Integer> tmpArray = new ArrayList<>();
                        ans.add(new ArrayList<Integer>(Arrays.asList(numbers[i], numbers[j], numbers[left], numbers[right])));
                        --right;
                        ++left;
                        while (left < right && numbers[left] == numbers[left - 1]) {
                            ++left;
                        }
                    }
                    else if (numbers[left] + numbers[right] > currentTarget) {
                        --right;
                    }
                    else {
                        ++left;
                    }
                }
            }
        }
        return ans;
    }
}
