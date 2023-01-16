import java.io.*;
import java.util.*;

public class Main {
  public static ArrayList<Pair> arr = new ArrayList<Pair>();

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(br.readLine());
    int [] a = new int [n+1];
    int [] b = new int [n+1];

    a[0] = 0;
    b[0] = 0;

    for (int i=1;i<=n;i++)
    {
      StringTokenizer st = new StringTokenizer(br.readLine());
      a[i] = Integer.parseInt(st.nextToken());
      b[i] = Integer.parseInt(st.nextToken());
    }
    
    

    for (int i=0;i<=n;i++)
    {
      for (int j=i+1;j<=n;j++)
      {
        int temp = (a[i]-a[j]) * (a[i] - a[j]) + (b[i]-b[j])*(b[i] - b[j]);
        arr.add(new Pair(temp,i,j));
        /*if (i != 0)
        {
          arr.add(new Pair(temp,j,i));;
        }*/
      }
    }
    Collections.sort(arr);

    int [] current= new int [n+1];
    int [] prev = new int [n+1];
    int [] dist = new int [n+1];

    for (int i=0;i<arr.size();i++)
    {
      if (arr.get(i).dist != dist[arr.get(i).a])
      {
        dist[arr.get(i).a] = arr.get(i).dist;
        prev[arr.get(i).a] = current[arr.get(i).a];
      }
      if (arr.get(i).dist != dist[arr.get(i).b])
      {
        dist[arr.get(i).b] = arr.get(i).dist;
        prev[arr.get(i).b] = current[arr.get(i).b];
      }

      if(arr.get(i).a == 0)
      {
        current[arr.get(i).a] = Math.max(current[arr.get(i).a], prev[arr.get(i).b]);
      }
      else
      {
        current[arr.get(i).a] = Math.max(current[arr.get(i).a], prev[arr.get(i).b] + 1);
        current[arr.get(i).b] = Math.max(current[arr.get(i).b], prev[arr.get(i).a] + 1);
      }
    }
    System.out.println(current[0] + 1);

    /*
    System.out.println();

    for (int i=0;i<=n;i++)
    {
      System.out.println(a[i] + " " + b[i]);
    }
    for (int i=0;i<arr.size();i++)
    {
      System.out.println(arr.get(i).dist+" "+arr.get(i).a+" "+arr.get(i).b);
    }*/

    
  }

  static class Pair implements Comparable<Pair>
  {
    int dist;
    int a, b;
    Pair (int d0, int a0, int b0)
    {
      dist=d0;
      a=a0;
      b=b0;
    }
    public int compareTo(Pair o)
    {
      if(this.dist > o.dist) return 1;
      else if(this.dist == o.dist) return 0;      
      else return -1;
    }
  }
}
