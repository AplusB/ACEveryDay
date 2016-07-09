public class Solution {
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */

    private boolean binarySearch(int[] arr, int l, int r, int target) {
        while (l < r) {
            int mid = l + (r - l)/2;
            if (arr[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return l != arr.length && arr[l] == target;
    }

    public ArrayList<ArrayList<Integer>> threeSum(int[] numbers) {
        ArrayList<ArrayList<Integer>> ret = new ArrayList<>();
        if (numbers.length == 0)
            return ret;

        Arrays.sort(numbers);
        for (int i = 0; i < numbers.length; ++i) {
            if (i != 0 && numbers[i] == numbers[i - 1])
                continue;
            for (int j = i+1; j < numbers.length; ++j) {
                if (j - i > 1 && numbers[j] == numbers[j - 1])
                    continue;
                int target = numbers[i] + numbers[j];
                target = -target;
                if (binarySearch(numbers, j+1, numbers.length, target)) {
                    ret.add(new ArrayList<Integer>(Arrays.asList(numbers[i], numbers[j], target)));
                }
            }
        }
        return ret;
    }
}
