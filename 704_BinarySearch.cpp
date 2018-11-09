class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if(size == 1){
          return nums[0]==target? 0 : -1;
        }
        int left = 0;
        int right = size -1;
        return binarysearch(target,left,right,nums);
    }

    int binarysearch(const int target, int left, int right, const vector<int>& nums){\
      if (left > right) return -1;
      int current = left + (right  - left)/2;
      if(nums[current] == target){
        return current;
      }else if(nums[current] < target){
        left = current + 1;
        return binarysearch(target,left,right,nums);
      }else{
        right = current - 1;
        return binarysearch(target,left,right,nums);
      }

    }
};