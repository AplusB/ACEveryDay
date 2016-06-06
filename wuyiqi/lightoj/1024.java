import java.util.*;
import java.math.*;
import java.io.*;
class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        AC solver = new AC();
        solver.solve(in, out);
        out.close();
    }
}

class AC {
	InputReader in;
	PrintWriter out;
        public void solve(InputReader in, PrintWriter out) {
                this.in = in; this.out = out;
                int T, ca = 1;
                T = in.nextInt();
                while(T-- > 0) {
                        System.out.print("Case " + ca + ": ");
                        ca++;
                        int n = in.nextInt();
                        BigInteger ret = BigInteger.valueOf(1);
                        BigInteger x = BigInteger.ZERO, gcd = BigInteger.ZERO;
                        for(int i = 0; i < n; i++) {
                                x = in.nextBigInteger();
                                gcd = ret.gcd(x);
                                ret = ret.divide(gcd).multiply(x);
                        }
                        System.out.println(ret);
                }
        }
}
class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;
        public InputReader(InputStream stream) {
                reader = new BufferedReader(new InputStreamReader(stream));
                tokenizer = null;
        }

        public String next() {
                if (!hasNext())
                        throw new RuntimeException();
                return tokenizer.nextToken();
        }

        boolean hasNext() {
                while (tokenizer == null || !tokenizer.hasMoreTokens())
                        try {
                                tokenizer = new StringTokenizer(reader.readLine());
                        } catch (Exception e) {
                                return false;
                        }
                return true;
        }

        public int nextInt() {
                return Integer.parseInt(next());
        }

        public double nextDouble() {
                return Double.parseDouble(next());
        }

        public long nextLong() {
                return Long.parseLong(next());
        }
        public BigInteger nextBigInteger() {
                return new BigInteger(next());
        }
}

