public class Solution {
    /**
     * @param nums: A list of integers.
     * @return: the median of numbers
     */
    public int[] medianII(int[] nums) {
        Comparator<Integer> desc = new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                if (o1 > o2)
                    return -1;
                else if (o1 == o2)
                    return 0;
                return 1;
            }
        };

        Queue<Integer> Q2 = new PriorityQueue<>();
        Queue<Integer> Q1 = new PriorityQueue<Integer>(11, desc);

        int pos = 0;
        int[] ans = new int[nums.length];
        for (int num : nums) {
            if (Q1.isEmpty() || num <= Q1.peek()) {
                Q1.offer(num);
                if (Q1.size() - 1 > Q2.size()) {
                    Q2.offer(Q1.poll());
                }
            }
            else if (num > Q1.peek()) {
                Q2.offer(num);
                if (Q2.size() - Q1.size() > 0) {
                    //System.out.println(Q2.peek());
                    Q1.offer(Q2.poll());
                    //System.out.println(Q1.peek());
                }
            }

            ans[pos++] = Q1.peek();
        }
        return ans;
    }
}

