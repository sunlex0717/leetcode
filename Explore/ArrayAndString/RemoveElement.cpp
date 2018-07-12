class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        if(len == 0){
            return 0;
        }
        int ind1 = 0;
        int ind2 = 0;
        for(;ind1 < len - 1; ++ind1){
            if(nums[ind1]!=val){
                nums[ind2] = nums[ind1];
                ++ind2;
            }
        }
        return ind2;
    }
};