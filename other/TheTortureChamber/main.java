import java.util.*;
import java.io.*;
public class Main {
  public static void main(String[] args) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    long start = Long.parseLong(br.readLine());
    long end = Long.parseLong(br.readLine());
    int diff = (int) (end - start);
    long total = 0;
    boolean [] isPrime = new boolean [diff];
    
    LinkedList<Integer> yes = new LinkedList<Integer>();


    
    Arrays.fill(isPrime, true);

    if(start==1)
    {
      total--;
    }

    for (int i=2;i<Math.sqrt(end);i++)
    {
      if(Prime(i))
      {
        yes.add(i);
      }
    }
    //System.out.println(yes);
    while (!yes.isEmpty())
    {
      int curPrime=yes.poll();
      long newPos=(long)(Math.ceil((double)start/(double)curPrime)*curPrime);
			while(newPos<end)
			{
				if(newPos!=curPrime)
				{
					isPrime[(int)(newPos-start)]=false;
				}
				newPos+=curPrime;
			}
    }
    
    for (int i=0;i<diff;i++)
    {
      if(isPrime[i])
      {
        //System.out.println(i);
        total++;
      }
    }
    System.out.println(total);
  
  }
  static boolean Prime(int n) 
    { 
        if (n <= 1) 
            return false; 
        if (n <= 3) 
            return true; 
        if (n % 2 == 0 || n % 3 == 0) 
            return false; 
  
        for (int i = 5; i * i <= n; i = i + 6) 
            if (n % i == 0 || n % (i + 2) == 0) 
                return false; 
  
        return true; 
    } 
}
