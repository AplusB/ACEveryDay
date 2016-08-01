import java.io.*;
import java.util.*;

public class Solution {
	static int n;
	static int[] a = new int[100005];
	static int[] b = new int[100005];
	static int d;
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		d = in.nextInt();
		d = d % n;
		for(int i=0; i<n; i++) a[i] = in.nextInt();
		for(int i=d; i<n; i++) b[i-d] = a[i];
		for(int i=0; i<d; i++) b[n-d+i] = a[i];
		for(int i=0; i<n; i++){
			System.out.print(b[i] + " ");
		}
	}
}
