class Solution {
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    public int[] mergeSortedArray(int[] A, int[] B) {
        // Write your code here
        int len1 = A.length, len2 = B.length;
        int pos1 = 0, pos2 = 0, pos = 0;

        int[] buffer = new int[A.length + B.length];
        while (pos1 < len1 && pos2 < len2)
            buffer[pos++] = A[pos1] < B[pos2] ? A[pos1++] : B[pos2++];
        while (pos1 < len1)
            buffer[pos++] = A[pos1++];
        while (pos2 < len2)
            buffer[pos++] = B[pos2++];

        return buffer;
    }
}

