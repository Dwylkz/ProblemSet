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
	int n;
	
	public void run(Scanner in, PrintWriter out) {
		n = in.nextInt();
		Map<Integer, TreeSet<Integer>> map = new TreeMap<>();
		for (int i = 0; i < n; i++) {
			int ai, bi;
			ai = in.nextInt();
			bi = in.nextInt();
			if (!map.containsKey(ai)) {
				map.put(ai, new TreeSet<>());
			}
			map.get(ai).add(ai);
			if (!map.containsKey(bi)) {
				map.put(bi, new TreeSet<>());
			}
			map.get(bi).add(ai);
		}
		
		List<Integer> as = new ArrayList<>();
		List<Integer> ds = new ArrayList<>();
		for (Map.Entry<Integer, TreeSet<Integer>> entry: map.entrySet()) {
			as.addAll(entry.getValue());
			for (int i = 0; i < entry.getValue().size(); i++) {
				ds.add(entry.getKey());
			}
		}
		
		out.println(as);
		out.println(ds);
		
		int[] fs = new int[as.size()];
		for (int i = 0; i < as.size(); i++) {
			int maxval = 1;
			for (int j = 0; j < i; j++) {
				if (as.get(j) < as.get(i)) {
					maxval = Math.max(maxval, fs[j]+1);
				}
			}
			fs[i] = maxval;
			if (fs[i] == n) {
				out.println(ds.get(i));
				return ;
			}
		}
		
		throw new RuntimeException();
	}
}