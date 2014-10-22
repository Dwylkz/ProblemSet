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
	int n, l, x, y;
	int[] as = new int[200_005];
	
	public void run(Scanner in, PrintWriter out) {
		n = in.nextInt();
		l = in.nextInt();
		x = in.nextInt();
		y = in.nextInt();
		
		for (int i = 0; i < n; i++) {
			as[i] = in.nextInt();
		}
		
		int mask = 3;
		
		Set<Integer> set = new TreeSet<>();
		for (int i = 0; i < n; i++) {
			set.add(as[i]);
			if (set.contains(as[i]-x)) {
				mask &= ~1;
			}
			if (set.contains(as[i]-y)) {
				mask &= ~2;
			}
		}
		
		if (mask == 0) {
			out.println(0);
			return ;
		}
		
		if (mask == 1) {
			out.println(1);
			out.println(x);
			return ;
		}
		
		if (mask == 2) {
			out.println(1);
			out.println(y);
			return ;
		}
		
		for (int i = 0; i < n; i++) {
			if (set.contains(as[i]-(x+y))) {
				out.println(1);
				out.println(as[i]-x);
				return ;
			}
			
			if (set.contains(as[i]-(y-x))) {
				if (as[i]+x <= l) {
					out.println(1);
					out.println(as[i]+x);
					return ;
				}
				
				if (as[i]-(y-x)-x >= 0) {
					out.println(1);
					out.println(as[i]-(y-x)-x);
					return ;
				}
			}
		}
		
		out.println(2);
		out.println(x+" "+y);
	}
}