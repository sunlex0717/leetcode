/*
we can use two-point tech
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len == 0){
            return 0;
        }
        if(len == 1){
            return 1;
        }
        int ind1 = 0; //faster pointer
        int ind2 = 0; //slower pointer

        for(; ind1 < len ; ++ind1){
            if(nums[ind1] != nums[ind2]){
                ind2++;
                nums[ind2] = nums[ind1];
            }
        }
        return ++ind2;
    }
};