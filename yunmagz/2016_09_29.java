//HDU 3723 Delta Wave
import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Main {
	
	static BigInteger [][]dp=new BigInteger[2][3];
	public static void main(String args[])
	{
		Scanner in=new Scanner(System.in);
		PrintWriter out=new PrintWriter(System.out);
		int n;
		while(in.hasNextInt())
		{
			n=in.nextInt();
			BigInteger ans=BigInteger.ONE;  
	        BigInteger tmp=BigInteger.ONE;
	        for(int i=0;i<n/2;i++)  
            {  
                tmp=tmp.multiply(BigInteger.valueOf(n-2*i)).multiply(BigInteger.valueOf(n-2*i-1)).divide(BigInteger.valueOf(i+1)).divide(BigInteger.valueOf(i+2));
                ans=ans.add(tmp);
            }
			out.println(ans.mod(BigInteger.TEN.pow(100)));
		}
		
		in.close();
		out.flush();
		out.close();
	}
	
	
}
