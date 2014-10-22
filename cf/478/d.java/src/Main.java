import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(
				new BufferedReader(
						new InputStreamReader(System.in), 32768));
		PrintWriter out = new PrintWriter(System.out);
		Routine routine = new Routine();
		routine.run(in, out);
		out.flush();
	}
}

class Routine {
	static final int MOD = (int)1e9+7;
	
	int r, g;

	int G(int x) {
		return x*(x+1)/2;
	}
	
	int[][] memo;
	int F(int h, int th, int tr) {
		if (tr < 0 || g-(G(h)-G(th)-(r-tr)) < 0) {
			return 0;
		}
		
		if (th == 0) {
			return 1;
		}
		
		if (memo[th][tr] != -1) {
			return memo[th][tr];
		}
		
		memo[th][tr] = (F(h, th-1, tr)+F(h, th-1, tr-th))%MOD;
		return memo[th][tr];
	}
	
	public void run(Scanner in, PrintWriter out) {
		r = in.nextInt();
		g = in.nextInt();
		
		int h = 1;
		while (G(h) <= r+g) {
			h++;
		}
		
		memo = new int[h][r+1];
		
		/*int lb = 1, rb = h;
		while (lb < rb) {
			int m = (lb+rb)/2;
			for (int i = 0; i < h; i++) {
				Arrays.fill(memo[i], -1);
			}
			
			if (F(m, m, r) > 0) {
				lb = m+1;
			}
			else {
				rb = m;
			}
		}
		out.printf("%d\n", F(rb-1, rb-1, r));*/
		out.printf("%d\n");
	}
}