/*
#include <numeric>
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left=0;
        int right;
        int index=0;
        int length = nums.size();
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        for(int index=1;index<length;index++){ //no you should consider corner case
            left += nums[index-1];
            right = sum - left - nums[index];
            if(left==right){
                std::cout<<"found at index"<<index<<" left = "<<left <<", right = "<<right<<endl;
                return index;
            }
        }
        std::cout<<"not found"<<endl;
        return -1;
    }
};
*/

#include <numeric>
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.empty()){ //corner case 1,check empty
            return -1;
        }
        int left=0;
        int index=0;
        int length = nums.size();
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        // corner case 2, check 0
        int right = sum-left-nums[index];
        if(right==left){
            return 0;
        }
        for(int index=1;index<length;index++){
            left += nums[index-1];
            right = sum - left - nums[index];
            if(left==right){
                std::cout<<"found at index"<<index<<" left = "<<left <<", right = "<<right<<endl;
                return index;
            }
        }
        std::cout<<"not found"<<endl;
        return -1;
    }
};