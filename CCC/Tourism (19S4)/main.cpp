#include <iostream>
#include <vector>
#include <bits/stdc++.h>
int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector <long long> dp;
  std::vector <long long> tour;
  std::vector <long long> local;
  for (int i=0;i<n;i++)
  {
    int xd;
    std::cin >> xd;
    tour.push_back(xd);
    dp.push_back(0);
    local.push_back(0);
  }


  //i % k is number of attractions that must be visited per day
  //
  for (int i=0;i<n; i+=k)
  {
    local[i] = tour [i];
    for (int j=i+1;j<std::min(n, i + k);j++)
    {
      local[j] = std::max(tour[j], local[j-1]); 
    }
  }

  for (int i=0;i<n;i += k)
  {
    long long cur = tour[i];
    /*for(int j=i;j>i-i%k;j--)
    {
      cur = std::max(cur, tour[j]);
    }*/
    for (int l = 0, j = std::min(n - 1, i + k - 1); j >= i; j--)
    {
      if (cur <= local[j + 1])
      {
        dp[j] = dp[j + 1] - (local[j+1] - local[j]);  
      }
      else 
      {
        dp[j] = dp[j+1];
      }
      while(i-l >= std::max(0, j - k + 1))
      {
        assert(i >= l); //if i >= l is false break
        cur = std::max(cur, tour[i - l]);
        dp[j] = std::max(dp[j], std::max(local[j], cur) + (i == l ? 0 : dp[i - l - 1]));
        ++l;
      }
    }
  }

  std::cout << dp[n-1];
}
