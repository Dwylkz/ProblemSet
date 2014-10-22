import java.io.*;

public class Tester {

	public static void main(String[] args) throws Exception {
		File dir = new File("src/test");
		for (File file: dir.listFiles()) {
			System.out.println(file.getName());
			System.setIn(new FileInputStream(file));
			Main.main(new String[]{"test"});
		}
	}

}