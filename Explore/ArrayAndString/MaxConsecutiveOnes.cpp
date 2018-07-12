class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len = nums.size();
        if(len == 0){
            return 0;
        }
        int ind1 = 0;
        int ind2 = -1; //note that this one should be -1. It really does noe matter it is -1 or 0 if the longest 1s does noe start
                        // from the beginning
        int res = 0;
        for(;ind1 < len;++ind1){
            if(nums[ind1]!=1){
                ind2 = ind1;
            }
            res = max(res,ind1-ind2);
        }
        return res;
    }
};