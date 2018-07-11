class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
      int len =nums.size();

      std::sort (nums.begin(), nums.end());
      int res=0;
      for(int i = 0;i<len ;i=i+2){
        res+=nums[i];
      }
      return res;
    }
};