import java.util.*;
import java.io.*;
public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    
    String[] temp = in.readLine().split(" ");
    
    int n = Integer.parseInt(temp[0]);
    long gen = Long.parseLong(temp[1]);

    String xd = in.readLine();
    int[] nodes = new int[n];

    for (int i=0;i<n;i++)
    {
      nodes[i] = xd.charAt(i) - 48;
    }

    while(gen>0)
    {
      long skip = (gen&-gen);
      gen = gen - skip;
      int[] sim = new int[n];
      for (int i=0;i<n;i++)
      {
        sim[i] = nodes[(int)((i + skip) % n)] ^ nodes[(int)((i + n - skip%n)%n)];
      }
      for (int i=0;i<n;i++)
      {
        nodes[i] = sim[i];
      }
    }
    for (int i=0;i<n;i++)
    {
      System.out.print(nodes[i]);
    }

  }
}