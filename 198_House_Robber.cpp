// prev2 prev1 num
//
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        int prev1 = 0;
        int prev2 = 0;

        for(int num:nums){
          int tmp = prev1;
          prev1 = std::max(prev2 + num,prev1);
          prev2 = tmp;
        }

        return prev1;
    }
};