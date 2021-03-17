import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Collections;
import java.util.Set;

public class AOC6 {

    public static void main(String[] args) {
        int count = 0;
        BufferedReader reader;
		try {
			reader = new BufferedReader(new FileReader("input6.txt"));
            String line = reader.readLine();
            Set<String> answers = Collections.<String>emptySet();
			while (line != null) {
                while(line != ""){
                    for(char s : line.toCharArray()){
                      answers.add(String.valueOf(s));
                    }
                }
                count += answers.size();
				answers.clear();
				line = reader.readLine();
			}
			reader.close();
		} catch (IOException e) {
			e.printStackTrace();
        }
  
        System.out.println("Count: " + count);
    }
}