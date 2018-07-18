/*
we can consider two-pointer tech
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int write_ind = 0;
        int len = nums.size();
        if(len  >0){
            for(int i = 0; i<len;++i){
                if(nums[i]!=0){
                    nums[write_ind] = nums[i];
                    ++write_ind;
                }
            }
            for(;write_ind < len; ++write_ind){
                nums[write_ind] = 0;
            }
        }
        //for(int i=0;i)
        
    }
};