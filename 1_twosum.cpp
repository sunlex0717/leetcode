/*Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/


/* 
  two pointer
*/
#include<iostream>
#include<vector>
#include<array>


//brute force
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {    
      int ind1=0;
      int ind2=1;
      int count = nums.size();
      for(ind1 = 0; ind1 < count-1; ind1++)
      {
        for(ind2 = ind1+1; ind2 < count; ind2++)
        {
          if(nums[ind1]+nums[ind2]==target){
            vector<int> ret(2);
            ret[0]=ind1;
            ret[1]=ind2;
            return ret;
          }
        } 
      }
    }
};