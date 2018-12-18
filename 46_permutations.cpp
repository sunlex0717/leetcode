//https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> result;

        backtrack(result,nums,0,len);
        return result;
        
    }
    
    void backtrack(vector<vector<int>>& result,vector<int>& tmp, int start, int end){
      int i = 0;
      if(start == end){
        result.push_back(tmp);
      }
      else{
        for(i = start; i<end;++i){
          swap(tmp[start],tmp[i]);
          backtrack(result,tmp,start+1,end);
          swap(tmp[start],tmp[i]); //backtrack
        }
      }
    }

};