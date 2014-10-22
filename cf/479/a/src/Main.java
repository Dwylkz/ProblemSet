import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(
				new BufferedReader(
						new InputStreamReader(System.in)));
		PrintWriter out = new PrintWriter(System.out);
		Routine routine = new Routine();
		routine.run(in, out);
		out.flush();
	}
}

class Routine {
	int a, b, c;
	public void run(Scanner in, PrintWriter out) {
		a = in.nextInt();
		b = in.nextInt();
		c = in.nextInt();
		int[] maxs = new int[]{
				a+b+c, (a+b)+c, a+(b+c),
				a+b*c, (a+b)*c, a+(b*c),
				a*b+c, (a*b)+c, a*(b+c),
				a*b*c, (a*b)*c, a*(b*c),
				};
		int maxval = 0;
		for (int i: maxs) {
			maxval = Math.max(maxval, i);
		}
		out.println(maxval);
	}
}