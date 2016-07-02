class Solution {
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: a double whose format is *.5 or *.0
     */
    public double findMedianSortedArrays(int[] A, int[] B) {
        int m = A.length, n = B.length;
        int k = (m + n)/2;
        if ((m + n) % 2 == 1) {
            return getKth(A, B, 0, 0, m, n, k+1);
        }
        return (getKth(A, B, 0, 0, m, n, k) + getKth(A, B, 0, 0, m, n, k+1))/2;
    }

    private double getKth(int[] A, int[] B, int start1, int start2, int len1, int len2, int k) {
        if (len1 > len2)
            return getKth(B, A, start2, start1, len2, len1, k);
        if (len1 == 0)
            return B[start2 + k - 1];
        if (k == 1)
            return Math.min(A[start1], B[start2]);

        int pos1 = Math.min(k/2, len1);
        int pos2 = k - pos1;
        if (A[start1 + pos1 - 1] < B[start2 + pos2 - 1])
            return getKth(A, B, start1+pos1, start2, len1-pos1, len2, pos2);
        else if (A[start1 + pos1 - 1] > B[start2 + pos2 - 1])
            return getKth(A, B, start1, start2+pos2, len1, len2-pos2, pos1);
        else
            return (double) A[start1 + pos1 - 1];
    }
}

