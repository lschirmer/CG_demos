import java.math.BigInteger;
import java.util.Scanner;

class Main{
    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);
		while (true) {
			int N = 0;
			int A = 0;
            try {
                N = teclado.nextInt();
                A = teclado.nextInt();
            } catch (Exception ex) {
                return;
            }
            BigInteger reallyBig = new BigInteger("0");
            for (int i = 1; i <= N; i++) {
                BigInteger r1 = new BigInteger(String.valueOf(A));
                r1 = r1.pow(i);
                r1 = r1.multiply(new BigInteger(String.valueOf(i)));
                reallyBig = reallyBig.add(r1);
            }
            System.out.println(reallyBig.toString());
        }
    }
}
