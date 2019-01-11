#include<bits/stdc++.h>
//DP
// dp[i][j] represents the optimal solution for s1[i:] and s2[j:]

using namespace std;
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
      int m = s1.size()+1;
      int n = s2.size()+1;
      vector<vector<int>> dp(m,vector<int>(n,0));

      for(int i = s1.size()-1;i>=0;--i){
        dp[i][s2.size()] = dp[i+1][s2.size()] + int(s1.at(i));
      }

      for(int i = s2.size()-1;i>=0;--i){
        dp[s1.size()][i]=dp[s1.size()][i+1] + int(s2.at(i));
      }

      for(int i = s1.size()-1;i>=0;--i){
        for(int j = s2.size()-1;j>=0;--j){
          if(s1.at(i)==s2.at(j)){
            dp[i][j] = dp[i+1][j+1];
          }else{
            dp[i][j] = min(dp[i+1][j] + int(s1.at(i)),dp[i][j+1]+int(s2.at(j)));
          }
        }
      }

      return dp[0][0];
    }
};