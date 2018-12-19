#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> res;
      vector<int> subres;
      subSum(subres,candidates,target,res,0);
      return res;

    }

    void subSum(vector<int>& subres ,vector<int>& candidates,int target,vector<vector<int>>& res, int start){
      if(target==0){
        res.push_back(subres);
        return;
      }

      for(int i = start;i < candidates.size();++i){
        if(target<candidates[i]){
          continue;
        }
        subres.push_back(candidates[i]);
        subSum(subres,candidates,target-candidates[i],res,i);
        subres.pop_back();
      }
    }
};