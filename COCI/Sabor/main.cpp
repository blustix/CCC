#include <iostream>
#include <queue>
#include <array>
int main() {
  
  int b, s;
  std::cin >> b;
  std::cin >> s;

  long even = 0;
  long odd = 0;

  std::vector<std::vector<int>> step;
  std::vector<std::vector<int>> map;
  
  for(int i=0;i<2003;i++)
  {
    step.push_back(std::vector<int>());
    map.push_back(std::vector<int>());

    for (int j=0;j<2003;j++)
    {
      step[i].push_back(1<<30);
      map[i].push_back(0);
    }
  }

  for (int i=0;i<b;i++)
  {
    int x,y;
    std::cin >> y;
    std::cin >> x;
    y = 1001 - y;
    x = 1001 + x;
    map [y][x] = (1<<30);
  }
  std::queue<int> q;
  step[1001][1001] = 0;
  q.push(1001);
  q.push(1001); 
  
  while(!q.empty())
  {
    int y = q.front();
    q.pop();
    int x = q.front();
    q.pop();

    if(step[y][x]%2 == 1 && step[y][x] <= s)
    {
      odd++;
    }
    else if (step[y][x] <= s)
    {
      even++;
    }

    if(y + 1 < 2003)
    {
    if (map[y+1][x] != (1<<30) && step[y+1][x] > step[y][x] + 1)
    {
      step[y+1][x] = step[y][x] + 1;
      q.push(y+1);
      q.push(x);

    }
    }
    if(y - 1  >= 0)
    {
    if (map[y-1][x] != (1<<30) && step[y-1][x] > step[y][x] + 1)
    {
      step[y-1][x] = step[y][x] + 1;
      q.push(y-1);
      q.push(x);
    }
    }
    if(x + 1 < 2003)
    {
    if(map[y][x+1] != (1<<30) && step[y][x+1] > step[y][x] + 1)
    {
      step[y][x+1] = step[y][x] + 1;
      q.push(y);
      q.push(x+1);
    }
    }
    if(x - 1 >= 0)
    {
    if(map[y][x-1] != (1<<30) && step[y][x-1] > step[y][x] + 1)
    {
      step[y][x-1] = step[y][x] + 1;
      q.push(y);
      q.push(x-1);
    }
    }
  }
  
  for (int i=0;i<2003;i++)
  {
    if (step[0][i] < s && step[0][i] != (1<<30))
    {
      int temp = s - step[0][i];
      if (temp % 2 == 0)
      {
        temp = temp/2;
        odd+=temp;
        even+=temp;
      }
      else
      {
        temp = temp/2;
        if (step[0][i] % 2 == 0)
        {
          odd+=temp + 1;
          even+=temp;
        }
        else
        {
          odd+= temp;
          even+= temp + 1;
        }
      }
    }

    if (step[i][0] < s)
    {
      int temp = s - step[i][0];
      if (temp % 2 == 0)
      {
        temp = temp/2;
        odd+=temp;
        even+=temp;
      }
      else
      {
        temp = temp/2;
        if (step[i][0] % 2 == 0)
        {
          odd+=temp + 1;
          even+=temp;
        }
        else
        {
          odd+= temp;
          even+= temp + 1;
        }
      }
    }
    if (step[2002][i] < s)
    {
      int temp = s - step[2002][i];
      if (temp % 2 == 0)
      {
        temp = temp/2;
        odd+=temp;
        even+=temp;
      }
      else
      {
        temp = temp/2;
        if (step[2002][i] % 2 == 0)
        {
          odd+=temp + 1;
          even+=temp;
        }
        else
        {
          odd+= temp;
          even+= temp + 1;
        }
      }
    }
    
    if (step[i][2002] < s)
    {
      int temp = s -  step[i][2002];
      if (temp % 2 == 0)
      {
        temp = temp/2;
        odd+=temp;
        even+=temp;
      }
      else
      {
        temp = temp/2;
        if (step[i][2002] % 2 == 0)
        {
          odd+=temp + 1;
          even+=temp;
        }
        else
        {
          odd+= temp;
          even+= temp + 1;
        }
      }
    }
    
  }
  if (step[0][0] + 1 < s)
  {
    long temp, sum1, sum2;
    temp = s - (step[0][0]+1);
    if (temp%2 == 0)
    {
      temp = temp/2;
      long last = 1 + ((temp-1) * 2);
      sum1 = (1 + last)/2 * temp; 
      last = 2 + ((temp-1) * 2);
      sum2 = (2 + last)/2 * temp; 
    }
    else
    {
      temp = temp/2;
      long last = 1 + ((temp) * 2);
      sum1 = (1 + last)/2 * (temp+1); 
      last = 2 + ((temp-1) * 2);
      sum2 = (2 + last)/2 * temp; 
    }

    if(step[0][0]%2 == 0)
    {
      even+=sum1;
      odd+=sum2;
    }
    else
    {
      even+=sum2;
      odd+=sum1;
    }
  }
  if (step[0][2002] + 1 < s)
  {
    long temp, sum1, sum2;
    temp = s - (step[0][2002]+1);
    if (temp%2 == 0)
    {
      temp = temp/2;
      long last = 1 + ((temp-1) * 2);
      sum1 = (1 + last)/2 * temp; 
      last = 2 + ((temp-1) * 2);
      sum2 = (2 + last)/2 * temp; 
    }
    else
    {
      temp = temp/2;
      long last = 1 + ((temp) * 2);
      sum1 = (1 + last)/2 * (temp+1); 
      last = 2 + ((temp-1) * 2);
      sum2 = (2 + last)/2 * temp; 
    }

    if(step[0][2002]%2 == 0)
    {
      even+=sum1;
      odd+=sum2;
    }
    else
    {
      even+=sum2;
      odd+=sum1;
    }
  }
  if (step[2002][0] + 1 < s)
  {
    long temp, sum1, sum2;
    temp = s - (step[2002][0]+1);
    if (temp%2 == 0)
    {
      temp = temp/2;
      long last = 1 + ((temp-1) * 2);
      sum1 = (1 + last)/2 * temp; 
      last = 2 + ((temp-1) * 2);
      sum2 = (2 + last)/2 * temp; 
    }
    else
    {
      temp = temp/2;
      long last = 1 + ((temp) * 2);
      sum1 = (1 + last)/2 * (temp+1); 
      last = 2 + ((temp-1) * 2);
      sum2 = (2 + last)/2 * temp; 
    }

    if(step[2002][0]%2 == 0)
    {
      even+=sum1;
      odd+=sum2;
    }
    else
    {
      even+=sum2;
      odd+=sum1;
    }
  }
  if (step[2002][2002] + 1 < s)
  {
    long temp, sum1, sum2;
    temp = s - (step[2002][2002]+1);
    if (temp%2 == 0)
    {
      temp = temp/2;
      long last = 1 + ((temp-1) * 2);
      sum1 = (1 + last)/2 * temp; 
      last = 2 + ((temp-1) * 2);
      sum2 = (2 + last)/2 * temp; 
    }
    else
    {
      temp = temp/2;
      long last = 1 + ((temp) * 2);
      sum1 = (1 + last)/2 * (temp+1); 
      last = 2 + ((temp-1) * 2);
      sum2 = (2 + last)/2 * temp; 
    }

    if(step[2002][2002]%2 == 0)
    {
      even+=sum1;
      odd+=sum2;
    }
    else
    {
      even+=sum2;
      odd+=sum1;
    }
  }

  std::cout << even << " " << odd;

}
